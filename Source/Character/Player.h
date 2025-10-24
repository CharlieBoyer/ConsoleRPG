#pragma once

#include <cmath>
#include "Character.h"

class Player final : public Character
{
public:
	explicit Player(const std::string& name);
	~Player() override = default;

	void Display() const override;
	void TakeDamage(int damage) override;
	void Attack(Character &target) override;

	void GainEXP(int exp);
	void LevelUp();

private:
	int GetNextLevelExp() const { return static_cast<int>(std::round(100 * std::pow(1.5, _level))); }

	int _exp;
	int _nextLevelExp;
};
