#pragma once

#include "gameObject.h"
#include "Resources.h"

class staticObject : public gameObject
{
public:
	// Constructor
	staticObject(const sf::Vector2f& position, const sf::Texture& texture);

	// Collision Handlers
	//virtual void handleCollision(movingObject& movingObject) override;
	//virtual void handleCollision(Monster& monster) override;
	virtual void handleCollision(Ground& ground) override {};
	//virtual void handleCollision(Wall& wall) override {};
	//virtual void handleCollision(MonsterWall& monsterWall) override {};
	//virtual void handleCollision(Ladder& ladder) override {};
	//virtual void handleCollision(Rope& rope) override {};
};