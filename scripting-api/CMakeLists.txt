add_library(Scripting-API)

find_package(SFML 3 COMPONENTS Graphics Window System CONFIG REQUIRED)

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(Scripting-API PUBLIC ${SRC})

target_include_directories(Scripting-API PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Scripting-API PUBLIC
    SFML::Graphics
    SFML::Window
    SFML::System
)