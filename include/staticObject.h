#pragma once

#include "gameObject.h"
#include "Player.h"
#include "Monster.h"

class staticObject : public gameObject
{
public:
	// Constructor
	staticObject(const sf::Vector2f& position);
	staticObject(const sf::Vector2f& position, const sf::Vector2f& mapSize,
		         const sf::Vector2f& resolution);

	// Collision Handlers

};