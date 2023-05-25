cmake_minimum_required(VERSION 3.26)

project(imb C)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

file(GLOB SOURCES
${PROJECT_SOURCE_DIR}/include/*.h
${PROJECT_SOURCE_DIR}/include/*.c
${PROJECT_SOURCE_DIR}/main.c)

add_executable(imbroglio ${SOURCES})
target_compile_options(imbroglio PRIVATE -static)
