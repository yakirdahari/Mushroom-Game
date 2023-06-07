#include "Player.h"

constexpr auto PlayerSpeed = 110.f;
constexpr auto AttackSpeed = 0.8f;
constexpr auto JumpSpeed = 0.2f;

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
                m_sp.setScale(1.f, 1.f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
                    return jump();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    return attack();
                break;
            case sf::Keyboard::Right:
                m_sp.setScale(-1.f, 1.f);
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
            {
                return attack();
            }
            case sf::Keyboard::LAlt:
                return jump();
            }
            m_prone = false;
            return pair.second;
        }
    }
    if (m_prone)
    {
        m_prone = false;
        return Direction::Prone;
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
    if (m_jumpCooldown.getElapsedTime().asSeconds() >= JumpSpeed + 0.5)
    {
        m_jump = true;
        m_jumpCooldown.restart();
        physics.velocity = sf::Vector2f(0, -20);
        updatePhysics();
        switch (m_dir)
        {
        case Direction::Left: return Direction::JumpLeft;
        case Direction::Right: return Direction::JumpRight;
        case Direction::Stay: return Direction::Jump;
        default: return Direction::Jump;
        }
    }
    return m_dir;
}

Player::Player(const sf::Vector2f& position)
    : movingObject(position, Resources::Player),
      m_attack(false), m_prone(false), m_jump(false)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 1.7f, getGlobalBounds().height / 1.5f));
}

void Player::update(sf::Time delta)
{
    if (m_jumpCooldown.getElapsedTime().asSeconds() >= JumpSpeed)
    {
        m_jump = false;
    }

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
    if (!m_jump)
    {
        physics.velocity = sf::Vector2f(0, -1);
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
