cmake_minimum_required(VERSION 3.11)
project(cpp-heap)

add_library(HeapElement HeapElement.cpp)
add_library(Heap Heap.cpp)
target_link_libraries(Heap HeapElement)