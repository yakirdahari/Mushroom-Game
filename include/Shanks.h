#pragma once

#include "NPC.h"

class Shanks : public NPC
{
public:
	Shanks(const sf::Vector2f& position)
		: NPC(position, Resources::Shanks, "Shanks")
	{}
};