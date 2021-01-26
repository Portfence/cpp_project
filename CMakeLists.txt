cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
