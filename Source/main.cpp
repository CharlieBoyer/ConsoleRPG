#include <iostream>

#include "GameManager.h"

int main()
{
	GameManager manager = GameManager();

	// TODO: Make loop
	manager.StartGame();
	manager.SelectAction();
	manager.PlayerTurn();
}
