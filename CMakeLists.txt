cmake_minimum_required(VERSION 4.0)
project(ConsoleRPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConsoleRPG main.cpp
        Character/Character.h
        Character/Player.cpp
        Character/Player.h
        Character/Ennemy/Enemy.h)
