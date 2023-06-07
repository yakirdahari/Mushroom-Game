#pragma once
#include "movingObject.h"

movingObject::movingObject(const sf::Vector2f& position, Resources::Objects object)
	: gameObject(position),
	  m_animation(Resources::instance().animationData(object), Direction::Stay, m_sp)
{
}

void movingObject::updatePhysics()
{
	// gravity
	physics.velocity.y += physics.gravity;
	
	if (std::abs(physics.velocity.x) > physics.velocityMaxY)
	{
		physics.velocity.y = physics.velocityMaxY * ((physics.velocity.y < 0.f) ? -1.f : 1.f);
	}

	// deceleration
	physics.velocity *= physics.drag;

	// limit deceleration
	if (std::abs(physics.velocity.x) < physics.velocityMin)
	{
		physics.velocity.x = 0.f;
	}
	if (std::abs(physics.velocity.y) < physics.velocityMin)
	{
		physics.velocity.y = 0.f;
	}
	m_sp.move(physics.velocity);
}

//void movingObject::handleCollision(Wall& wall)
//{
//	m_dir = opposite(m_dir);
//	m_animation.direction(m_dir);
//}
