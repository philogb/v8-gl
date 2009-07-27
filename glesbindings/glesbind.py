from __future__ import with_statement

import json
import re
from os import path

#input output files
IN_FILE = 'glesbind.json'
OUT_FILE = 'glesbind.cpp'
CUSTOM_CODE_FILE = 'glescustom.cpp'

#functions found in custom code file
#there won't be an automatic code generation
#for these functions. However there will be a corresponding
#accessor in the Gles object, if found.
template = """
    glGenBuffers               #custom code functions
    |glGenRenderbuffers
    |glGenFramebuffers
    |glGenTextures
    |glGetProgramiv
    |glGetShaderiv
    |glShaderSource
    |glVertexAttribPointer
    |glDrawElements
    |glBufferData                
    |glBufferSubData             
    |glReadPixels
    |glGetActiveAttrib
    |glGetActiveUniform
    |glGetBufferParameteriv
    |glGetProgramInfoLog
    |glGetShaderInfoLog
    |glTexImage2D              
    |glTexSubImage2D
    |glGetShaderSource
    |glGetAttachedShaders
           
"""

#excluded functions
#there won't be an accessor for these functions
#in the Gles object.
exclude = """
    _ATI
    |ATI$
    |MESA     
    |IMPLEMENTATION
    |GL_INVALID_FRAMEBUFFER_OPERATION
    
    |glGetVertexAttribPointerv #functions to be considered for custom implementation
                               #might be missing some
                               
    |glCompressedTexImage2D    
    |glCompressedTexSubImage2D 
    |glShaderBinary            
        
    |glReleaseShaderCompiler    #commented functions
    |glGetShaderPrecisionFormat
    
    
    
    |glGetBooleaniv             #are replaced by glGetParameter
    |glGetIntegeriv
    |glGetFloativ
    |glGetDoubleiv
    
    |glGetTexParameterfv        #are replaced by glGetTexParameter
    |glGetTexParameteriv
    
    |glGetUniformfv                 #should be implemented but I find quite difficult
                                    #to guess the type of a queried uniform, so I'm not
                                    #sure how to allocate the resulting data.
                                
    |glGetVertexAttribiv            #are replaced by glGetVertexAttrib
    |glGetVertexAttribfv
    
    |glGetRenderbufferParameteriv    #is replaced by glGetRenderbufferParameter
    
"""

accessor_extras = ['glGetParameter', 
                   'glGetTexParameter', 
                   'glGetVertexAttrib', 
                   'glGetRenderbufferParameter',
                   'glShaderSourceFile']

EXCLUDE = re.compile(exclude, re.VERBOSE)
TEMPLATE = re.compile(template, re.VERBOSE)

def main():
    """Generates GLES bindings"""
    
    #read custom code
    with open(CUSTOM_CODE_FILE, 'r') as f:
        custom_code = f.read()
        
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
                      if not re.search(TEMPLATE, obj['name']):
                        text_out.append(generate_function(obj))
                      functions.append(obj['name'])
                except Exception, e: #probably an unhandled type
                    print e
                    pass
            else:
                print obj['name']

        functions.extend(accessor_extras)

    with open(OUT_FILE, 'w') as fout:
        fout.write("""
#include "glesbind.h"

#if defined(V8_GL_USE_GLEW)
#include "GL/glew.h"
#include "glew_desktop_shim.h"
#elif defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#include "gles_desktop_shim.h"
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
// If we're running on desktop OpenGL, some ES 2.0 constants don't exist, or
// are under a name with EXT in them, etc.
#include "gles_desktop_shim.h"
#endif

#include <fstream>
#include <string>
using namespace v8;


Persistent<Object> GlesFactory::self_;
Persistent<Context> GlesFactory::gles_persistent_context;
char* GlesFactory::root_path;
""" + custom_code  + '\n'.join(text_out) + '\n' + generate_main_function(constants, functions))


def generate_main_function(constants, functions):
    """Generates the main createGles function definition"""
    
    text_out_begin = """

Handle<ObjectTemplate> GlesFactory::createGles(void) {
      HandleScope handle_scope;

      Handle<ObjectTemplate> Gles = ObjectTemplate::New();
      
      Gles->SetInternalFieldCount(1);

"""

    text_out_end = """

      // Again, return the result through the current handle scope.
      return handle_scope.Close(Gles);
}    
"""
    bind_accessor = lambda n: "     Gles->Set(String::NewSymbol(\"" + '_'.join(n.split('_')[1:]) \
        + "\"), Uint32::New(" + n + "), ReadOnly);\n"
    bind_function = lambda n: "     Gles->Set(String::NewSymbol(\"" + n[2:] + \
        "\"), FunctionTemplate::New(GLES" + n + "Callback));\n"
    
    cts = [bind_accessor(name) for name in constants]
    fts = [bind_function(name) for name in functions]
    
    return text_out_begin + '\n'.join(cts) + '\n' + '\n'.join(fts) + text_out_end

def generate_function(obj):
    """Generates code for declaring a Function"""

    text_out = """

Handle<<ret>> GLES<name>Callback(const Arguments& args) {
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
unsigned = re.compile('unsigned|ubyte|ushort|uint|bitfield|boolean|enum')
integer = re.compile('int|sizei|short|byte')
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
        #is a name (char*)
        if type.endswith('char*'):
            text_out.append("  String::Utf8Value value"+ si +"(args["+ si +"]);\n  " + \
                            "char* arg" + si + " = *value"+ si +";\n")
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
        return function_call + ';\n  Handle<Object> res(GlesFactory::self_);\n  return res;'
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
