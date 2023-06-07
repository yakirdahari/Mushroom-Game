#include "Mushroom.h"

Mushroom::Mushroom(const sf::Vector2f& position)
    : Monster(position, Resources::Mushroom)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height / 1.5f));
}