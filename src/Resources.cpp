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
        player.m_data[Direction::Hit].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Hit].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Hit].emplace_back(nextStart(), walkSize);
        player.m_data[Direction::Hit].emplace_back(nextStart(), walkSize);
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

AnimationData PortalData()
{
    const auto size = sf::Vector2i(87, 262);
    const auto initSpace = sf::Vector2i(330, 0);
    const auto middleSpace = sf::Vector2i(0, 14);

    auto Portal = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    Portal.m_data[Direction::Stay].emplace_back(currentStart, size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Portal.m_data[Direction::Stay].emplace_back(nextStart(), size);

    return Portal;
}

Resources& Resources::instance()
{
    static Resources instance;
    return instance;
}

Resources::Resources()
    : m_data(Max)
{
    loadAnimations();
    loadBackgrounds();
    loadMaps();
    loadTextures();

    m_data[Player] = playerData();
    m_data[Mushroom] = MushroomData();
    m_data[Portal] = PortalData();
}

void Resources::loadAnimations()
{
    // load animations
    if (!m_texture.loadFromFile("Animations.png"))
        throw std::runtime_error("Can't load file");
}

void Resources::loadBackgrounds()
{
    sf::Texture texture;

    if (!texture.loadFromFile("Background1.png"))
        throw std::runtime_error("Can't load file");

    m_backgrounds[MushroomTown] = texture;
    m_backgrounds[SmallForest] = texture;
}

void Resources::loadMaps()
{
    if (!m_maps[MushroomTown].loadFromFile("MushroomTown.png"))
        throw std::runtime_error("Can't load file");

    if (!m_maps[SmallForest].loadFromFile("SmallForest.png"))
        throw std::runtime_error("Can't load file");
}

void Resources::loadTextures()
{
    sf::Texture texture;

    if (!texture.loadFromFile("MenuBackground.jpg"))
        throw std::runtime_error("Can't load file");

    m_textures.push_back(texture);

    if (!texture.loadFromFile("Ground.png"))
        throw std::runtime_error("Can't load file");

    m_textures.push_back(texture);

    if (!texture.loadFromFile("Wall.png"))
        throw std::runtime_error("Can't load file");

    m_textures.push_back(texture);

    if (!texture.loadFromFile("MonsterWall.png"))
        throw std::runtime_error("Can't load file");

    m_textures.push_back(texture);

    if (!texture.loadFromFile("Ladder.png"))
        throw std::runtime_error("Can't load file");

    m_textures.push_back(texture);

    if (!texture.loadFromFile("Rope.png"))
        throw std::runtime_error("Can't load file");

    m_textures.push_back(texture);
}
