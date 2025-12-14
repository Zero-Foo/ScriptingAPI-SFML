cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

find_package(SFML 3 COMPONENTS Graphics Window System CONFIG REQUIRED)

project(S_API)

add_library(${PROJECT_NAME} SHARED)

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/scripts/*.cpp")
target_sources(${PROJECT_NAME} PUBLIC ${SRC} "${CMAKE_CURRENT_SOURCE_DIR}/function_exporter.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/scripts"
)

target_link_libraries(Scripting-API PUBLIC
    SFML::Graphics
    SFML::Window
    SFML::System
)