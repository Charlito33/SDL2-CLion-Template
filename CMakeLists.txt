cmake_minimum_required(VERSION 3.24)
project(Game)

set(CMAKE_CXX_STANDARD 20)

# https://www.codegrepper.com/tpc/sdl2+clion/636282?ucard=1
#SET(CMAKE_CXX_LINK_FLAGS "-lSDL2 -lSDL2_image")

# https://www.codegrepper.com/tpc/sdl2+clion/501945?ucard=1
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(Game main.cpp)

target_link_libraries(Game mingw32 SDL2main SDL2)