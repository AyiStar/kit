cmake_minimum_required(VERSION 3.20)

project(Kit C CXX)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "The C++ standard whose features are requested to build this target.")
set(CMAKE_C_STANDARD   11 CACHE STRING "The C standard whose features are requested to build this target.")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PYTHON_MIN_VERSION 3.9)

include(cmake/dependencies.cmake)

option(BUILD_TEST "Build C++ test binaries (need gtest and gbenchmark)" ON)
if (BUILD_TEST)
enable_testing()
endif(BUILD_TEST)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(kitten)
