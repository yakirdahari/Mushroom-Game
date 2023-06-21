#pragma once

struct PhysicsData
{
	sf::Vector2f velocity;
	sf::Vector2f knockback = { 2.f, 7.f };
	float velocityMax = 5.f;
	float velocityMaxY = 10.f;
	float velocityMin = 1.f;
	float acceleration = 2.f;
	float drag = 1.08f;
	float gravity = 1.f;
};