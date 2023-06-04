#include "Map.h"

Map::Map()
	: m_mapWidth(0), m_mapHeight(0), m_background(Resources::instance().texture(1)),
	                                        m_map(Resources::instance().texture(2))
{
}

Map& Map::instance()
{
	static Map instance;
	return instance;
}
