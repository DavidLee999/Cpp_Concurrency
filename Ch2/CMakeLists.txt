cmake_minimum_required( VERSION 2.8 )

project( Ch2 )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11" )

add_executable( AccessLocalVariable AccessLocalVariable.cpp )
add_executable( WaitForAnyExitPath WaitForAnyExitPath.cpp )
add_executable( UsingRAII UsingRAII.cpp )