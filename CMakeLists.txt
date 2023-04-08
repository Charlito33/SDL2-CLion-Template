cmake_minimum_required(VERSION 3.24)
project(Game)

set(CMAKE_CXX_STANDARD 17)

# https://wiki.libsdl.org/SDL2/README/cmake

set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2-2.26.5/cmake)
set(SDL2_image_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2_image-2.6.3/cmake)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image)

add_executable(Game WIN32 src/main.cpp)

if (TARGET SDL2::SDL2main)
    target_link_libraries(Game PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(Game PRIVATE SDL2::SDL2)
target_link_libraries(Game PRIVATE SDL2_image::SDL2_image)