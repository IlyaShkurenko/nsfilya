cmake_minimum_required(VERSION 3.6)
project(prac)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(prac ${SOURCE_FILES})
include_directories(/usr/local/include)

TARGET_LINK_LIBRARIES(prac /usr/local/lib/libextramodule.dylib)

include_directories(/usr/local/Cellar/check/0.11.0/include)

TARGET_LINK_LIBRARIES(prac /usr/local/Cellar/check/0.11.0/lib/libcheck.dylib)

enable_testing()
add_test(unit-tests ${CMAKE_PROJECT_NAME})

## Coverage
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)
include(CodeCoverage)
setup_target_for_coverage(${CMAKE_PROJECT_NAME}_coverage ${CMAKE_PROJECT_NAME} coverage)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-std=c99 -g -O0 -fprofile-arcs -ftest-coverage")
