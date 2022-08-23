cmake_minimum_required(VERSION 3.11)

project(
        i2a
        VERSION 0.1
        LANGUAGES CXX
)

enable_testing()
include(GoogleTest)
add_subdirectory(tests)
add_subdirectory(src)