cmake_minimum_required(VERSION 3.30.4) 
project(AIcheatSDK) 
set( CMAKE_CXX_STANDARD 23 ) 
 
file(GLOB InternalSource source/source.cpp source/*.c) 
file(GLOB InternalHeaders source/*.hpp source/*.h) 
 
file(GLOB ExternalSource external/source/*/*.cpp external/source/*/*.c) 
file(GLOB ExternalHeaders external/include/*/*.hpp external/include/*/*.h) 
 
file(GLOB Sources ${InternalSource} ${ExternalSource} ) 
file(GLOB Headers ${InternalHeaders} ${ExternalHeaders}) 
 
file(GLOB ExternalLibbarysLinux external/lib/linux/*.a external/lib/linux/*.so) 
file(GLOB ExternalLibbarysWindows external/lib/windows/*.a external/lib/windows/*.dll external/lib/windows/*.lib) 


if(WIN32)
# WINDOWS
    add_executable(AIcheatSDK ${Sources} ${Headers}) 
 
    target_include_directories(AIcheatSDK PUBLIC include external/include) 
    target_link_libraries(AIcheatSDK -l:libstdc++exp.a ws2_32 ${ExternalLibbarysWindows})
else()
# LINUX
    add_executable(AIcheatSDK ${Sources} ${Headers}) 
 
    target_include_directories(AIcheatSDK PUBLIC include external/include) 
    target_link_libraries(AIcheatSDK -l:libstdc++exp.a ws2_32 ${ExternalLibbarysLinux})
endif()
