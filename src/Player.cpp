#include "Player.h"

constexpr auto PlayerSpeed = 80.f;
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
        { sf::Keyboard::Down,  Direction::Down },
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
                break;
            case sf::Keyboard::LControl:
            {
                m_attack = true;
                m_attackTime.restart();
                int attackType = rand() % 2;
                if (attackType == 0)
                {
                    return Direction::Attack1;
                }
                return Direction::Attack2;
            }
            break;
            }
            return pair.second;
        }
    }
    return Direction::Stay;
}

Player::Player(const sf::Vector2f& position)
    : movingObject(position),
      m_animation(Resources::instance().animationData(Resources::Player), Direction::Stay, m_sp),
      m_attack(false), framesLeft(3)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 1.5f));
}

Player::Player(const sf::Vector2f& position, const sf::Vector2f& mapSize,
               const sf::Vector2f& resolution)
    : movingObject(position, mapSize, resolution), 
      m_animation(Resources::instance().animationData(Resources::Player), Direction::Stay, m_sp),
      m_attack(false), framesLeft(3)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 4.f, getGlobalBounds().height / 1.5f));
}

void Player::update(sf::Time delta)
{
    // can't move during attack
    if (m_attackTime.getElapsedTime().asSeconds() >= AttackSpeed)
    {
        m_attack = false;

        // check for key input
        m_dir = keyToDirection();
    }
    // move & animate player
    m_animation.direction(m_dir);
    m_animation.update(delta);
    m_sp.move(toVector(m_dir) * delta.asSeconds() * PlayerSpeed);   
}

void Player::direction(sf::Keyboard::Key key)
{
    /*if (auto dir = toDirection(key))
    {
        m_dir = *dir;

        if (m_dir == Direction::Right)
        {
            m_sp.setScale(-1.f, 1.f);
        }
        else if (m_dir == Direction::Left)
        {
            m_sp.setScale(1.f, 1.f);
        }
        m_animation.direction(*dir);
    }*/
}

