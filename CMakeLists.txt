cmake_minimum_required(VERSION 3.31)
project(Test VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SOURCES "src/*.cpp" "src/*.h")

add_executable(Test ${SOURCES})

target_include_directories(Test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_compile_definitions(Test PRIVATE _UNICODE)
target_compile_definitions(Test PRIVATE UNICODE)

