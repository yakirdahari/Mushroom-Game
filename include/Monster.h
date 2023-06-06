#pragma once

#include "movingObject.h"

class Monster : public movingObject
{
public:
    Monster(const sf::Vector2f& position, Resources::Objects object);
    Monster(const sf::Vector2f& position, const sf::Vector2f& mapSize,
        const sf::Vector2f& resolution, Resources::Objects object);

    void update(sf::Time delta) override;
};
