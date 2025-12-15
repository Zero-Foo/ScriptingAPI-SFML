cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

add_library(S_API SHARED)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/scripts/*.cpp")
target_sources(S_API PUBLIC ${SRC} "${CMAKE_CURRENT_SOURCE_DIR}/function_exporter.cpp")

target_include_directories(S_API PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/scripts"
)

target_link_libraries(S_API PUBLIC
    SFML::Graphics
    SFML::Window
    SFML::System
)