import re
import json

function_name_pattern = re.compile("error:[\s]*'(?P<function_name>[^\s]+)'[\s]*was not declared in this scope")

def main():
    text_out = []
    
    with open('glesbind.json', 'r') as bindings:
        objs = json.loads(bindings.read())

    with open('errors.txt', 'r') as errors:
        for error_line in errors:
            match = re.search(function_name_pattern, error_line)
            if match:
                text_out.append(define(get_obj(objs, match.group('function_name'))))
                
    with open('whatsmissing.txt', 'w') as fout:
        fout.write('\n'.join(text_out))

def define(obj):
    if obj['type'] == 'c': return '#define ' + obj['name'] + ' 1'
    
    return obj['return_type'] + ' ' + obj['name'] + "(" + ", ".join([param + ' ' + "arg" + str(i) \
                    for i, param in enumerate(obj['parameters'])]) + ") {}"

def get_obj(objs, name):
    print name
    for obj in objs:
        if obj['name'] == name: return obj
        
if __name__ == '__main__': main()