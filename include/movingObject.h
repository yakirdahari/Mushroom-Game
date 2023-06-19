#pragma once

#include "gameObject.h"
#include "Direction.h"
#include "Animation.h"
#include "PhysicsData.h"
#include "Resources.h"
#include "Data.h"

class movingObject : public gameObject
{
public:
	// Constructors
	movingObject(const sf::Vector2f& position,
		         const Resources::Objects& object);
	
	// Functions
	virtual void update(const sf::Time delta) = 0;
	void wasHit(const int& damage, const sf::Vector2f& direction);
	void knockback(const sf::Vector2f& direction);					// knock back when hit
	void updatePhysics();
	void respawn();												    // revives object and sends back to spawn
	int randomDamage();
	bool isDead();													// checks if HP is negative

	// Variables
protected:
	sf::Vector2f m_spawnLocation;
	Direction m_dir = Direction::Stay;
	Data data;
	PhysicsData physics;
	Animation m_animation;
	sf::Clock m_hitTime;		// how long hit effect lasts
	sf::Clock m_deathTime;		// helps with death animations
	bool dead;					// is object dead?
};