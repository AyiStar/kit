cmake_minimum_required(VERSION 3.20)

project(KitTen C CXX)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "The C++ standard whose features are requested to build this target.")
set(CMAKE_C_STANDARD   11 CACHE STRING "The C standard whose features are requested to build this target.")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PYTHON_MIN_VERSION 3.9)

# find pybind
execute_process(COMMAND python3 -m pybind11 --cmakedir
    RESULT_VARIABLE __pybind_exit_code
    OUTPUT_VARIABLE __pybind_path
    OUTPUT_STRIP_TRAILING_WHITESPACE)
find_package(pybind11 PATHS ${__pybind_path} REQUIRED)

include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${pybind11_LIBRARIES})

option(BUILD_TEST "Build C++ test binaries (need gtest and gbenchmark)" ON)
if (BUILD_TEST)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test)
endif(BUILD_TEST)

file(GLOB KITTEN_SRCS
    core/*.cpp
)
file(GLOB KITTEN_HEADERS
    core/*.h
)
include_directories(${PROJECT_SOURCE_DIR})
add_library(kitten ${KITTEN_SRCS} ${KITTEN_HEADERS})


