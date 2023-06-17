#include "Resources.h"

#include "Direction.h"

#include <stdexcept>

namespace
{
    AnimationData MushroomData()
    {
        const auto size = sf::Vector2i(65, 71);
        const auto initSpace = sf::Vector2i(116, 20);
        const auto middleSpace = sf::Vector2i(0, 14);

        auto Mushroom = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };

        Mushroom.m_data[Direction::Dead].emplace_back(currentStart, size);
        Mushroom.m_data[Direction::Dead].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Dead].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Hit].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Jump].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Left].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Right].emplace_back(currentStart, size);
        Mushroom.m_data[Direction::Left].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Right].emplace_back(currentStart, size);
        Mushroom.m_data[Direction::Left].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Right].emplace_back(currentStart, size);
        Mushroom.m_data[Direction::Stay].emplace_back(nextStart(), size);
        Mushroom.m_data[Direction::Stay].emplace_back(nextStart(), size);

        return Mushroom;
    }

    AnimationData playerData()
    {
        const auto walkSize = sf::Vector2i(61, 80);
        const auto size = sf::Vector2i(95, 80);
        const auto initSpace = sf::Vector2i(232, 2);
        const auto middleSpace = sf::Vector2i(0, 20);

        auto player = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };


        player.m_data[Direction::Ladder].emplace_back(currentStart, size);
        player.m_data[Direction::LadderUp].emplace_back(currentStart, size);
        player.m_data[Direction::LadderDown].emplace_back(currentStart, size);
        player.m_data[Direction::LadderUp].emplace_back(nextStart(), size);
        player.m_data[Direction::LadderDown].emplace_back(currentStart, size);
        player.m_data[Direction::Rope].emplace_back(nextStart(), size);
        player.m_data[Direction::RopeUp].emplace_back(currentStart, size);
        player.m_data[Direction::RopeDown].emplace_back(currentStart, size);
        player.m_data[Direction::RopeUp].emplace_back(nextStart(), size);
        player.m_data[Direction::RopeDown].emplace_back(currentStart, size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Jump].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::JumpLeft].emplace_back(currentStart, walkSize);
        player.m_data[Direction::JumpRight].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Prone].emplace_back(nextStart(), size);
        player.m_data[Direction::ProneStab].emplace_back(nextStart(), size);
        player.m_data[Direction::ProneStab].emplace_back(nextStart(), size);
        player.m_data[Direction::ProneStab].emplace_back(currentStart, size);
        player.m_data[Direction::ProneStab].emplace_back(currentStart, size);
        player.m_data[Direction::ProneStab].emplace_back(currentStart, size);
        player.m_data[Direction::Attack1].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack1].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack1].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack1].emplace_back(currentStart, size);
        player.m_data[Direction::Attack1].emplace_back(currentStart, size);
        player.m_data[Direction::Stay].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Stay].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Stay].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Stay].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Stay].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Stay].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Stay].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Stay].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Attack2].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack2].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack2].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack2].emplace_back(currentStart, size);
        player.m_data[Direction::Attack2].emplace_back(currentStart, size);
        player.m_data[Direction::Left].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Right].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Left].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Right].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Left].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Right].emplace_back(currentStart, walkSize);
        player.m_data[Direction::Left].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Right].emplace_back(currentStart, walkSize);

        return player;
    }
}

Resources& Resources::instance()
{
    static Resources instance;
    return instance;
}

Resources::Resources()
    : m_data(Max)
{
    sf::Texture texture;

    if (!m_texture.loadFromFile("Animations.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    
    // load textures to vector
    if (!texture.loadFromFile("MenuBackground.jpg"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("Background1.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("Map1.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("Ground.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("Wall.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("MonsterWall.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("Ladder.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    if (!texture.loadFromFile("Rope.png"))
    {
        throw std::runtime_error("Can't load file");
    }
    m_textures.push_back(texture);

    m_data[Player] = playerData();
    m_data[Mushroom] = MushroomData();
}
