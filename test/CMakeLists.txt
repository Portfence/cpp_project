cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project_test CXX)

include(CTest)
enable_testing()

find_package(doctest CONFIG REQUIRED)
if (NOT TARGET cpp_project::cpp_project)
    find_package(cpp_project CONFIG REQUIRED)
endif()

add_executable(test_${PROJECT_NAME}
    test_main.cpp
    test_source.cpp
    another_test_source.cpp
)

target_link_libraries(test_${PROJECT_NAME}
    PRIVATE
        cpp_project::cpp_project
        doctest::doctest
        trompeloeil::trompeloeil
)

add_test(NAME cpp_project.unit_tests COMMAND ${PROJECT_NAME})
