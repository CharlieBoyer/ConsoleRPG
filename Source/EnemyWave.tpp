#pragma once

#include <iostream>

#include "EnemyWave.h"

template<typename T>
EnemyWave<T>::EnemyWave(const int difficultyRating, const int defaultReserve)
{
	_difficulty = difficultyRating;
	_enemies = std::vector<std::shared_ptr<T>>();
	_enemies.reserve(defaultReserve);
}

template<typename T>
EnemyWave<T>::EnemyWave(const int difficultyRating, std::initializer_list<T&> enemies)
{
	_difficulty = difficultyRating;
	_enemies = std::vector<std::shared_ptr<T>>();
	_enemies.reserve(enemies.size());

	for (T& enemyRef : enemies) {
		_enemies.push_back(std::make_shared<T>(enemyRef));
	}
}

template<typename T>
void EnemyWave<T>::Display() const
{
	std::cout << "Wave of <" << typeid(T).name() << ">  " << Difficulty() << std::endl;

	for (int i = 0; i < _enemies.size(); i++)
	{
		std::cout << "    " << _enemies[i]->Name << " Lv. " << _enemies[i]->_level << "  "
			<< " HP: " << _enemies[i]->_hp << " /" << _enemies[i]->_maxHp << std::endl;
	}

	std::cout << std::endl;
}

template<typename T>
void EnemyWave<T>::BuildWave(std::initializer_list<T&> enemies) const
{
	for (T& enemyRef : enemies) {
		_enemies.push_back(std::make_shared<T>(enemyRef));
	}
}

template<typename T>
void EnemyWave<T>::CurrentEnemy(T& out)
{
	out = _enemies[_currentIndex];
}

template<typename T>
std::string EnemyWave<T>::Difficulty() const
{
	std::string difficultyStr = "[";

	for (int i = 0; i < MAX_DIFFICULTY; i++)
	{
		if (i <= _difficulty)
			difficultyStr += "!";
		else
			difficultyStr += "\u2022";
	}

	difficultyStr += "]";

	return difficultyStr;
}
