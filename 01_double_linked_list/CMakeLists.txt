cmake_minimum_required(VERSION 3.9)

file(GLOB files *.cpp *.hpp)
get_filename_component(dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable("${dir}.out" ${files})
