cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(test_package CXX)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

find_package(cpp_project CONFIG REQUIRED)
enable_testing()
add_executable(test_package test_package.cpp)

target_compile_features(${PROJECT_NAME}
  PRIVATE cxx_std_20
)
if(cpp_project_FOUND)
  target_link_libraries(test_package PRIVATE cpp_project::cpp_project)
endif()