//
// Created by c.boyer on 21/10/2025.
//

#include "Player.h"

#include <algorithm>
#include <iostream>
#include <sstream>

#include "../Ennemy/Enemy.h"

Player::Player(const std::string &name):
    Character(name, 1, 10, 1, 0), _exp(0)
{
    _nextLevelExp = GetNextLevelExp();
}

void Player::Display()
{
    std::cout << "___ " << Name << " Lv. " << _level << " ___\n" <<
        "\tHP → " << _hp << " /" << _maxHp << "\n" <<
        "\tStrength → " << _strength << "\n" <<
        "\tDefense → " << _defense << "\n" <<
    "Next level in " << _nextLevelExp - _exp << " exp points\n\n";
}

void Player::TakeDamage(const int damage)
{
    const int oldHp = _hp;

    _hp -= std::clamp(damage, 0, damage - _defense);

    std::cout << "Ouch! You have taken " << oldHp - _hp << " damage(s) (reduced by " << _defense << ")\n\n";
}

void Player::Attack(Character &target)
{
    target.TakeDamage(_strength);
    std::cout << "Attack → " << target.Name << std::endl <<
        "Dealt " << _strength << " damage(s)!\n\n";
}

void Player::GainEXP(const int exp)
{
    _exp += exp;
    std::cout << _exp - exp << " → " << _exp << " /" << _nextLevelExp << "exp points (+" << exp << ")\n\n";

    if (_exp >= _nextLevelExp)
    {
        LevelUp();
    }
}

void Player::LevelUp()
{
    int choice = 0;

    _exp -= _nextLevelExp;
    _level++;
    _nextLevelExp = GetNextLevelExp();

    std::cout << "\u9733\u9733 ___ NEXT LEVEL ___ \u9733\u9733\n" <<
              "Congratulations " << Name << ", you've reached level (" << _level << ")!\n\n"
              "Choose your next attribute to improve:\n" <<
              "\t\t\\1. HP\n" <<
              "\t\t\\2. Strength\n" <<
              "\t\t\\3. Defense\n";
    std::cin >> choice;

    while (choice < 0 || choice > 3)
    {
        std::cout << "Invalid choice, choose your next attribute to improve:\n" <<
              "\t\t\\1. Max HP    ↑\n" <<
              "\t\t\\2. Strength  ↑\n" <<
              "\t\t\\3. Defense   ↑\n";
        std::cin >> choice;
    }

    switch (choice) {
        case 1:
            _maxHp += 2;
            _hp = _maxHp;
            std::cout << "Max HP increased: " << _strength - 2 << " → " << _strength << "\n" <<
                "\t→ HP fully restored.\n\n";
            break;
        case 2:
            _strength++;
            std::cout << "Strength increased: " << _strength - 1 << " → " << _strength << "\n\n";
            break;
        case 3:
            _defense++;
            std::cout << "Defense increased: " << _defense - 1 << " → " << _defense << "\n\n";
            break;
        default:
            throw std::invalid_argument("Player::LevelUp() - Unexpected choiceIndex caught");
    }
}
