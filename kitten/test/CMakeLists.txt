file(GLOB_RECURSE KITTEN_ALL_TEST_FILES
  *_test.cpp
)

foreach(test_src ${KITTEN_ALL_TEST_FILES})
  get_filename_component(test_file_name ${test_src} NAME_WE)
  set(test_name "kitten_${test_file_name}")
  add_executable(${test_name} "${test_src}")
  if(NOT MSVC)
    target_compile_options(${test_name} PRIVATE -Wno-unused-variable)
  endif()
  target_link_libraries(${test_name} kitten gtest gtest_main)
  add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
endforeach()
