cmake_minimum_required(VERSION 3.21)
project(FtInch)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-std=c++20 -O0)

find_package(Catch2 3 REQUIRED)

set(
    SOURCE_FILES
    test.cpp
    Feet.hpp
    Feet.cpp
)

add_executable(FtInch ${SOURCE_FILES})
target_link_libraries(FtInch PRIVATE Catch2::Catch2WithMain)
target_compile_options(FtInch PRIVATE -w)