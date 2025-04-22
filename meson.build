project('data_struct_sort', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3'])

src_files = [
  'src/data_struct_sort.cpp',
  'src/utils/console.cpp',
  'src/sorts/bubblesort.cpp',
  'src/sorts/selectionsort.cpp',
  'src/sorts/quicksort.cpp'
]

exe = executable('data_struct_sort', src_files,
  install : true, include_directories: [include_directories('src')])

test('basic', exe)
