#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

using std::string;

class Player;
class Monster;
class Ground;
class Wall;
class MonsterWall;
class Ladder;
class Rope;

class gameObject
{
public:
	// Constructors
	gameObject(const sf::Vector2f& position);
	gameObject(const sf::Vector2f& position, const sf::Texture& texture);

	// Public functions
	void setImage(const sf::Texture& texture);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window) const ;
	bool collidesWith(const sf::FloatRect& other) const;
	sf::FloatRect getGlobalBounds() const;
	bool isDeleted() const;
	void remove();

	// Collision Handlers (double dispatch)
	virtual void handleCollision(gameObject& gameObject) = 0;
	virtual void handleCollision(Player& player) = 0;
	virtual void handleCollision(Monster& monster) = 0;
	virtual void handleCollision(Ground& ground) = 0;
	//virtual void handleCollision(Wall& wall) = 0;
	//virtual void handleCollision(MonsterWall& monsterWall) = 0;
	//virtual void handleCollision(Ladder& ladder) = 0;
	//virtual void handleCollision(Rope& rope) = 0;

	// Destructor
	virtual ~gameObject() = default;
protected:
	sf::Sprite m_sp;
	bool m_isDeleted;
	sf::Vector2f m_resolution;
};