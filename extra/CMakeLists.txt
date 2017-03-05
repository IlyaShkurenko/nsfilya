cmake_minimum_required(VERSION 3.6)
project(prac)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(prac ${SOURCE_FILES})
include_directories(/usr/local/include)

TARGET_LINK_LIBRARIES(prac /usr/local/lib/libextramodule.dylib)

include_directories(/usr/local/Cellar/check/0.11.0/include)

TARGET_LINK_LIBRARIES(prac /usr/local/Cellar/check/0.11.0/lib/libcheck.dylib)
