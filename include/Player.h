#pragma once

#include <optional>
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Animation.h"
#include "movingObject.h"
#include "Resources.h"


class Player : public movingObject
{
public:
    Player(const sf::Vector2f& position);
    Player(const sf::Vector2f& position, const sf::Vector2f& mapSize,
           const sf::Vector2f& resolution);

    Direction keyToDirection();
    void update(sf::Time delta) override;
    void direction(sf::Keyboard::Key key);

private:
    Animation m_animation;
    bool m_attack;
    sf::Clock m_attackTime;
    int framesLeft;
};
