#include "Player.h"
#include "Ground.h"
#include "Wall.h"

constexpr auto PlayerSpeed = 140.f;
constexpr auto AttackSpeed = 0.8f;
constexpr auto JumpSpeed = 0.5f;

Direction Player::keyToDirection()
{
    static const
        std::initializer_list<std::pair<sf::Keyboard::Key, Direction>>
        keyToDirectionMapping =
    {
        { sf::Keyboard::Right, Direction::Right },
        { sf::Keyboard::Left,  Direction::Left },
        { sf::Keyboard::Up,    Direction::Up },
        { sf::Keyboard::Down,  Direction::Prone},
        { sf::Keyboard::LControl,  Direction::Attack1 },
        { sf::Keyboard::LAlt,  Direction::Jump },
    };

    for (const auto& pair : keyToDirectionMapping)
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            switch (pair.first)
            {
            case sf::Keyboard::Left:
                m_sp.setScale(-1.f, 1.f);
                if (m_jump)
                    return Direction::JumpLeft;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
                    return jump();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    return attack();
                break;
            case sf::Keyboard::Right:
                if (m_jump)
                    return Direction::JumpRight;
                m_sp.setScale(1.f, 1.f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
                    return jump();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    return attack();
                break;
            case sf::Keyboard::Up:
                break;
            case sf::Keyboard::Down:
                m_prone = true;
                continue;
            case sf::Keyboard::LControl:
                return attack();
            case sf::Keyboard::LAlt:
                return jump();
            }
            m_prone = false;
            return pair.second;
        }
    }
    if (m_jump)
        return Direction::Jump;
    if (m_prone)
    {
        m_prone = false;
        return Direction::Prone;
    }
    if (m_attack && m_dir == Direction::Stay)
    {
        m_attack = false;
    }
    return Direction::Stay;
}

Direction Player::attack()
{
    m_attack = true;
    m_attackTime.restart();
    m_animation.resetAnimation();

    if (m_prone)
    {
        return Direction::ProneStab;
    }

    int attackType = rand() % 2;
    if (attackType == 0)
    {
        return Direction::Attack1;
    }
    return Direction::Attack2;
}

Direction Player::jump()
{
    if (m_jumpCooldown.getElapsedTime().asSeconds() >= JumpSpeed && !m_jump)
    {
        m_jump = true;
        m_jumpCooldown.restart();
        physics.velocity = sf::Vector2f(0, -16);
        updatePhysics();

        // check direction of jump (can't change mid-jump)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return Direction::JumpLeft;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            return Direction::JumpRight;
        return Direction::Jump;
    }
    return m_dir;
}

Player::Player(const sf::Vector2f& position)
    : movingObject(position, Resources::Player),
      m_attack(false), m_prone(false), m_jump(false)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height / 2.f));
}

void Player::update(sf::Time delta)
{
    m_lastPosition = m_sp.getPosition();

    // can't move during attack
    if (m_attackTime.getElapsedTime().asSeconds() >= AttackSpeed)
    {
        m_dir = keyToDirection();   // check for key input
    }

    // animate & move player
    m_animation.direction(m_dir);
    m_animation.update(delta);
    m_sp.move(toVector(m_dir) * delta.asSeconds() * PlayerSpeed);
}

sf::Vector2f Player::getPosition() const
{
    return sf::Vector2f();
}

void Player::handleCollision(gameObject& gameObject)
{
    // ignore self collision
    if (&gameObject == this) return;

    // use double dispatch to find which object
    gameObject.handleCollision(*this);
}

void Player::handleCollision(Monster& monster)
{
    // -HP
    m_dir = Direction::Hit;
    m_animation.direction(m_dir);
    m_attackTime.restart();
}

void Player::handleCollision(Ground& ground)
{
    if (m_lastPosition.y < ground.getPosition().y - 12.f)
    {
        m_jump = false;
        physics.velocity = sf::Vector2f(0.f, 0.f);
        m_sp.move(0.f, -0.8f);
    }
}

void Player::handleCollision(Wall& wall)
{
    if (m_lastPosition.x < wall.getPosition().x)
    {
        m_sp.move(-0.8f, 0.f);
    }
    else
    {
        m_sp.move(-0.8f, 0.f);
    }
}

//void Player::handleCollision(Ladder& ladder)
//{
//    m_dir = Direction::Ladder;
//    m_animation.direction(m_dir);
//}
//
//void Player::handleCollision(Rope& rope)
//{
//    m_dir = Direction::Rope;
//    m_animation.direction(m_dir);
//}
