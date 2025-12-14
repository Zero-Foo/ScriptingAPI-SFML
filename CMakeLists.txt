cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 23)

project(
  Scripting_API
  VERSION 1.0
)

add_subdirectory("${CMAKE_SOURCE_DIR}/exemple/")
add_subdirectory("${CMAKE_SOURCE_DIR}/scripting-api")

