import re
import json

PATH_GL = 'gl2.h'
FILE_JSON = 'glesbind.json'

#constant and function patterns
constant_pattern = """
    .+define[\s]+       #define C/C++ keyword
    
    (?P<name>GL_[^\s]+) #Constant name
    
    [\s]+
    
    (?P<value>[^\s]+)   #Constant value
    
    [\s]*
"""

function_pattern = """
    [\s]*GL_APICALL[\s]+          #GLAPICALL typedef
    
    (?P<return_type>[^\s]+)       #Function return type
    
    [\s]+GL_APIENTRY[\s]+         #GLAPIENTRY typedef
    
    (?P<name>gl[A-Za-z0-9]+)      #Function name
    
    [\s]*
    
    \((?P<parameters>.*)\);       #Function parameters
"""
#precompile regexps
constant = re.compile(constant_pattern, re.VERBOSE)
function = re.compile(function_pattern, re.VERBOSE)

def main():
    json_out = []
    constants = []
    #open input file
    with open(PATH_GL, 'r') as fin:
        #line accumulator. Function definitions 
        #can be spread into multiple lines
        l = ''
        #get function/constant prototype
        for cont in fin:
           l += cont.replace('\n', '')
           if not balanced(l):
              continue
           #is constant declaration
           mat = re.match(constant, l)
           if mat and not mat.group('name') in constants:
               constants.append(mat.group('name'))
               json_out.append(make_constant(mat))
           else:
               #is function declaration
               mat = re.match(function, l)
               if mat: 
                   json_out.append(make_function(mat))
               
           l = '' #empty line accumulator

    #dump as JSON
    with open(FILE_JSON, 'w') as fout:
        fout.write(json.dumps(json_out, indent=4))

def make_constant(match):
    """Returns a Constant JSON Object"""
    
    return {
        'type': 'c', #c for constant, f for function
        'name': match.group('name'),
        'value': match.group('value') #is this necessary?        
    }

def make_function(match):
    """Returns a Function JSON Object"""
    
    return {
        'type': 'f', #f for function
        'name': match.group('name'),
        'return_type': match.group('return_type'),
        'parameters': get_parameters(match.group('parameters'))
    }

def get_parameters(params):
    """Returns an ordered list of parameter types"""
    
    params_list = []
    params_aux = params.split(',')
    passed = False
    for par in params_aux:
        if passed and not balanced(params_list[-1]):
            params_list[-1] += ',' + par
        else:
            #magic
            param = ' '.join(par.strip().replace('*', '').split(' ')[:-1]) + ('*' * (par.count('*') + par.count('[')))
            if param.strip() != '': params_list.append(param)
        passed = True
    
    return params_list


def balanced(l):
    return l.count('(') == l.count(')')

if __name__ == '__main__': main()