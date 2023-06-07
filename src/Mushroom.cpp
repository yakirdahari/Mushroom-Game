#include "Mushroom.h"

Mushroom::Mushroom(const sf::Vector2f& position)
    : Monster(position, Resources::Mushroom)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 1.5f));
}