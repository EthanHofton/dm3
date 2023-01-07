cmake_minimum_required(VERSION 3.24.3)
project(dm3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.cpp")

option(USE_GLFW  "Use GLFW as a windowing API"  OFF)
option(USE_SDL   "Use SDL as a windowing API"   OFF)
option(USE_COCOA "use COCOA as a windowing API" ON)
option(USE_WIN32 "use WIN32 as a windowing API" OFF)

add_subdirectory("lib/util")
add_subdirectory("lib/glm")

if (APPLE AND NOT IPHONE)
    set(MACOS 1)
endif()


if (USE_SDL)
    add_subdirectory("lib/sdl")
    message("-- SDL enalbled")
    list(APPEND EXTRA_LIBS SDL3::SDL3-static)
endif()

if (USE_COCOA AND MACOS)
    # add objective c++ compile flag
    add_definitions("-x objective-c++")
    file(GLOB OBJCXX_SOURCES "src/*.mm")
    list(APPEND EXTRA_LIBS "-framework Foundation")
    list(APPEND EXTRA_LIBS "-framework Cocoa")
    message("-- Cocoa enabled")
elseif(USE_COCOA AND NOT MACOS)
    message(WARNING "-- Cocoa is mac only. Unsetting and using GLFW instead")
    set(USE_COCOA OFF)
    set(USE_GLFW  ON)
endif()

if (USE_WIN32 AND WIN32)
    message("-- WIN32 enabled")
elseif(USE_WIN32 AND NOT WIN32)
    message(WARNING "-- WIN32 is windows only. Unsetting and using GLFW instead")
    set(USE_WIN32 OFF)
    set(USE_GLFW  ON)
endif()

if (NOT USE_GLFW AND NOT USE_SDL AND NOT USE_COCOA AND NOT USE_WIN32)
    message(WARNING "-- No window API selected, using GLFW")
    set(USE_GLFW ON)
endif()

if (USE_GLFW)
    add_subdirectory("lib/glfw")
    message("-- GLFW enalbled")
    list(APPEND EXTRA_LIBS glfw)
endif()

configure_file(dm3Config.hpp.in dm3Config.hpp)

add_library(dm3 ${SOURCES} ${OBJCXX_SOURCES})

# add include directory
target_include_directories(dm3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(dm3 PUBLIC ${PROJECT_BINARY_DIR})

# link libaries
target_link_libraries(dm3 PUBLIC util)
target_link_libraries(dm3 PUBLIC glm)
target_link_libraries(dm3 PRIVATE ${EXTRA_LIBS})
