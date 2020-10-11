cmake_minimum_required(VERSION  3.1.3)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS -g)

add_executable(getopt api/getopt.cpp)
add_executable(SelectionSort algorithm4/2/Sort.cpp)

add_executable(SequentialSearchST algorithm4/3/SequentialSearchST.h algorithm4/3/SequentialSearchST_Main.cpp)
add_executable(BinarySearchST algorithm4/3/BinarySearchST.h algorithm4/3/BinarySearchST_Main.cpp)