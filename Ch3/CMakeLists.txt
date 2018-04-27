cmake_minimum_required( VERSION 2.8 )

project( Ch3 )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11" )

add_executable( UsingMutex UsingMutex.cpp )
add_executable( UsingLockGuard UsingLockGuard.cpp )
add_executable( ReferenceOut ReferenceOut.cpp )
