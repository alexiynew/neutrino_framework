#!/usr/bin/python
import os
import sys
import re

if len(sys.argv) < 2:
    print 'Need to add some subfolders.'
    sys.exit()

extentions = ['.cpp', '.h']

task_mark = u'\u2610'.encode('utf-8')
block_separator = u'--- \u2704 -----------------------'.encode('utf-8')

re_todo = ['\/?[\/|*]?\s*TODO\s*:[ \\t]*(.[^\\n]*)?$',
           '\/?[\/|*]?\s*TODO\s[ \\t]*(.[^\\n:]*)?$']

result_file = 'filestodo.todo'

def find_regexes(regexes, line):
    for regex in regexes:
        m = re.match(regex, line)
        if m:
            text = m.groups(' ')[0]
            return text

def get_task_list(file, regexes):
    todo_list = []

    with open(file) as f:
        content = f.readlines()
        index = 0;
        for line in content:
            index += 1
            text = find_regexes(re_todo, line)
            if text:
                todo_list.append({'line': index,'text': text})

    return todo_list


path = os.path.dirname(os.path.realpath(__file__))
paths = map(lambda f: os.path.join(path, f), sys.argv[1:])

all_files = []

for folder in paths:
    for root, dirs, files in os.walk(folder):
        for file in files:
            filename, file_extension = os.path.splitext(file)
            if (file_extension in extentions):
                all_files.append(os.path.join(root, file))

with open(result_file, 'w') as result_file:
    result_file.write('TODO:\n')

    for file in all_files:
        todo_list = get_task_list(file, re_todo)
        if len(todo_list) > 0:
            result_file.write('  {}:\n'.format(file.split('/')[-1]))

            for task in todo_list:
                result_file.write('    {} {}\n'.format(task_mark, task['text']))
                result_file.write('      [[{}]] ":{}"\n\n'.format(file, task['line']))

            result_file.write('\n')
