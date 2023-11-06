cmake_minimum_required(VERSION 3.11)
project(cpp-heap)

add_subdirectory(src)

add_executable(main main.cpp src/colours.h)
target_link_libraries(main Heap HeapElement)