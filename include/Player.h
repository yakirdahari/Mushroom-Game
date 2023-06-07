#pragma once

#include "movingObject.h"

class Player : public movingObject
{
public:
    using movingObject::handleCollision;

    Player(const sf::Vector2f& position);

    Direction keyToDirection();
    Direction attack();
    Direction jump();
    void update(sf::Time delta) override;

    // Collision Handlers
    void handleCollision(gameObject& gameObject);
    void handleCollision(Player& player) override {};   // ignore another player
    void handleCollision(Monster& monster) override;
    void handleCollision(Ground& ground) override;
    void handleCollision(Wall& wall) override;
    void handleCollision(MonsterWall& monsterWall) override {};    // ignore
    /*virtual void handleCollision(Ladder& ladder);
    virtual void handleCollision(Rope& rope);*/

private:
    bool m_attack;
    bool m_prone;
    bool m_jump;
    sf::Clock m_attackTime;
    sf::Clock m_jumpCooldown;
};