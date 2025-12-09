cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 23)

project(Scripting_API_Project)

add_subdirectory("${CMAKE_SOURCE_DIR}/exemple/${COMPILER}")
add_subdirectory("${CMAKE_SOURCE_DIR}/scripting-api")

