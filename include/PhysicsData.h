#pragma once

struct PhysicsData
{
	sf::Vector2f velocity;
	float velocityMax = 20.f;
	float velocityMaxY = 1.f;
	float velocityMin = 1.f;
	float acceleration = 2.f;
	float drag = 1.f;
	float gravity = 1.2f;
};