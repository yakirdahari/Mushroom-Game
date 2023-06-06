#pragma once

#include "Direction.h"
#include "Animation.h"
#include "movingObject.h"

#include <SFML/Graphics.hpp>

class Monster : public movingObject
{
public:
    Monster(const sf::Vector2f& position);
    Monster(const sf::Vector2f& position, const sf::Vector2f& mapSize,
        const sf::Vector2f& resolution);

    void update(sf::Time delta) override;

private:
    Animation m_animation;
    sf::Clock m_aiTime;
};
