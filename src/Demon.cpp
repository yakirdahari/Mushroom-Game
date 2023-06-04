#include "Demon.h"

#include "Resources.h"

constexpr auto DemonSpeed = 80.f;

Demon::Demon(const sf::Vector2f& position)
    : movingObject(position),
      m_animation(Resources::instance().animationData(Resources::RedDemon), Direction::Right, m_sp)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 2.f));
}

Demon::Demon(const sf::Vector2f& position, const sf::Vector2f& mapSize,
             const sf::Vector2f& resolution)
    : movingObject(position, mapSize, resolution),
      m_animation(Resources::instance().animationData(Resources::RedDemon), Direction::Right, m_sp)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 2.f));
}

void Demon::update(sf::Time delta)
{
    // Each direction is kept for at least 3 seconds
    int nextDirection = (rand() % 5) + 1;
    if (m_aiTime.getElapsedTime().asSeconds() >= nextDirection)
    {
        m_aiTime.restart();
        m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Max));
        if (m_dir == Direction::Left)
        {
            m_sp.setScale(1.f, 1.f);
        }
        else if (m_dir == Direction::Right)
        {
            m_sp.setScale(-1.f, 1.f);
        }
    }
    m_animation.direction(m_dir);
    m_animation.update(delta);
    m_sp.move(toVector(m_dir) * delta.asSeconds() * DemonSpeed);
}
