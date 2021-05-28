cmake_minimum_required(VERSION 3.19)
project(Server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(Server main.cpp ServerSocket.cpp ServerSocket.h Matrix.cpp Matrix.h Astar.cpp Astar.h NodeAStar.cpp NodeAStar.h Backtracking.cpp Backtracking.h)