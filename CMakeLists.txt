cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

add_subdirectory(src)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
