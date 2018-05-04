cmake_minimum_required( VERSION 2.8 )

project( Ch4 )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11")

add_executable( WaitingUsingConditionVar WaitingUsingConditionVar.cpp )
add_executable( ThreadSafeQueueStructure ThreadSafeQueueStructure.cpp )
add_executable( ThreadSafeQueue ThreadSafeQueue.cpp )
add_executable( UsingFuture UsingFuture.cpp )
add_executable( AccumulateUsingPromise AccumulateUsingPromise.cpp )
