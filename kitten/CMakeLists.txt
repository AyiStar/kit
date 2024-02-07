cmake_minimum_required(VERSION 3.20)

project(KitTen C CXX)

file(GLOB KITTEN_SRCS
    core/tensor/*.cpp
    core/graph/*.cpp
    core/alloc/*.cpp
    core/meta/*.cpp
    util/*.cpp
)
file(GLOB KITTEN_HEADERS
    core/tensor/*.h
    core/graph/*.h
    core/alloc/*.h
    core/meta/*.h
    util/*.h
    macro/*.h
)
add_library(kitten SHARED ${KITTEN_SRCS} ${KITTEN_HEADERS})


if (BUILD_TEST)
    add_subdirectory(test)
endif(BUILD_TEST)
