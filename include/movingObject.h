#pragma once

#include "gameObject.h"
#include "Direction.h"
#include "Animation.h"
#include "PhysicsData.h"
#include "Resources.h"

class movingObject : public gameObject
{
public:
	// Constructors
	movingObject(const sf::Vector2f& position, Resources::Objects object);
	
	// Functions
	virtual void update(const sf::Time delta) = 0;
	void updatePhysics();

	// Variables
protected:
	Direction m_dir = Direction::Stay;
	sf::Vector2f m_position;
	sf::Vector2f m_lastPosition;
	PhysicsData physics;
	Animation m_animation;
	sf::Clock m_aiTime;
};