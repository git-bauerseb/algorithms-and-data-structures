add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_executable(i2a_test test_project.cpp)
target_link_libraries(i2a_test gtest gmock gtest_main)
