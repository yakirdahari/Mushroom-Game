#pragma once
#include <SFML/Graphics.hpp>
#include "Controller.h"

class GameOver
{
public:
	// Constractor
	GameOver();

	// Public Functions
	void run(sf::RenderWindow& m_window);

private:
	// Members
	int m_windowHeight;
	int m_windowWidth;

	sf::Font titleFont;
	sf::Font buttonsFont;
	sf::Text title;
	sf::Text newGame;
	sf::Text exit;

	// Private Functions
	void draw(sf::RenderWindow& m_window);
	void updateEvents(sf::RenderWindow& m_window);
	void initTitle();
	void initButton();
	
};