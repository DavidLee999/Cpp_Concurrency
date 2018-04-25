cmake_minimum_required( VERSION 2.8 )

project( Ch2 )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11" )

add_executable( test test.cpp )
add_executable( AccessLocalVariable AccessLocalVariable.cpp )
add_executable( WaitForAnyExitPath WaitForAnyExitPath.cpp )
add_executable( UsingRAII UsingRAII.cpp )
add_executable( DetachThread DetachThread.cpp )
add_executable( ReturnThread ReturnThread.cpp )
add_executable( ScopedThread ScopedThread.cpp )
add_executable( GroupOfThreads GroupOfThreads.cpp )
add_executable( ParallelAccumulate ParallelAccumulate.cpp )