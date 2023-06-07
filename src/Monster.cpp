#include "Monster.h"
#include "Ground.h"

constexpr auto MonsterSpeed = 140.f;

Monster::Monster(const sf::Vector2f& position, Resources::Objects object)
    : movingObject(position, object)
{
}

void Monster::update(sf::Time delta)
{
    m_lastPosition = m_sp.getPosition();

    // Each direction is kept for at least 3 seconds
    int nextDirection = (rand() % 5) + 1;
    if (m_aiTime.getElapsedTime().asSeconds() >= nextDirection)
    {
        m_aiTime.restart();
        m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Max));
        if (m_dir == Direction::Left)
        {
            m_sp.setScale(-1.f, 1.f);
        }
        else if (m_dir == Direction::Right)
        {
            m_sp.setScale(1.f, 1.f);
        }
    }
    m_animation.direction(m_dir);
    m_animation.update(delta);
    m_sp.move(toVector(m_dir) * delta.asSeconds() * MonsterSpeed);
}

void Monster::handleCollision(gameObject& gameObject)
{
    // ignore self collision
    if (&gameObject == this) return;

    // use double dispatch to find which object
    gameObject.handleCollision(*this);
}

void Monster::handleCollision(Ground& ground)
{
    if (m_lastPosition.y < ground.getPosition().y - 0.9f)
    {
        physics.velocity = sf::Vector2f(0.f, 0.f);
        m_sp.move(0.f, -1.f);
    }
}

void Monster::handleCollision(Wall& wall)
{
    setPosition(m_lastPosition);
}

void Monster::handleCollision(MonsterWall& monsterWall)
{
    /*if (m_dir == Direction::Left || m_dir == Direction::Right)
    {
        m_sp.move(toVector(opposite(m_dir)));
    }*/
    setPosition(m_lastPosition);
}