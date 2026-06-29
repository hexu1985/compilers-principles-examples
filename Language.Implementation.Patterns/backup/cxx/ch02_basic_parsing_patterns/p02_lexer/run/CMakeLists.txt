cmake_minimum_required( VERSION 3.15 )

project(lexer-run LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

set(TEST_FILE test.txt)

foreach(script ${TEST_FILE})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${script}
        #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/${script}
                ${CMAKE_CURRENT_BINARY_DIR}/${script}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${script}
        COMMENT "Copying test script ${script}"
    )
endforeach()

add_custom_target(copy_files ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/test.txt
)

add_executable( LexerRun LexerRun.cpp )
target_link_libraries( LexerRun lexer )
add_dependencies( LexerRun copy_files )
