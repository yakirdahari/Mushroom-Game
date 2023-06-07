#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
    Left,
    Right,
    Stay,
    Max,
    Up,
    Ladder,
    Rope,
    Dead,
    Hit,
    Jump,
    JumpRight,
    JumpLeft,
    ProneStab,
    Prone,
    Attack1,
    Attack2,
    Down,
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
