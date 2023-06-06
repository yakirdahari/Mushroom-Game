#include "Player.h"

constexpr auto PlayerSpeed = 110.f;
constexpr auto AttackSpeed = 0.8f;

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
                break;
            case sf::Keyboard::Right:
                m_sp.setScale(-1.f, 1.f);
                break;
            case sf::Keyboard::Up:
                break;
            case sf::Keyboard::Down:
                m_prone = true;
                continue;
            case sf::Keyboard::LControl:
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

Player::Player(const sf::Vector2f& position)
    : movingObject(position, Resources::Player),
      m_attack(false), m_prone(false)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 1.7f, getGlobalBounds().height / 1.5f));
}

Player::Player(const sf::Vector2f& position, const sf::Vector2f& mapSize,
               const sf::Vector2f& resolution)
    : movingObject(position, mapSize, resolution, Resources::Player),
      m_attack(false), m_prone(false)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 1.7f, getGlobalBounds().height / 1.5f));
}

void Player::update(sf::Time delta)
{
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
