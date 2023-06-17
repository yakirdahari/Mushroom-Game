#include "Player.h"
#include "Ground.h"
#include "Wall.h"
#include "Ladder.h"

constexpr auto PlayerSpeed = 160.f;
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
        { sf::Keyboard::Up,    Direction::Stay },
        { sf::Keyboard::Down,  Direction::Prone},
        { sf::Keyboard::LControl,  Direction::Attack1 },
        { sf::Keyboard::LAlt,  Direction::Jump },
    };

    for (const auto& pair : keyToDirectionMapping)
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            m_prone = false;
            switch (pair.first)
            {
            case sf::Keyboard::Left: return left();
            case sf::Keyboard::Right: return right();
            case sf::Keyboard::Up: return up();
            case sf::Keyboard::Down: return prone();
            case sf::Keyboard::LControl: return attack();
            case sf::Keyboard::LAlt: return jump();
            } 
            return pair.second;
        }
    }
    if (m_climbLadder)
    {
        return Direction::Ladder;
    }
    if (m_jump)
        return Direction::Jump;
    /*if (m_prone)
    {
        return Direction::Prone;
    }*/
    if (m_attack && m_dir == Direction::Stay)
    {
        m_attack = false;
    }
    return Direction::Stay;
}

Direction Player::attack()
{
    // cannot attack while climbing
    if (m_climbLadder || m_climbRope || m_jump)
    {
        return m_dir;
    }

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
    // jump left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_climbLadder = m_climbRope = false;
        m_sp.setScale(-1.f, 1.f);
        physics.velocity = sf::Vector2f(0, -8);
        updatePhysics();
        m_jump = true;
        m_jumpCooldown.restart();
        return Direction::JumpLeft;
    }    
    // jump right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_climbLadder = m_climbRope = false;
        m_sp.setScale(1.f, 1.f);
        physics.velocity = sf::Vector2f(0, -8);
        updatePhysics();
        m_jump = true;
        m_jumpCooldown.restart();
        return Direction::JumpRight;
    }
    // jump down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !m_climbLadder && !m_climbRope)
    {
        m_sp.move(0.f, 20.f);
        physics.velocity = physics.velocity = sf::Vector2f(0.f, -1.f);
        updatePhysics();
        m_jump = true;
        m_jumpCooldown.restart();
        return Direction::Jump;
    }
    // jump
    if (!m_climbLadder && !m_climbRope)
    {
        physics.velocity = sf::Vector2f(0, -8);
        updatePhysics();
        m_jump = true;
        m_jumpCooldown.restart();
        return Direction::Jump;
    }
    return m_dir;
}

Direction Player::left()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        return jump();

    // cannot move while climbing
    if (m_climbLadder)
        return Direction::Ladder;
    if (m_climbRope)
        return Direction::Rope;

    // change player's direction to the left
    m_sp.setScale(-1.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        return attack();
    return Direction::Left;
}

Direction Player::right()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        return jump();

    // cannot move while climbing
    if (m_climbLadder)
        return Direction::Ladder;
    if (m_climbRope)
        return Direction::Rope;

    // change player's direction to the right
    m_sp.setScale(1.f, 1.f);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        return attack();
    return Direction::Right;
}

Direction Player::up()
{
    if (m_climbLadder)
        return Direction::LadderUp;
    if (m_climbRope)
        return Direction::RopeUp;
    return Direction::Stay;
}

Direction Player::prone()
{
    if (m_climbLadder)
        return Direction::LadderDown;
    if (m_climbRope)
        return Direction::RopeDown;
    m_prone = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        return jump();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        return attack();
    return Direction::Prone;
}

Player::Player(const sf::Vector2f& position)
    : movingObject(position, Resources::Player),
      m_attack(false), m_prone(false), m_jump(false), m_climbLadder(false), m_climbRope(false)
{
    m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height / 2.f));
}

void Player::update(sf::Time delta)
{
    m_lastPosition = m_sp.getPosition();

    // can't move during attack/jump
    if (m_attackTime.getElapsedTime().asSeconds() >= AttackSpeed && !m_jump)
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
    // m_lastPosition.y < ground.getPosition().y - 23.f
    if (m_sp.getPosition().y < ground.getPosition().y - 10.f &&
        physics.velocity.y > -0.41f)
    {
        m_climbLadder = m_climbRope = false;
        physics.velocity = sf::Vector2f(0.f, 0.f);
        m_sp.move(0.f, -0.8f);

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            m_jump = false;

        // avoid stuck animations while holding down button
        if (m_jump)
        {
            m_dir = Direction::Prone;
            m_animation.direction(m_dir);
        }
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
        m_sp.move(0.8f, 0.f);
    }
}

void Player::handleCollision(Ladder& ladder)
{
    // check if player is close
    if (m_lastPosition.x < ladder.getPosition().x - 10.f ||
        m_lastPosition.x > ladder.getPosition().x + 10.f)
        return;

    // climb up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        m_sp.getPosition().y > ladder.getPosition().y + 5.f)
    {
        if (!m_climbLadder)
        {
            m_climbLadder = true;
            m_jump = false;
            m_attack = false;
            m_sp.setPosition(ladder.getPosition().x, m_sp.getPosition().y - 5.f);
        }
        physics.velocity = sf::Vector2f(0.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (!m_climbLadder)
        {
            m_climbLadder = true;
            m_jump = false;
            m_attack = false;
            m_sp.setPosition(ladder.getPosition().x, m_sp.getPosition().y + 5.f);
        }
        physics.velocity = sf::Vector2f(0.f, -0.4f);
    }
    else if (m_climbLadder)
    {
        physics.velocity = sf::Vector2f(0.f, -0.8f);
    }
}

//void Player::handleCollision(Rope& rope)
//{
//    m_dir = Direction::Rope;
//    m_animation.direction(m_dir);
//}
