#include "Map.h"

Map::Map()
	: m_mapWidth(0), m_mapHeight(0), 
	  m_background(std::make_unique<sf::Sprite>(Resources::instance().backgrounds().at(MushroomTown))),
	  m_map(std::make_unique<sf::Sprite>(Resources::instance().maps().at(MushroomTown))),
	  m_mapID(MushroomTown)
{
}

Map& Map::instance()
{
	static Map instance;
	return instance;
}
