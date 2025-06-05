cmake_minimum_required(VERSION 3.31)
project(Fill)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_executable(Fill main.cpp
        src/FillGrid.cpp
        include/FillGrid.h
)
include_directories(include)

add_executable(tests
        tests/tests.cpp
)
target_link_libraries(tests gtest)
