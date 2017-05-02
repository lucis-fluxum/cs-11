cmake_minimum_required(VERSION 3.6)
project(CS_11)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# TODO: uncomment all executables when finished with assignments
#add_executable(A1.1 src/a1_1.cpp)
#add_executable(A1.2 src/a1_2.cpp)
#
#add_executable(A2.1 src/a2_1.cpp)
#add_executable(A2.2 src/a2_2.cpp)
#add_executable(A2.3 src/a2_3.cpp)
#
#add_executable(A3.1 src/a3_1.cpp)
#
#add_executable(A4.1 src/a4_1.cpp src/Fraction.cpp include/Fraction.h)
#
#add_executable(A5.1 src/a5_1.cpp src/mystring.cpp include/mystring.h)
#
#add_executable(A6.1 src/a6_1.cpp src/mystring.cpp include/mystring.h)
#
#file(GLOB a7_SRC "include/creature/*.h" "src/creature/*.cpp")
#add_executable(A7 src/a7.cpp ${a7_SRC})
#
#add_executable(A8.1 src/a8_1.cpp)
#add_executable(A8.2 src/a8_2.cpp include/orderedpair.h)
#
#add_executable(A9.1 src/a9_1.cpp src/sequence.cpp include/sequence.h)

add_executable(A10.1 src/a10_1.cpp src/sequence.cpp include/sequence.h)

add_executable(A11.1 src/a11_1.cpp src/sequence.cpp include/sequence.h)

add_executable(A12.1 src/a12_1.cpp)
add_executable(A12.2 src/a12_2.cpp src/mystring.cpp include/mystring.h)
add_executable(A12.3 src/a12_3.cpp)

add_executable(A13.1 src/a13_1.cpp src/binarytree.cpp include/binarytree.h include/LL.h)
