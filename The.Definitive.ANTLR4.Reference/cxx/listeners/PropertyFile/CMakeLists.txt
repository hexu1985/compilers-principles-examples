cmake_minimum_required( VERSION 3.15 )

project ( antlr LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

include_directories( ${ANTLR4_DIR}/include/antlr4-runtime ${CMAKE_CURRENT_SOURCE_DIR}/gen )
link_directories( ${ANTLR4_DIR}/lib )

file(GLOB GEN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/gen/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/gen/*.h)

add_executable( TestPropertyFile TestPropertyFile.cpp ${GEN_SOURCES} )
target_link_libraries( TestPropertyFile antlr4-runtime )

add_executable( TestPropertyFileVisitor TestPropertyFileVisitor.cpp ${GEN_SOURCES} )
target_link_libraries( TestPropertyFileVisitor antlr4-runtime )


