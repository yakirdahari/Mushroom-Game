#pragma once

#include "animatedObject.h"

class NPC : public animatedObject
{
public:
	using staticObject::handleCollision;

	// Constructor
	NPC(const sf::Vector2f& position, const Resources::Objects& object);

	// Functions
	virtual void update(const sf::Time delta);

	// Collision Handlers
	void handleCollision(gameObject& gameObject) {};
	virtual void handleCollision(Player& movingObject) {};
	virtual void handleCollision(Monster& monster) {}
};