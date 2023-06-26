#pragma once

#include "Monster.h"

#include <SFML/Graphics.hpp>

constexpr auto MonsterSpeed = 100.f;
constexpr auto HitDuration = 0.6f;

class TutorialJrSentinel : public Monster
{
public:
    using movingObject::handleCollision;

    TutorialJrSentinel(const sf::Vector2f& position)
        : Monster(position, Resources::TutorialJrSentinel, Resources::HitSound1, Resources::MushroomDeath_Sound)
    {
        m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 1.5f, getGlobalBounds().height /  2.f));
        data.name = "Tutorial Jr. Sentinel";
        data.expReward = 0;
        data.level = 1;
        data.damage = 1;

        m_info.setName(data.name);
        m_info.setLevel(data.level);
    }

    void update(sf::Time delta) override
    {
        if (data.HP == 0)
            return death(delta);

        // for smoother knockback
        if (m_hitTime.getElapsedTime().asSeconds() <= HitDuration)
            physics.drag = 0.9f;

        m_info.update(data, m_sp.getPosition());

        // move in a random direction
        int nextDirection = (rand() % 5) + 1;
        if (m_aiTime.getElapsedTime().asSeconds() > nextDirection &&
            m_hitTime.getElapsedTime().asSeconds() > HitDuration && !data.dead)
        {
            physics.drag = 1.12f;       // turn drag back to normal after knockback is done
            m_aiTime.restart();
            m_animation.resetAnimation();

            m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Max));
        }

        m_animation.direction(m_dir);
        m_animation.update(delta);
        m_sp.move(toVector(m_dir) * delta.asSeconds() * MonsterSpeed);
    }
};
