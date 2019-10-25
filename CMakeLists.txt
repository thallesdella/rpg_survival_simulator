# cmake_minimum_required(VERSION <specify CMake version here>)
project(rpg C)

set(CMAKE_C_STANDARD 99)

add_executable(rpg main.c Source/App/PlayerController.c Source/App/PlayerController.h Source/App/GameController.c Source/App/GameController.h Source/Helpers/Helpers.c Source/Helpers/Helpers.h Source/Rooms/Forest/Forest.c Source/Rooms/Forest/Forest.h Source/Rooms/River/River.c Source/Rooms/River/River.h Source/Rooms/Cave/Cave.c Source/Rooms/Cave/Cave.h Source/App/RoomController.c Source/App/RoomController.h Source/Rooms/Start/Start.c Source/Rooms/Start/Start.h Source/Rooms/GameOver/GameOver.c Source/Rooms/GameOver/GameOver.h Source/Rooms/Introduction/Introduction.c Source/Rooms/Introduction/Introduction.h Source/Rooms/Elf/Elf.c Source/Rooms/Elf/Elf.h Source/Helpers/Colors.c Source/Helpers/Colors.h Source/App/TimeController.c Source/App/TimeController.h Source/Rooms/Trail/Trail.c Source/Rooms/Trail/Trail.h Source/Rooms/Ruins/Ruins.c Source/Rooms/Ruins/Ruins.h)