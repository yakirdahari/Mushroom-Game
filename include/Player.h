#pragma once

#include "movingObject.h"


class Player : public movingObject
{
public:
    Player(const sf::Vector2f& position);
    Player(const sf::Vector2f& position, const sf::Vector2f& mapSize,
           const sf::Vector2f& resolution);

    Direction keyToDirection();
    void update(sf::Time delta) override;

private:
    bool m_attack;
    bool m_prone;
    sf::Clock m_attackTime;
};
