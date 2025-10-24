#pragma once

#include "Enemy.h"

class Goblin final : public Enemy
{
public:
	static int InstanceCount;

	Goblin() : Enemy{"Goblin_", 2, 100, 5, 2, 0}
	{
		Name += std::to_string(InstanceCount);
		InstanceCount++;
	}
	Goblin(const std::string &name, const int level, const int expValue, const int baseHP, const int baseStrength, const int baseDefense)
	: Enemy{name, level, expValue, baseHP, baseStrength, baseDefense}
	{
		Name = name + "_" + std::to_string(InstanceCount);
		InstanceCount ++;
	}
	Goblin(const Goblin &copy)
	: Enemy{copy}
	{
		Name = copy.Name + "_" + std::to_string(InstanceCount);
		InstanceCount++;
	}
};


