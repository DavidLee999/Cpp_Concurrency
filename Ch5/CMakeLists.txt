cmake_minimum_required( VERSION 2.8 )

project( Ch4 )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11")

add_executable( UnspecifiedOrder UnspecifiedOrder.cpp )
add_executable( SequentialConsistency SequentialConsistency.cpp )
add_executable( RelaxedOperations RelaxedOperations.cpp )
add_executable( RelaxedOperations2 RelaxedOperations2.cpp )
