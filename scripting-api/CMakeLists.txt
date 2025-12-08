add_library(Scripting-API)

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(Scripting-API PUBLIC ${SRC})

target_include_directories(Scripting-API PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")