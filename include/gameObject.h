#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

using std::string;

class Player;
class Demon;

class gameObject
{
public:

	// Constructors
	gameObject(const sf::Vector2f& position);
	gameObject(const sf::Vector2f& position, const sf::Vector2f& mapSize,
		       const sf::Vector2f& resolution);

	// Public functions
	void setImage(const sf::Texture& texture);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window) const ;
	bool collidesWith(const sf::FloatRect& other) const;
	sf::FloatRect getGlobalBounds() const;
	bool isDeleted() const;
	void remove();

	// Collision Handlers
	
	// Destructor
	virtual ~gameObject() = default;
protected:
	sf::Sprite m_sp;
	bool m_isDeleted;
	sf::Vector2f m_resolution;
};