cmake_minimum_required(VERSION 4.0)
project(ConsoleRPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConsoleRPG Source/main.cpp
        Source/Character/Character.h
        Source/Character/Player.cpp
        Source/Character/Player.h
        Source/Character/Enemy.cpp
        Source/Character/Enemy.h
        Source/Character/Slime.h
        Source/Character/Goblin.h
        Source/GameManager.cpp
        Source/GameManager.h
        Source/EnemyWave.tpp
        Source/EnemyWave.h
        Source/Character/Goblin.cpp
        Source/Character/Slime.cpp
        Source/IWave.h)
