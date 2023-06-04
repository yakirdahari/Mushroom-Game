#pragma once

#include "gameObject.h"
#include "Direction.h"
#include "Animation.h"

class movingObject : public gameObject
{
public:
	// Constructors
	movingObject(const sf::Vector2f& position);
	movingObject(const sf::Vector2f& position, const sf::Vector2f& mapSize,
		         const sf::Vector2f& resolution);
	
	// Functions
	virtual void update(const sf::Time delta) = 0;

	// Variables
protected:
	Direction m_dir = Direction::Stay;
};