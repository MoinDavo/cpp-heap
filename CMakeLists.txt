cmake_minimum_required(VERSION 3.11)

project(cpp-heap)

add_subdirectory(src)


add_executable(main src/main.cpp)
target_link_libraries(main Heap HeapElement)