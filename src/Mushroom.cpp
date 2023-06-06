#include "Mushroom.h"

Mushroom::Mushroom(const sf::Vector2f& position)
    : Monster(position, Resources::Mushroom)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 1.5f));
}

Mushroom::Mushroom(const sf::Vector2f& position, const sf::Vector2f& mapSize,
    const sf::Vector2f& resolution)
    : Monster(position, mapSize, resolution, Resources::Mushroom)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 1.5f));
}