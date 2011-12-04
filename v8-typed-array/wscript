from os import mkdir
from os import symlink
from os import remove
from os.path import lexists

srcdir = '.'
blddir = 'build'
VERSION = '0.0.2'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')

def build(bld):
  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  obj.target = 'typed-array'
  obj.source = 'typed-array.cc'
