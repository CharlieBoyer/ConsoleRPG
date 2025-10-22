//
// Created by c.boyer on 22/10/2025.
//

#include <iostream>

#include "GameManager.h"

#include <ctime>

#include "Character/Player/Player.h"
#include "EnemyWaves/EnemyWave.h"

GameManager::GameManager(const int initialWaveCount)
{
	Player = nullptr;
	_waves = std::vector<EnemyWave<Enemy>>(initialWaveCount);
}

GameManager::~GameManager() = default;

bool GameManager::AddWave(const EnemyWave<Enemy>& wave)
{
	_waves.push_back(wave);
	return true;
}

void GameManager::StartGame()
{
	std::string playerName;

	std::cout << "___ CONSOLE RPG v.1 ___\n\n" <<
			"Welcome dear player!\n" <<
			"Please enter your character name:  ";

	std::cin >> playerName;
	Player = std::make_shared<class Player>(playerName);

	std::cout << "\nGreeting \"" << Player->Name << "\" !\n" <<
			"Here is a quick overview of your character stats:\n\n";

	Player->Display();

	// TODO: First item selection
	// std::cout << "Prepare yourself, you are ambushed by multiples enemy waves.\n" <<
	// 		"You have the time to take a item for the combats ahead :\n" <<
	// 		"\t1. Health Potion (recovers all your HPs)\n" <<
	// 		"\t2. Iron Sword (+2 Strength)\n" <<
	// 		"\t3. Wooden Shield (+2 Defense)\n\n";
}

void GameManager::PlayerTurn() const
{
	int choice;

	std::cout << "___ YOUR TURN ___\n\n" <<
			"What would you like to do?\n" <<
			"\t1. Attack\n" <<
			"\t2. Skip\n" <<
			"\t3. Flee\n\n";

	std::cin >> choice;

	while (choice < 1 || choice > 3)
	{
		std::cout << "Invalid choice, what would you like to do?\n" <<
			"\t\t1. Attack\n" <<
			"\t\t2. Skip\n" <<
			"\t\t3. Flee\n\n";
		std::cin >> choice;
	}

	switch (choice)
	{
		case 1:
			Attack();
			break;
		case 2:
			Skip();
			break;
		case 3:
			Flee();
			break;
		default:
			throw std::invalid_argument("GameManager::PlayerTurn() - Unexpected choice caught");
	}
}

void GameManager::Attack() const
{
	Player->Attack(*CurrentWave->CurrentEnemy);

	if (!CurrentWave->CurrentEnemy->IsAlive())
	{
		CurrentWave->GetNextEnemy();
	}
}

void GameManager::Skip() const
{
	// TODO: do nothing?
}

void GameManager::Flee() const
{
	std::srand(std::time({}));

	if (const int fleeChance = std::rand() % 100; fleeChance > 75)
	{
		std::cout << "You successfully fled the battle!\n\n";
		// TODO: End combat and return to action menu.
	}
	else
	{
		std::cout << "You failed to flee the battle!\n\n";
	}
}
