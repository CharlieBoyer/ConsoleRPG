cmake_minimum_required(VERSION 4.0)
project(ConsoleRPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConsoleRPG main.cpp
        Character/Character.h
        Character/Player/Player.cpp
        Character/Player/Player.h
        Character/Enemy/Enemy.cpp
        Character/Enemy/Enemy.h
        EnemyWaves/EnemyWave.h
        GameManager.cpp
        GameManager.h
        Items/Item.cpp
        Items/Item.h)
