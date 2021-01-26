# ##### The 'src' directory is a standalone project #####
cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project CXX)

# For finding dependencies with Conan Package Manager
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

add_library(${PROJECT_NAME} SHARED
    lib_source_a.cpp
    lib_source_b.cpp
)

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_20
)

# Contributers use #include "lib_source_XXX.h"
target_include_directories(${PROJECT_NAME} 
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
    PRIVATE $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

# Clients use #include <cpp_project/lib_source_XXX.h>
target_include_directories(${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PUBLIC $<INSTALL_INTERFACE:include>
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
