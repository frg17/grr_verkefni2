cmake_minimum_required(VERSION 3.13)
project (DatastructureComparison)

include_directories (
    "${CMAKE_SOURCE_DIR}/BinaryTree"
	"${CMAKE_SOURCE_DIR}/Treap"
)

add_subdirectory(BinaryTree)
add_subdirectory(Treap)

add_executable (DSCompare main.cpp)
target_link_libraries (DSCompare BinaryTree Treap)
