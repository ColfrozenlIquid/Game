cmake_minimum_required(VERSION 3.27.2)
project(cmake_game)
set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(cmake_game main.cpp
    application.cpp
    camera.cpp
    character.cpp
    np_character.cpp
    spritesheet.cpp
    )
target_link_libraries(cmake_game ${SDL2_LIBRARIES})