cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project CXX)

include(CTest)
enable_testing()

add_subdirectory(src)

if(BUILD_TESTING)
    find_package(Catch2 CONFIG REQUIRED)
    if(Catch2_FOUND)
        message(STATUS "Found Catch2 version: ${Catch2_VERSION}")
    endif()
    
    find_package(trompeloeil CONFIG REQUIRED)
    if(trompeloeil_FOUND)
        message(STATUS "Found Trompeloeil version: ${trompeloeil_VERSION}")
    endif()
    
    add_subdirectory(test)
endif()
