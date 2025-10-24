#pragma once

#include <memory>
#include <vector>

#include "IWave.h"

#define MAX_DIFFICULTY 10

template <typename T>
class EnemyWave final : public IWave
{
public:
	EnemyWave(int difficultyRating, int defaultReserve);
	EnemyWave(int difficultyRating, std::initializer_list<T&> enemies);
	~EnemyWave() override {} // NOLINT(*-use-equals-default)

	void Display() const override;
	void BuildWave(std::initializer_list<T&> enemies) const;
	void CurrentEnemy(T& out);

private:
	std::string Difficulty() const;

	int _difficulty;
	int _currentIndex = 0;
	std::vector<std::shared_ptr<T>> _enemies;
};

#include "EnemyWave.tpp"
