cmake_minimum_required(VERSION 4.0) 
project(AIcheatSDK) 
set( CMAKE_CXX_STANDARD 23 ) 
 
file(GLOB InternalSource source/source.cpp source/*.c) 
file(GLOB InternalHeaders source/*.hpp source/*.h) 
 
file(GLOB ExternalSource external/source/*/*.cpp external/source/*/*.c) 
file(GLOB ExternalHeaders external/include/*/*.hpp external/include/*/*.h) 
 
file(GLOB Sources ${InternalSource} ${ExternalSource} ) 
file(GLOB Headers ${InternalHeaders} ${ExternalHeaders}) 
 
file(GLOB ExternalLibbarys external/lib/*.a external/lib/*.dll external/lib/*.lib) 
 
add_executable(AIcheatSDK ${Sources} ${Headers}) 
 
target_include_directories(AIcheatSDK PUBLIC include external/include) 
target_link_libraries(AIcheatSDK -l:libstdc++exp.a ${ExternalLibbarys})
