# ---[ pybind11
message(STATUS "Using third_party/pybind11/")
set(pybind11_DIR ${CMAKE_CURRENT_LIST_DIR}/../third_party/pybind11)
set(pybind11_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../third_party/pybind11/include)
install(DIRECTORY ${pybind11_INCLUDE_DIRS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        FILES_MATCHING PATTERN "*.h")
message(STATUS "pybind11 include dirs: " "${pybind11_INCLUDE_DIRS}")
add_library(pybind::pybind11 INTERFACE IMPORTED)
target_include_directories(pybind::pybind11 SYSTEM INTERFACE ${pybind11_INCLUDE_DIRS})
target_link_libraries(pybind::pybind11 INTERFACE python::python)

# ---[ googletest
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../third_party/googletest)
include_directories(BEFORE SYSTEM ${CMAKE_CURRENT_LIST_DIR}/../third_party/googletest/googletest/include)
include_directories(BEFORE SYSTEM ${CMAKE_CURRENT_LIST_DIR}/../third_party/googletest/googlemock/include)
