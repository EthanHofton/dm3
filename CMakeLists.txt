cmake_minimum_required(VERSION 3.24.3)
project(dm3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.cpp")

option(USE_GLFW  "Use GLFW as a windowing API"  ON)
option(USE_SDL   "Use SDL as a windowing API"   OFF)
option(USE_COCOA "use COCOA as a windowing API" OFF)
option(USE_WIN32 "use WIN32 as a windowing API" OFF)

add_subdirectory("lib/util")
add_subdirectory("lib/glm")

if (USE_GLFW)
    add_subdirectory("lib/glfw")
    message("-- GLFW enalbled")
    list(APPEND EXTRA_LIBS glfw)
endif()

if (USE_SDL)
    add_subdirectory("lib/sdl")
    message("-- SDL enalbled")
    list(APPEND EXTRA_LIBS SDL3::SDL3-static)
endif()

configure_file(dm3Config.hpp.in dm3Config.hpp)

add_library(dm3 ${SOURCES})

# add include directory
target_include_directories(dm3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(dm3 PUBLIC ${PROJECT_BINARY_DIR})

# link libaries
target_link_libraries(dm3 PUBLIC util)
target_link_libraries(dm3 PUBLIC glm)
target_link_libraries(dm3 PUBLIC ${EXTRA_LIBS})

