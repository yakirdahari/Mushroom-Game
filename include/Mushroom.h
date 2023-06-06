#pragma once

#include "Monster.h"

#include <SFML/Graphics.hpp>

class Mushroom : public Monster
{
public:
    Mushroom(const sf::Vector2f& position);
    Mushroom(const sf::Vector2f& position, const sf::Vector2f& mapSize,
        const sf::Vector2f& resolution);
};
