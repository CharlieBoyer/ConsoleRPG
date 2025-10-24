#pragma once

#include "Enemy.h"

class Slime final : public Enemy
{
public:
	static int InstanceCount;

	Slime() : Enemy{"Slime_", 1, 50, 3, 1, 0}
	{
		Name += std::to_string(InstanceCount);
		InstanceCount++;
	}
	Slime(const std::string &name, const int level, const int expValue, const int baseHP, const int baseStrength, const int baseDefense)
		: Enemy{name, level, expValue, baseHP, baseStrength, baseDefense}
	{
		Name = name + "_" + std::to_string(InstanceCount);
		InstanceCount ++;
	}
	Slime(const Slime &copy)
		: Enemy{copy}
	{
		Name = copy.Name + "_" + std::to_string(InstanceCount);
		InstanceCount++;
	}
};