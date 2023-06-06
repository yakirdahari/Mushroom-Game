#include "Resources.h"

#include "Direction.h"

#include <stdexcept>

namespace
{
    AnimationData MushroomData()
    {
        const auto size = sf::Vector2i(65, 65);
        const auto initSpace = sf::Vector2i(145, 20);
        const auto middleSpace = sf::Vector2i(0, 20);

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
        const auto size = sf::Vector2i(80, 80);
        const auto initSpace = sf::Vector2i(0, 2);
        const auto middleSpace = sf::Vector2i(0, 20);

        auto player = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };


        player.m_data[Direction::Up].emplace_back(currentStart, size);
        player.m_data[Direction::Up].emplace_back(nextStart(), size);
        player.m_data[Direction::Down].emplace_back(nextStart(), size);
        player.m_data[Direction::Down].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Hit].emplace_back(nextStart(), size);
        player.m_data[Direction::Jump].emplace_back(nextStart(), size);
        player.m_data[Direction::Prone].emplace_back(nextStart(), size);
        player.m_data[Direction::ProneStab].emplace_back(nextStart(), size);
        player.m_data[Direction::ProneStab].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack1].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack1].emplace_back(nextStart(), size);
        player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        player.m_data[Direction::Stay].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack2].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack2].emplace_back(nextStart(), size);
        player.m_data[Direction::Attack2].emplace_back(nextStart(), size);
        player.m_data[Direction::Left].emplace_back(nextStart(), size);
        player.m_data[Direction::Right].emplace_back(currentStart, size);
        player.m_data[Direction::Left].emplace_back(nextStart(), size);
        player.m_data[Direction::Right].emplace_back(currentStart, size);
        player.m_data[Direction::Left].emplace_back(nextStart(), size);
        player.m_data[Direction::Right].emplace_back(currentStart, size);
        player.m_data[Direction::Left].emplace_back(nextStart(), size);
        player.m_data[Direction::Right].emplace_back(currentStart, size);

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
