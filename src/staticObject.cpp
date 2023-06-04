#include "staticObject.h"

staticObject::staticObject(const sf::Vector2f& position)
	: gameObject(position)
{
}

staticObject::staticObject(const sf::Vector2f& position, const sf::Vector2f& mapSize,
	                       const sf::Vector2f& resolution)
	: gameObject(position, mapSize, resolution)
{
}

