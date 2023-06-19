#include "Map.h"

Map::Map()
	: m_mapWidth(0), m_mapHeight(0), 
	  m_background(std::make_unique<sf::Sprite>(Resources::instance().backgrounds().at(MushroomTown))),
	  m_map(std::make_unique<sf::Sprite>(Resources::instance().maps().at(MushroomTown))),
	  m_mapID(MushroomTown)
{
}

void Map::respawn()
{
	// respawns movables every set interval
	if (respawnTime.getElapsedTime().asSeconds() >= 14.f)
	{
		respawnTime.restart();

		for (auto& movable : m_movables)
			if (movable->isDead())
				movable->respawn();
	}
}

Map& Map::instance()
{
	static Map instance;
	return instance;
}
