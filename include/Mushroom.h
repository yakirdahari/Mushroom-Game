#pragma once

#include "Monster.h"

#include <SFML/Graphics.hpp>

class Mushroom : public Monster
{
public:
    using movingObject::handleCollision;

    Mushroom(const sf::Vector2f& position);
};
