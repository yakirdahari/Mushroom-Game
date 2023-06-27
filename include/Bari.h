#pragma once

#include "NPC.h"

class Bari : public NPC
{
public:
	Bari(const sf::Vector2f& position)
		: NPC(position, Resources::Bari, "Bari")
	{}
};