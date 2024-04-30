cmake_minimum_required(VERSION 3.2...3.27.5)
set (CMAKE_CXX_STANDARD 11)
project(kmms_prog_2023)

enable_testing()
add_subdirectory(lib/googletest)

set(SCL_LIB "scl_lib")
add_subdirectory(scl)

add_subdirectory(bubble_sort)
add_subdirectory(bubble_sort_mf)
add_subdirectory(refactoring_and_print)
add_subdirectory(base_theory_p1)
add_subdirectory(base_theory_tasks_p1)
add_subdirectory(obuchaika)
add_subdirectory(unit_test_example)
add_subdirectory(inheritance_examples)
add_subdirectory(recursion)
add_subdirectory(obuchaika_v2)

set(CMAKE_SUPPRESS_REGENERATION true)
