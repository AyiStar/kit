cmake_minimum_required(VERSION 3.20)

project(KitTen C CXX)

file(GLOB KITTEN_SRCS
    core/*.cpp
)
file(GLOB KITTEN_HEADERS
    core/*.h
)
add_library(kitten SHARED ${KITTEN_SRCS} ${KITTEN_HEADERS})

if (BUILD_TEST)
    add_subdirectory(test)
endif(BUILD_TEST)
