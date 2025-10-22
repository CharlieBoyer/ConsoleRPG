//
// Created by c.boyer on 22/10/2025.
//

#include "Item.h"

#include <utility>

Item::Item(std::string name, std::string description): Name(std::move(name)), Description(std::move(description)) {}
