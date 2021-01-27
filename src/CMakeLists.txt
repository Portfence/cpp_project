# ##### The 'src' directory is a standalone project #####
cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(cpp_project CXX)

# For finding dependencies with Conan Package Manager
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

find_package(fmt CONFIG REQUIRED)
find_package(plog CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED
    lib_source_a.cpp
    lib_source_b.cpp
)

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_20
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE fmt::fmt
    PUBLIC plog::plog
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

install(TARGETS ${PROJECT_NAME} 
        EXPORT ${PROJECT_NAME}-export
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(EXPORT ${PROJECT_NAME}-export
        DESTINATION lib/cmake/${PROJECT_NAME}
        FILE ${PROJECT_NAME}-targets.cmake
        NAMESPACE ${PROJECT_NAME}::)

install(DIRECTORY include/${PROJECT_NAME}
        DESTINATION include)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(${PROJECT_NAME}-config-version.cmake
        COMPATIBILITY SameMajorVersion VERSION SameMajorVersion)

install(FILES cmake/${PROJECT_NAME}-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION lib/cmake/${PROJECT_NAME})
