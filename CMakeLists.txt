cmake_minimum_required(VERSION 3.25)

project(spbu-tree-set C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra")
message(STATUS "Compiling with flags: ${CMAKE_C_FLAGS}")

add_executable(main main.c)
add_library(binary_search_tree binary_search_tree.c)
add_library(stack stack.c)

target_link_libraries(binary_search_tree PRIVATE stack)
target_link_libraries(main PRIVATE binary_search_tree)
