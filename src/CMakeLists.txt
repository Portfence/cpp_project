cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project CXX)

add_library(${PROJECT_NAME} SHARED
    lib_source.h
    lib_source.cpp
    another_lib_source.h
    another_lib_source.cpp
)

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_20
)

target_include_directories(${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PUBLIC $<INSTALL_INTERFACE:include>
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
