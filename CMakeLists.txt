cmake_minimum_required(VERSION 3.24.3)
project(dm3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.cpp")

add_subdirectory("lib/util")
add_subdirectory("lib/glfw")
add_subdirectory("lib/glm")

add_library(dm3 ${SOURCES})

# add include directory
target_include_directories(dm3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# link libaries
target_link_libraries(dm3 PUBLIC util)
target_link_libraries(dm3 PUBLIC glm)
target_link_libraries(dm3 PUBLIC glfw)
