cmake_minimum_required(VERSION 3.8.2)
get_filename_component(dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project($dir)

file(GLOB files *.cpp *.hpp)
add_executable("${dir}.out" ${files})
