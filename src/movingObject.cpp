#pragma once
#include "movingObject.h"

movingObject::movingObject(const sf::Vector2f& position)
	: gameObject(position)
{
}

movingObject::movingObject(const sf::Vector2f& position, const sf::Vector2f& mapSize,
	                       const sf::Vector2f& resolution)
	: gameObject(position, mapSize, resolution)
{
}
