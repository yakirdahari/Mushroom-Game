#pragma once

struct PhysicsData
{
	sf::Vector2f velocity;
	float velocityMax = 20.f;
	float velocityMaxY = 1.f;
	float velocityMin = 1.f;
	float acceleration = 3.f;
	float drag = 0.85f;
	float gravity = 4.f;
};