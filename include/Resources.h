#pragma once

#include "AnimationData.h"
#include <SFML/graphics.hpp>
#include <vector>
//#include "Map.h"

class Resources
{
public:
    // ---------------
    enum Objects
    {
        Mushroom,
        Player,
        Portal,
        Max,
    };
    // ---------------
    enum Textures
    {
        MenuBackground,
        Ground,
        Wall,
        MonsterWall,
        Ladder,
        Rope,
    };
    // ---------------
    enum Maps
    {
        Menu,
        MushroomTown,
        SmallForest,
    };
    // ---------------
    static Resources& instance();

    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;

    const sf::Texture& texture() const { return m_texture; }
    const sf::Texture& texture(int i) const { return m_textures[i]; }
    const AnimationData& animationData(Objects object) { return m_data[object]; }
    const std::unordered_map<int, sf::Texture>& backgrounds() const { return m_backgrounds; }
    const std::unordered_map<int, sf::Texture>& maps() const { return m_maps; }
    //const std::unordered_map<int, sf::Sound>& music() const { return m_music; }

private:
    Resources();
    void loadAnimations();
    void loadBackgrounds();
    void loadMaps();
    void loadTextures();
    //void loadMusic();

    sf::Texture m_texture;
    std::unordered_map<int, sf::Texture> m_backgrounds;
    std::unordered_map<int, sf::Texture> m_maps;
    //std::unordered_map<int, sf::Sound> m_music;
    std::vector<sf::Texture> m_textures;
    std::vector<AnimationData> m_data;
};
