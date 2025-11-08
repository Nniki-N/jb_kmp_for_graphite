cmake_minimum_required(VERSION 4.0)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-I$ENV{JAVA_HOME}/include -I$ENV{JAVA_HOME}/include/darwin)

add_library(cpp SHARED matrix.cpp
        matrix_c.h
        matrix_c.cpp
        matrix_jni.cpp)
add_executable(matrix_test main.cpp)
target_link_libraries(matrix_test matrix)
