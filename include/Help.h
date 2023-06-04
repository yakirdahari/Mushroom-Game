#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Help
{
public:
	// Constractor
	Help();

	// Public Functions
	void run(sf::RenderWindow& m_window);

private:
	// Members
	float m_windowHeight;
	float m_windowWidth;

	sf::Font titleFont;
	sf::Font buttonsFont;
	sf::Text title;
	sf::Text back;

	sf::Text row1;
	sf::Text row2;
	sf::Text row3;
	sf::Text row4;
	sf::Text row5;

	// Private Functions
	void draw(sf::RenderWindow& m_window);
	void updateEvents(sf::RenderWindow& m_window);
	void initTitle();
	void initButton();
	void initInstructions();

};