cmake_minimum_required( VERSION 3.12 )
project( Tutorial )

set( CMAKE_CXX_STANDARD 17 )
set( Tutorial_VERSION_MAJOR 1 )
set( Tutorial_VERSION_MINOR 0 )

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
include_directories( "${PROJECT_BINARY_DIR}" )


option( USE_OUTPUT_FUNCTIONS "Use tutorial provided output function to print the version number" ON )
if( USE_OUTPUT_FUNCTIONS )
    include_directories( "${PROJECT_SOURCE_DIR}/OutputFunctions" )
    add_subdirectory( OutputFunctions )
    set( EXTRA_LIBS ${EXTRA_LIBS} OutputFunctions )
endif( USE_OUTPUT_FUNCTIONS )


add_executable( Tutorial main.cpp )
target_link_libraries( Tutorial ${EXTRA_LIBS} )
