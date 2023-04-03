cmake_minimum_required(VERSION 3.24)
project(Game)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_DIR SDL2-2.26.4/cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Game main.cpp)
target_link_libraries(Game ${SDL2_LIBRARIES})