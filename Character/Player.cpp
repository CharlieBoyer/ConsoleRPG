//
// Created by c.boyer on 21/10/2025.
//

#include "Player.h"

#include <iostream>
#include <sstream>

#include "Ennemy/Enemy.h"

Player::Player(const std::string &name):
    Character(name, 10, 1, 0), _exp(0), _nextLevelExp() {}

void Player::Display() {}

void Player::TakeDamage(int damage) {}

void Player::Attack(Enemy &target) {}

void Player::GainEXP(const int exp)
{
    _exp += exp;

    if (_exp >= _nextLevelExp)
    {
        _exp -= _nextLevelExp;
        LevelUp();
    }
}

void Player::LevelUp()
{
    int choice = 0;

    _level++;
    std::cout << "\u9733\u9733 ___ NEXT LEVEL ___ \u9733\u9733\n" <<
              "Congratulations " << _name << ", you reached level (" << _level << ")!\n\n"
              "Choose your next attribute to improve:\n" <<
              "\t\t\\1. HP\n" <<
              "\t\t\\2. Strength\n" <<
              "\t\t\\3. Defense\n";
    std::cin >> choice;

    while (choice < 0 || choice > 3)
    {
        std::cout << "Invalid choice, choose your next attribute to improve:\n" <<
              "\t\t\\1. HP\n" <<
              "\t\t\\2. Strength\n" <<
              "\t\t\\3. Defense\n";
        std::cin >> choice;
    }

    switch (choice) {
        case 1:
            _hp += 2;
            std::cout << "Strength increased: " << _strength - 2 << " → " << _strength << "\n\n";
            break;
        case 2:
            _strength++;
            std::cout << "Strength increased: " << _strength - 1 << " → " << _strength << "\n\n";
            break;
        case 3:
            _defense++;
            std::cout << "Strength increased: " << _defense - 1 << " → " << _defense << "\n\n";
            break;
        default:
            throw std::invalid_argument("Player::LevelUp() - Unexpected choiceIndex caught");
    }
}
