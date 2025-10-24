#pragma once
#include <memory>

#include "EnemyWave.h"
#include "Character/Player.h"
#include "Character/Slime.h"
#include "Character/Goblin.h"

using SlimeWavePtr = std::shared_ptr<EnemyWave<Slime>>;
using GoblinWavePtr = std::shared_ptr<EnemyWave<Goblin>>;

class GameManager
{
public:
	GameManager() = default;
	~GameManager() = default;

	/*
	 * TODO:	void SelectFirstItem()
	 * TODO:	{
	 * TODO:		std::cout << "Prepare yourself, you are ambushed by multiples enemy waves.\n" <<
	 * TODO: 			"You have the time to take a item for the combats ahead :\n" <<
	 * TODO: 			"\t1. Health Potion (recovers all your HPs)\n" <<
	 * TODO: 			"\t2. Iron Sword (+2 Strength)\n" <<
	 * TODO: 			"\t3. Wooden Shield (+2 Defense)\n\n";
	 * TODO:	}
	 */

	void StartGame();
	void SelectAction();

	void PlayerTurn();
	void EnemyTurn();
	void Attack();
	void Skip();
	void Flee();

	std::shared_ptr<Player> Player = nullptr;
	std::shared_ptr<IWave> Wave = nullptr;

private:
	SlimeWavePtr _slimes;
	GoblinWavePtr _goblins;
};
