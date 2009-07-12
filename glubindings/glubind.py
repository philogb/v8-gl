import sys
import re

PATH_GL = 'glu.h'
FILE_GL = 'glubind.cpp'

def main():
    make_gl()

def make_gl():
    constants = []
    functions = []
    void_stars = []
    
    constant = re.compile(".+define[\s]+GLU_([^\s]+).*")
    function = re.compile("[\s]*extern[\s]+([^\s]+)[\s]+glu([A-Za-z0-9]+)[\s]*\((.*)\);")
    
    text_out = []
    
    fin = open(PATH_GL, 'r')
    for l in fin:
       try:
           mat = re.match(constant, l)
           if mat and not mat.group(1) in constants:
               name = mat.group(1)
               text_out.append(make_constant("GLU", name))
               constants.append(name)
               
               #print "GL_" + mat.group(1) + "\n"
               
           else:
               
               mat = re.match(function, l)
          
               if mat:
                   print l
                   prefix = "glu"
                   return_val = mat.group(1)
                   name = mat.group(2)
                   params = mat.group(3)
                   text_out.append(make_function(prefix, name, params, return_val))
                   functions.append(name)
                    
                   #print return_val + " " + name + " " + params
       except Exception, e:
            print e
            pass
    
    fin.close()

    fout = open(FILE_GL, 'w')
    fout.write("""

#include "glubind.h"
    
    """ + '\n'.join(text_out) + make_main_gl_function(constants, functions, void_stars))
    
    fout.close()

def make_main_gl_function(constants, functions, void_stars):
    text_out_begin = """

Handle<ObjectTemplate> createGlu(void) {
      HandleScope handle_scope;

      Handle<ObjectTemplate> Glu = ObjectTemplate::New();
      Glu->SetInternalFieldCount(1);

"""

    text_out_end = """

      // Again, return the result through the current handle scope.
      return handle_scope.Close(Glu);
}    
"""
    fnt = [bind_font(name) for name in void_stars]    
    cts = [bind_accessor("Glu", name) for name in constants]
    fts = [bind_function("Glu", name) for name in functions]
    
    return text_out_begin + '\n'.join(fnt) + '\n'.join(cts) + '\n'.join(fts) + text_out_end
    

def make_constant(prefix, name):
    return_val = "return Uint32::New(GLU_"+ name +");"
    text_out = """

Handle<Value> GetGLU_%%(Local<String> property,
                      const AccessorInfo &info) {
    ##
}

"""
    return multiple_replace({
        '%%': name,
        '##': return_val
    }, text_out)



def make_function(prefix, name, params, return_val):
    text_out = """

Handle<Value> GLU<name>Callback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < <len_params>) return v8::Undefined();
  //define handle scope
  HandleScope scope;
  //get arguments
<args>
  //make call
  <call>
  return v8::Undefined();
}

"""
    count, params_list = get_param_list(params)
    return multiple_replace({
        '<name>': name,
        '<len_params>': str(count),
        '<args>': make_args(params_list, count),
        '<call>': make_call(prefix + name, params_list, count)      
    }, text_out)


def get_param_list(params):
    params_list = []
    params_aux = params.split(',')
    passed = False
    for par in params_aux:
        if passed and params_list[-1].count('(') != params_list[-1].count(')'):
            params_list[-1] += ',' + par
        else:
            params_list.append(par)
        passed = True
    
    aux = len(params_list)
    if aux == 1 and params_list[0].find('callback') == -1 and len(params_list[0].strip().split(' ')) == 1: 
        nb = 0
    else:
        nb = aux
    return nb, params_list
    

def make_args(params_list, count):
    ans = []
    for i in range(count):
        el = params_list[i]
        type = get_type(el)
        
        #is function
        if type.find('(*') != -1:
            ans.append("  Handle<Function> value" + str(i) + " = Handle<Function>::Cast(args[" + str(i) + "]);\n  void* arg" + str(i) + " = *value" + str(i) + ";\n")
            print "function " + type
        #is string
        elif type.find('char*') != -1:
            ans.append("  String::Utf8Value value"+ str(i) +"(args["+ str(i) +"]);\n  char* arg" + str(i) + " = *value"+ str(i) +";\n")
            print "string " + type
        #is void*
        elif type.find('void*') != -1 or type.find('**') != -1:
            raise Exception("unhandled type " + type)
        #is array
        elif type.find('*') != -1 or el.find('[') != -1:
            ans.append(make_array_expression(type, i))
        #is unsigned integer
        elif type.find('unsigned') != -1 or type.find('ubyte') != -1 or type.find('ushort') != -1 or type.find('uint') != -1 or type.find('bitfield') != -1 or type.find('boolean') != -1:
            ans.append("  unsigned int arg" + str(i) + " = args["+ str(i) +"]->Uint32Value();\n")
            print "unsigned " + type
        #is integer
        elif type.find('int') != -1 or type.find('enum') != -1 or type.find('sizei') != -1 or type.find('short') != -1 or type.find('byte') != -1:
            ans.append("  int arg" + str(i) + " = args["+ str(i) +"]->IntegerValue();\n")
            print "integer " + type
        #is double, float
        elif type.find('double') != -1 or type.find('float') != -1 or type.find('clampf') != -1 or type.find('clampd') != -1:
            ans.append("  double arg" + str(i) + " = args["+ str(i) +"]->NumberValue();\n")
            print "double " + type
        else:
            raise Exception("unhandled type " + type)
    
    return ''.join(ans)




def make_call(name, params_list, nb):
    return name + "(" + ", ".join([get_type(params_list[i]) + "arg" + str(i) for i in range(nb)]) + ");"
            
def bind_accessor(prefix, name):
    return "     " + prefix + "->SetAccessor(String::NewSymbol(\"" + name + "\"), GetGLU_" + name + ");\n"

def bind_function(prefix, name):
    return "     " + prefix + "->Set(String::NewSymbol(\"" + name + "\"), FunctionTemplate::New(GLU" + name + "Callback));\n"

def bind_font(name):
    return "     font_[\""+ name +"\"] = GLUT_" + name + ";\n"

def get_accessor(type):
    #is unsigned integer
    if type.find('unsigned') != -1 or type.find('ubyte') != -1 or type.find('ushort') != -1 or type.find('uint') != -1 or type.find('bitfield') != -1 or type.find('boolean') != -1:
        return "Uint32Value()"
    #is integer
    elif type.find('int') != -1 or type.find('enum') != -1 or type.find('sizei') != -1 or type.find('short') != -1 or type.find('byte') != -1:
        return "IntegerValue()"
    #is double, float
    elif type.find('double') != -1 or type.find('float') != -1 or type.find('clampf') != -1 or type.find('clampd') != -1:
        return "NumberValue()"
    else:
        raise Exception("unhandled type " + type)
    

def make_array_expression(type, i):
    type = multiple_replace({'(':'', ')':'', 'const':''}, type)
    acc = get_accessor(type)
    clean_type = type.replace('*', '', 1)
    
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
        '##4': acc
    }, text_out)

def get_type(t):
    if t.find('callback') != -1: 
        return '( ' + t.replace('callback', '') + ') '
    return '( ' + ' '.join(t.strip().split(' ')[:-1]) + ('*' * (t.count('*') + t.count('['))) + ' ) '

def multiple_replace(dict, text): 
  """ Replace in 'text' all occurences of any key in the given
  dictionary by its corresponding value.  Returns the new tring.""" 

  # Create a regular expression  from the dictionary keys
  regex = re.compile("(%s)" % "|".join(map(re.escape, dict.keys())))

  # For each match, look-up corresponding value in dictionary
  return regex.sub(lambda mo: dict[mo.string[mo.start():mo.end()]], text) 

main()  