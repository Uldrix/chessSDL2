cmake_minimum_required(VERSION 3.20)
project(ChessGame)

set(CMAKE_CXX_STANDARD 17)

# Include SDL2
include_directories(C:/FW/SDL2-2.30.8-VC/include)
link_directories(C:/FW/SDL2-2.30.8-VC/lib)

add_executable(ChessGame src/main.cpp)

# Link SDL2 libraries
target_link_libraries(ChessGame SDL2 SDL2main SDL2_image)
