#include "Mushroom.h"

Mushroom::Mushroom(const sf::Vector2f& position)
    : Monster(position, Resources::Mushroom, Resources::HitSound1, Resources::MushroomDeath_Sound)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 1.8f, getGlobalBounds().height / 2.f));
    data.name = "Mushroom";
    data.expReward = 10;
    data.level = 6;

    m_info.setName("Mushroom");
    m_info.setLevel(data.level);
}