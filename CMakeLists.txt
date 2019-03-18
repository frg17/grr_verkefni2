cmake_minimum_required(VERSION 3.13)
project (DatastructureComparison)

include_directories (
    "${CMAKE_SOURCE_DIR}/BinaryTree"
)

add_subdirectory(BinaryTree)

add_executable (DSCompare main.cpp)
target_link_libraries (DSCompare BinaryTree)
