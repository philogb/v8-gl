from __future__ import with_statement

import json
import re

#input output files
IN_FILE = 'glbind.json'
OUT_FILE = 'glbind.cpp'

#exclude functions by name
EXCLUDE = re.compile('ATI|MESA')

def main():
    """Generates Gl bindings"""
    
    with open(IN_FILE, 'r') as f:
        text_out = []
        data = f.read()
        try:
            # Try the python 2.6 json module first.
            json_in = json.loads(data)
        except AttributeError:
            # Fall back to json-py.
            reader = json.JsonReader()
            json_in = reader.read(data)
        constants, functions = [], []
        
        for obj in json_in:
            if not re.search(EXCLUDE, obj['name']):
                try:
                    if obj['type'] == 'c':
                        constants.append(obj['name'])
                    else:
                        text_out.append(generate_function(obj))
                        functions.append(obj['name'])
                except Exception, e: #probably an unhandled type
                    print e
                    pass

    with open(OUT_FILE, 'w') as fout:
        fout.write("""
#include "glbind.h"

#if defined(V8_GL_USE_GLEW)
#include "GL/glew.h"
#elif defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif

using namespace v8;

Persistent<Object> GlFactory::self_;
""" + '\n'.join(text_out) + '\n' + generate_main_function(constants, functions))


def generate_main_function(constants, functions):
    """Generates the main createGl function definition"""
    
    text_out_begin = """

Handle<ObjectTemplate> GlFactory::createGl(void) {
      HandleScope handle_scope;

      Handle<ObjectTemplate> Gl = ObjectTemplate::New();
      
      Gl->SetInternalFieldCount(1);

"""

    text_out_end = """

      // Again, return the result through the current handle scope.
      return handle_scope.Close(Gl);
}    
"""
    bind_accessor = lambda n: "     Gl->Set(String::NewSymbol(\"" + '_'.join(n.split('_')[1:]) \
        + "\"), Uint32::New(" + n + "), ReadOnly);\n"
    bind_function = lambda n: "     Gl->Set(String::NewSymbol(\"" + n[2:] + \
        "\"), FunctionTemplate::New(GL" + n + "Callback));\n"
    
    cts = [bind_accessor(name) for name in constants]
    fts = [bind_function(name) for name in functions]
    
    return text_out_begin + '\n'.join(cts) + '\n' + '\n'.join(fts) + text_out_end

def generate_function(obj):
    """Generates code for declaring a Function"""

    text_out = """

Handle<<ret>> GL<name>Callback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < <len_params>) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
<args>
  //make call
  <call>
}

"""
    return multiple_replace({
        '<name>': obj['name'],
        '<len_params>': str(len(obj['parameters'])),
        '<args>': generate_arguments(obj['parameters']),
        '<call>': generate_call(obj),
        '<ret>': 'Value'      
    }, text_out)


#map some OpenGL types to V8 types
unsigned = re.compile('unsigned|ubyte|ushort|uint|bitfield|boolean')
integer = re.compile('int|enum|sizei|short|byte')
double = re.compile('double|float|clampf|clampd')

def generate_arguments(params):
    """generates the formal parameter definition"""
    
    text_out = []
    #assignment template
    assign = lambda type, method, i: '  ' + type + ' arg' + i + \
        ' = args[' + i + ']->' + method + '();\n'
    
    for i, type in enumerate(params):
        si = str(i)
        #TODO Find a way to map void* to a V8 type
        if type.find('void*') != -1:
            raise Exception("unhandled type " + type)
        #is array
        elif type.find('*') != -1 or type.find('[') != -1:
            text_out.append(generate_array_expression(type, i))
        #is unsigned integer
        elif re.search(unsigned, type):
            text_out.append(assign('unsigned int', 'Uint32Value', si))
        #is integer
        elif re.search(integer, type):
            text_out.append(assign('int', 'IntegerValue', si))
        #is double, float
        elif re.search(double, type):
            text_out.append(assign('double', 'NumberValue', si))
        else:
            raise Exception("unhandled type " + type)

    return ''.join(text_out)

def generate_array_expression(type, i):
    """generates an Array assignment expression"""
    type = multiple_replace({ '(':'', ')':'', 'const':'' }, type)
    acc = get_accessor(type)
    clean_type = type.replace('*', '')
    
    text_out = """
    
  Handle<Array> arrHandle##1 = Handle<Array>::Cast(args[##1]);
  ##2 arg##1 = new ##3[arrHandle##1->Length()];
  for (unsigned j = 0; j < arrHandle##1->Length(); j++) {
      Handle<Value> arg(arrHandle##1->Get(Integer::New(j)));
      ##3 aux = (##3)arg->##4;
      arg##1[j] = aux; 
  }
    
    """
    return multiple_replace({
        '##1': str(i),
        '##2': type,
        '##3': clean_type,
        '##4': acc + 'Value()'
    }, text_out)

def get_accessor(type):
    """Returns the V8 type accesor method to be called"""
    
    if re.search(unsigned, type): return 'Uint32'
    if re.search(integer, type): return 'Integer'
    if re.search(double, type): return 'Number'
    
    return None

def generate_call(obj):
    """generates the native function call syntax"""

    acc = get_accessor(obj['return_type'])
    function_call = obj['name'] + "(" + ", ".join(['(' + param + ') ' + "arg" + str(i) \
                        for i, param in enumerate(obj['parameters'])]) + ")"
    
    #dot-this-dot-that feature
    if acc is None: 
        return function_call + ';\n  Handle<Object> res(GlFactory::self_);\n  return res;'
    else:
        return 'return ' + acc + '::New(' + function_call + ');'
    

def multiple_replace(dict, text): 
  """ Replace in 'text' all occurences of any key in the given
  dictionary by its corresponding value.  Returns the new string.""" 

  # Create a regular expression  from the dictionary keys
  regex = re.compile("(%s)" % "|".join(map(re.escape, dict.keys())))

  # For each match, look-up corresponding value in dictionary
  return regex.sub(lambda mo: dict[mo.string[mo.start():mo.end()]], text) 

if __name__ == '__main__': main()
