#include "GameManager.h"

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
}

void GameManager::SelectAction()
{
	int choice = 0;

	std::cout << "___ CHOOSE AN ACTION ___\n\n" <<
		"What would you like to do?\n" <<
		"    1. Use an object\n" <<
		"    2. (Fight) Slimes\n" <<
		"    3. (Fight) Goblins\n" <<
	    "    4. Come back another day (exit the game)\n\n";

	std::cin >> choice;

	while (choice < 1 || choice > 4)
	{
		std::cout << "Invalid choice, what would you like to do?\n" <<
		"    1. Use an object\n" <<
		"    2. (Fight) Slimes\n" <<
		"    3. (Fight) Goblins\n" <<
		"    4. Come back another day (exit the game)\n\n";

		std::cin >> choice;
	}

	switch (choice)
	{
		case 1:
			// TODO: Use an object
			std::cout << "[Use an object not available]\n\n";
			break;
		case 2:
			Wave = _slimes;
			break;
		case 3:
			Wave = _goblins;
		case 4:
			std::cout << "See you next time !\n";
			exit(0);
		default:
			throw std::invalid_argument("GameManager::SelectAction() - Unexpected user input caught");
	}
}

void GameManager::PlayerTurn()
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
			Attack(); // TODO!
			break;
		case 2:
			Skip(); // TODO!
			break;
		case 3:
			Flee(); // TODO!
			break;
		default:
			throw std::invalid_argument("GameManager::PlayerTurn() - Unexpected user input caught");
	}
}

void GameManager::EnemyTurn()
{

}

void GameManager::Attack()
{

} // TODO!

void GameManager::Skip()
{

} // TODO!

void GameManager::Flee()
{

} // TODO!
