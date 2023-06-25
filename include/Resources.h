#pragma once

#include "AnimationData.h"
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Resources
{
public:
    // ---------------
    enum Objects
    {
        Mushroom,
        Player,
        Portal,
        LevelUp,
        Tombstone,
        Heena,
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
        Panel,
        Revive,
        OK_Button,
        OK_Button_Highlighted,
        OK_Button_Pressed,
        Cursor,
    };
    // ---------------
    enum Maps
    {
        Menu,
        MushroomTown,
        SmallForest,
    };
    // ---------------
    enum Sound
    {
        Death_Sound,
        LevelUp_Sound,
        QuestClear_Sound,
        HitSound1,
        Sword_Sound,
        Jump_Sound,
        MushroomDeath_Sound,
        Portal_Sound,
    };

    static Resources& instance();

    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;

    const sf::Texture& texture() const { return m_texture; }
    const sf::Texture& texture(int i) const { return m_textures.at(i); }
    const sf::Texture& backgrounds(int i) const { return m_backgrounds.at(i); }
    const sf::Texture& maps(int i) const { return m_maps.at(i); }
    const sf::SoundBuffer& music(int i) const { return m_music.at(i); }
    const sf::SoundBuffer& sound(int i) const { return m_sound.at(i); }
    const AnimationData& animationData(Objects object) { return m_data[object]; }

private:
    Resources();
    void loadAnimations();
    void loadBackgrounds();
    void loadMaps();
    void loadTextures();
    void loadMusic();
    void loadSound();

    sf::Texture m_texture;
    std::unordered_map<int, sf::Texture> m_textures;
    std::unordered_map<int, sf::Texture> m_backgrounds;
    std::unordered_map<int, sf::Texture> m_maps;
    std::unordered_map<int, sf::SoundBuffer> m_music;
    std::unordered_map<int, sf::SoundBuffer> m_sound;
    std::vector<AnimationData> m_data;
};
