#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class Button
{
public:
	Button(const sf::Texture& normal, const sf::Texture& highlighted,
		   const sf::Texture& pressed, const sf::Vector2f& location);

	virtual void draw(sf::RenderWindow& window);
	virtual bool wasClicked(sf::RenderWindow& window);

	virtual ~Button() = default;

protected:
	sf::Sprite m_button;

	sf::Texture m_normal;
	sf::Texture m_highlighted;
	sf::Texture m_pressed;
};