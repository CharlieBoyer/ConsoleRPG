//
// Created by c.boyer on 22/10/2025.
//

#pragma once
#include <string>

class Item
{
public:
	Item(std::string name, std::string description);
	~Item();

	bool Use() const;

	const std::string Name;
	const std::string Description;
};
