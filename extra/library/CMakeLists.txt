cmake_minimum_required(VERSION 3.6)
project(extramodule)

set(CMAKE_C_STANDARD 11)
include_directories(include)
file(GLOB SOURCES "src/*.c")
set(SOURCE_FILES src/library.c include/library.h)
add_library(extramodule SHARED ${SOURCE_FILES})
install(
        DIRECTORY include/ DESTINATION /usr/local/include
        FILES_MATCHING PATTERN "*.h"
)
install(TARGETS extramodule DESTINATION /usr/local/lib)