cmake_minimum_required( VERSION 3.15 )

project(lexer-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

find_package(GTest REQUIRED)

add_executable( LexerTest LexerTest.cpp )
target_link_libraries( LexerTest lexer GTest::gtest_main)

add_executable( RecursiveDescentTest RecursiveDescentTest.cpp )
target_link_libraries( RecursiveDescentTest parser lexer GTest::gtest_main)
