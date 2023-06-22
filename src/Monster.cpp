#include "Monster.h"
#include "Ground.h"
#include "MonsterWall.h"
#include "Wall.h"
#include "Info.h"

constexpr auto MonsterSpeed = 140.f;
constexpr auto HitDuration = 0.6f;
constexpr auto deathAnimationTime = 0.5f;


Monster::Monster(const sf::Vector2f& position, Resources::Objects object)
    : movingObject(position, object),
      m_info(data)
{
    physics.knockback = { 4.f, 4.f };
}

void Monster::update(sf::Time delta)
{
    // for smoother knockback
    if (m_hitTime.getElapsedTime().asSeconds() <= HitDuration)
        physics.drag = 0.9f;

    // dead = disappear
    if (dead && m_deathTime.getElapsedTime().asSeconds() >= deathAnimationTime)
        death();

    m_info.update(data, m_sp.getPosition());

    // move in a random direction
    int nextDirection = (rand() % 5) + 1;
    if (m_aiTime.getElapsedTime().asSeconds() > nextDirection &&
        m_hitTime.getElapsedTime().asSeconds() > HitDuration)
    {
        physics.drag = 1.12f;       // turn drag back to normal after knockback is done
        m_aiTime.restart();
        m_animation.resetAnimation();

        m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Max));
        if (m_dir == Direction::Left)
            m_sp.setScale(-1.f, 1.f);

        if (m_dir == Direction::Right)
            m_sp.setScale(1.f, 1.f);
    }

    m_animation.direction(m_dir);
    m_animation.update(delta);
    m_sp.move(toVector(m_dir) * delta.asSeconds() * MonsterSpeed);
}

void Monster::death()
{
    m_sp.setPosition(10000, 10000);
    m_dir == Direction::Stay;
    dead = false;   // get ready to respawn
    data.wasHit = false;
}

void Monster::drawInfo(sf::RenderWindow& window)
{
    m_info.draw(window);
}

void Monster::handleCollision(gameObject& gameObject)
{
    // ignore self collision
    if (&gameObject == this) return;

    // use double dispatch to find which object
    gameObject.handleCollision(*this);
}

void Monster::handleCollision(Player& player)
{
    if (!dead && !player.getData().wasHit && !player.isAttacking() &&
        player.getGlobalBounds().left > m_sp.getGlobalBounds().left - 50.f &&
        player.getGlobalBounds().left < m_sp.getGlobalBounds().left + m_sp.getGlobalBounds().width - 18.f &&
        player.getGlobalBounds().top + player.getGlobalBounds().height < m_sp.getGlobalBounds().top + m_sp.getGlobalBounds().height + 50.f &&
        player.getGlobalBounds().top + player.getGlobalBounds().height > m_sp.getGlobalBounds().top + m_sp.getGlobalBounds().height - 50.f)
    {
        const int& damage = randomDamage();

        player.wasHit(damage, m_sp.getScale());

        Info::instance().showDamage("Monster", damage, sf::Vector2f(player.getGlobalBounds().left, player.getGlobalBounds().top));
    }
}

void Monster::handleCollision(Ground& ground)
{
    if (m_sp.getPosition().y < ground.getPosition().y -5.f &&
        physics.velocity.y > -0.41f)
    {
        physics.velocity = sf::Vector2f(0.f, 0.f);
        m_sp.move(0.f, -0.8f);
    }
}

void Monster::handleCollision(Wall& wall)
{
    if (m_sp.getPosition().x < wall.getPosition().x)
    {
        m_sp.move(-0.7f, 0.f);
    }
    else
    {
        m_sp.move(0.7f, 0.f);
    }
}

void Monster::handleCollision(MonsterWall& monsterWall)
{
    if (m_sp.getPosition().x < monsterWall.getPosition().x)
    {
        m_sp.move(-0.7f, 0.f);
    }
    else
    {
        m_sp.move(0.7f, 0.f);
    }
}