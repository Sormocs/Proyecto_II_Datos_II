cmake_minimum_required(VERSION 3.19)
project(Client)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

add_executable(Client main.cpp ClientSock.cpp ClientSock.h GUI.cpp GUI.h Button.cpp Button.h BPGame.cpp BPGame.h GenPuzzle.cpp GenPuzzle.h PlayersList.cpp PlayersList.h Ball.cpp Ball.h PhysController.cpp PhysController.h PlayerObs.cpp PlayerObs.h json.hpp TextBox.cpp TextBox.h ImageParts.cpp ImageParts.h Line.cpp Line.h)
target_link_libraries(Client sfml-graphics sfml-window sfml-system)