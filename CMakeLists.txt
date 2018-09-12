cmake_minimum_required(VERSION 3.9)

representationsp)

set(CMAKE_CXX_STANDARD 14)

function(add_complete_directory dirname)
    file(GLOB files "${dirname}/*.hpp" "${dirname}/*.cpp")
    add_executable("${dirname}.out" ${files})
    set_target_properties("${dirname}.out"  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${dirname}")
endfunction(add_complete_directory)

add_complete_directory(01_double_linked_list)
add_complete_directory(02_task01)
add_complete_directory(03_quick_sort)
add_complete_directory(04_merge_sort)
add_complete_directory(05_graph_matrix)