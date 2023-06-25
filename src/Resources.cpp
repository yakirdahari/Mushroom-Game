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
        const auto deathSize = sf::Vector2i(81, 100);
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
        player.m_data[Direction::Dead].emplace_back(nextStart() + sf::Vector2i(-10, 0), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-12,0), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-14,0), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-16,-2), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-18,-4), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-18,-6), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-18,-8), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-16,-10), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-14,-12), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-12,-12), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-10,-12), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-8,-12), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-6,-12), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-4,-10), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-2,-8), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-2,-6), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-2,-4), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-4,-2), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-6, 0), deathSize);
        player.m_data[Direction::Dead].emplace_back(currentStart + sf::Vector2i(-8, 0), deathSize);

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

AnimationData LevelUpData()
{
    const auto size = sf::Vector2i(296, 345);
    const auto initSpace = sf::Vector2i(433, 0);
    const auto middleSpace = sf::Vector2i(0, 0);

    auto LevelUp = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    LevelUp.m_data[Direction::Stay].emplace_back(currentStart, size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);
    LevelUp.m_data[Direction::Stay].emplace_back(nextStart(), size);

    return LevelUp;
}

AnimationData TombstoneData()
{
    const auto size = sf::Vector2i(98, 213);
    const auto initSpace = sf::Vector2i(732, 0);
    const auto middleSpace = sf::Vector2i(0, 0);

    auto Tombstone = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    Tombstone.m_data[Direction::Stay].emplace_back(currentStart, size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Tombstone.m_data[Direction::Stay].emplace_back(nextStart(), size);

    return Tombstone;
}

AnimationData HeenaData()
{
    const auto size = sf::Vector2i(56, 55);
    const auto initSpace = sf::Vector2i(19, 20);
    const auto middleSpace = sf::Vector2i(0, 20);

    auto Heena = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(currentStart, size);
    Heena.m_data[Direction::Stay].emplace_back(nextStart(), size);
    Heena.m_data[Direction::Stay].emplace_back(nextStart(), size);

    return Heena;
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
    loadMusic();
    loadSound();
}

void Resources::loadAnimations()
{
    // load animations
    if (!m_texture.loadFromFile("Animations.png"))
        throw std::runtime_error("Can't load file");

    m_data[Player] = playerData();
    m_data[Mushroom] = MushroomData();
    m_data[Portal] = PortalData();
    m_data[LevelUp] = LevelUpData();
    m_data[Tombstone] = TombstoneData();
    m_data[Heena] = HeenaData();
}

void Resources::loadBackgrounds()
{
    if (!m_backgrounds[MushroomTown].loadFromFile("Background1.png") ||
        !m_backgrounds[SmallForest].loadFromFile("Background1.png")   )
        throw std::runtime_error("Can't load background");
}

void Resources::loadMaps()
{
    if (!m_maps[MushroomTown].loadFromFile("MushroomTown.png") ||
        !m_maps[SmallForest].loadFromFile("SmallForest.png")    )
        throw std::runtime_error("Can't load map");
}

void Resources::loadTextures()
{
    if (!m_textures[MenuBackground].loadFromFile("MenuBackground.jpg")                 ||
        !m_textures[Ground].loadFromFile("Ground.png")                                 ||
        !m_textures[Wall].loadFromFile("Wall.png")                                     ||
        !m_textures[MonsterWall].loadFromFile("MonsterWall.png")                       ||
        !m_textures[Ladder].loadFromFile("Ladder.png")                                 ||
        !m_textures[Rope].loadFromFile("Rope.png")                                     ||
        !m_textures[Panel].loadFromFile("Panel.png")                                   ||
        !m_textures[Revive].loadFromFile("Revive.png")                                 ||
        !m_textures[OK_Button].loadFromFile("OK_Button.png")                           ||
        !m_textures[OK_Button_Highlighted].loadFromFile("OK_Button_Highlighted.png")   ||
        !m_textures[OK_Button_Pressed].loadFromFile("OK_Button_Pressed.png")           ||
        !m_textures[Cursor].loadFromFile("Cursor.png")            )
        throw std::runtime_error("Can't load texture");
}

void Resources::loadMusic()
{
    if (!m_music[MushroomTown].loadFromFile("music1.wav"))
        throw std::runtime_error("Can't load music");
}

void Resources::loadSound()
{
    if (!m_sound[Death_Sound].loadFromFile("death.wav")                  ||
        !m_sound[LevelUp_Sound].loadFromFile("LevelUp.wav")              ||
        !m_sound[QuestClear_Sound].loadFromFile("QuestClear.wav")        ||
        !m_sound[HitSound1].loadFromFile("hitSound1.wav")                ||
        !m_sound[Sword_Sound].loadFromFile("sword.wav")                  ||
        !m_sound[Jump_Sound].loadFromFile("jump.wav")                    ||
        !m_sound[MushroomDeath_Sound].loadFromFile("mushroom_death.wav") ||
        !m_sound[Portal_Sound].loadFromFile("Portal.wav")                 )
        throw std::runtime_error("Can't load sound");
}
