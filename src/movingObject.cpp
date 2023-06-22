#pragma once
#include "movingObject.h"

constexpr auto HitDuration = 0.8f;

movingObject::movingObject(const sf::Vector2f& position,
	                       const Resources::Objects& object)
	: gameObject(position),
	  m_animation(Resources::instance().animationData(object), Direction::Stay, m_sp),
	  m_spawnLocation(position), dead(false)
{
}

void movingObject::wasHit(const int& damage, const sf::Vector2f& direction)
{
	if (m_hitTime.getElapsedTime().asSeconds() >= HitDuration &&
		m_dir != Direction::Attack1 && m_dir != Direction::Attack2 &&
		m_dir != Direction::ProneStab)
	{
		m_hitTime.restart();
		m_dir = Direction::Hit;
		knockback(direction);
		data.wasHit = true;
		data.HP -= damage;		// reduce health points
		if (data.HP < 0)
			data.HP = 0;		// hp can't go under 0
	}
}

void movingObject::knockback(const sf::Vector2f& direction)
{
	// knocks back object after being hit
	if (direction == sf::Vector2f(1.f, 1.f)) // attacker is facing right
	{
		physics.velocity = sf::Vector2f(physics.knockback.x, physics.velocity.y - physics.knockback.y);
	}
	else
	{
		physics.velocity = sf::Vector2f(-physics.knockback.x, physics.velocity.y - physics.knockback.y);
	}
}

void movingObject::updatePhysics()
{
	// gravity
	physics.velocity.y += physics.gravity;
	
	if (std::abs(physics.velocity.x) > physics.velocityMaxY)
	{
		physics.velocity.y = physics.velocityMaxY * ((physics.velocity.y < 0.f) ? -1.f : 1.f);
	}
	if (std::abs(physics.velocity.y) > physics.velocityMaxY)
	{
		physics.velocity.y = physics.velocityMaxY;
	}

	// deceleration
	physics.velocity *= physics.drag;

	// limit deceleration
	if (std::abs(physics.velocity.x) < physics.velocityMin)
	{
		physics.velocity.x = 0.f;
	}
	if (std::abs(physics.velocity.x) > physics.velocityMax)
	{
		physics.velocity.x = 0.f;
	}
	if (std::abs(physics.velocity.y) < physics.velocityMin)
	{
		physics.velocity.y = 0.f;
	}

	m_sp.move(physics.velocity);
}

void movingObject::respawn()
{
	data.HP = data.MaxHP;
	dead = false;
	data.wasHit = false;
	physics.drag = 1.12f;
	setPosition(m_spawnLocation);
}

int movingObject::randomDamage() const
{
	int maxDamage = data.damage * 1.2f;
	int minDamage = data.damage * 0.8f;

	return (rand() % maxDamage) + minDamage;
}

bool movingObject::isDead()
{
	if (data.HP == 0 && !dead)
	{
		dead = true;
		m_dir = Direction::Dead;
		m_deathTime.restart();
		physics.drag = 0.9f;
		m_animation.resetAnimation();
		return true;
	}
	return false;
}

const Data& movingObject::getData() const
{
	return data;
}
