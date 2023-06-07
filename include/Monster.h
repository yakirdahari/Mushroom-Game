#pragma once

#include "movingObject.h"

class Monster : public movingObject
{
public:
    using movingObject::handleCollision;

    Monster(const sf::Vector2f& position, Resources::Objects object);

    void update(sf::Time delta) override;

    // Collision Handlers
    void handleCollision(gameObject& gameObject);
    void handleCollision(Player& player) override {};   // ignore another player
    void handleCollision(Monster& monster) override {}; // ignore another monster
    void handleCollision(Ground& ground) override;
    //virtual void handleCollision(Ladder& ladder) {};
    //virtual void handleCollision(Rope& rope) {};
    //void handleCollision(MonsterWall& monsterWall) override;
};
