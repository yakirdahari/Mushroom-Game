#pragma once
#include "movingObject.h"

movingObject::movingObject(const sf::Vector2f& position, Resources::Objects object)
	: gameObject(position),
	  m_animation(Resources::instance().animationData(object), Direction::Stay, m_sp),
	  m_position(position), m_lastPosition(position)
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