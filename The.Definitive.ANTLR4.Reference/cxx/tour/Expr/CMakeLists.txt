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

### test datafile
set(DATAFILES t.expr)

foreach(datafile ${DATAFILES})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${datafile}
        #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/${datafile}
                ${CMAKE_CURRENT_BINARY_DIR}/${datafile}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${datafile}
        COMMENT "Copying test datafile ${datafile}"
    )
endforeach()

add_custom_target(copy_datafiles ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/t.expr
)

add_executable( ExprJoyRide ExprJoyRide.cpp ${GEN_SOURCES} )
target_link_libraries( ExprJoyRide antlr4-runtime )
add_dependencies( ExprJoyRide copy_datafiles )

