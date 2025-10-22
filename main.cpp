#include "GameManager.h"

int main()
{
    GameManager manager {2};

    manager.StartGame();

    while (manager.Player->IsAlive())
    {
        manager.PlayerTurn();
        // TODO: enemy choice
    }

    return 0;
}
