#pragma once

#include "AnimationData.h"
#include <SFML/graphics.hpp>
#include <vector>

class Resources
{
public:
    // ---------------
    enum Objects
    {
        Mushroom,
        Player,
        Max,
    };
    // ---------------
    enum Textures
    {
        MenuBackground,
        Background1,
        MushroomTown,
        Ground,
        Wall,
        MonsterWall,
        Ladder,
        Rope,
    };
    // ---------------
    static Resources& instance();

    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;

    const sf::Texture& texture() const { return m_texture; }
    const sf::Texture& texture(int i) const { return m_textures[i]; }
    const AnimationData& animationData(Objects object) { return m_data[object]; }

private:
    Resources();
    sf::Texture m_texture;
    std::vector<sf::Texture> m_textures;
    std::vector<AnimationData> m_data;
};
