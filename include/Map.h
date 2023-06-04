#pragma once

#include "movingObject.h"
#include "staticObject.h"
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class Map
{
public:
    enum Maps
    {
        MushroomTown = 1,
    };
    //----------------------
    static Map& instance();

    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    std::vector<std::unique_ptr<movingObject>>& movables() { return m_movables; }
    std::vector<std::unique_ptr<staticObject>>& unmovables() { return m_unmovables; }
    int& mapWidth() { return m_mapWidth; }
    int& mapHeight() { return m_mapHeight; }
    sf::Sprite& background() { return m_background; }
    sf::Sprite& map() { return m_map; }

private:
    Map();
    std::vector<std::unique_ptr<movingObject>> m_movables;
    std::vector<std::unique_ptr<staticObject>> m_unmovables;
    sf::Sprite m_background;
    sf::Sprite m_map;
    int m_mapWidth;
    int m_mapHeight;
};
