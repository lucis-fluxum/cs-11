cmake_minimum_required(VERSION 3.6)
project(CS_11)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(A1.1 src/a1_1.cpp)
add_executable(A1.2 src/a1_2.cpp)

add_executable(A2.1 src/a2_1.cpp)
add_executable(A2.2 src/a2_2.cpp)
add_executable(A2.3 src/a2_3.cpp)

add_executable(A3.1 src/a3_1.cpp)

add_executable(A4.1 src/a4_1.cpp src/Fraction.cpp include/Fraction.h)

add_executable(A5.1 src/a5_1.cpp src/mystring.cpp include/mystring.h)

add_executable(A6.1 src/a6_1.cpp src/mystring.cpp include/mystring.h)
