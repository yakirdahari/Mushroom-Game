#pragma once
#include "Controller.h"
#include <iostream>


class Menu
{
public:
	// Constractor
	Menu();							// Constractor
	~Menu();						// Destractor

	// Public Functions
	void run();						// running the program.

private:
	// Members
	sf::RenderWindow m_window;
	sf::Sprite m_background;
	int m_windowHeight;
	int m_windowWidth;

	// Texts
	sf::Font titleFont;
	sf::Font buttonsFont;
	sf::Text title;
	sf::Text start;
	sf::Text help;
	sf::Text exit;

	// Private Functions
	void draw();					// Draws the objects on the screen.
	void updateEvents();			// Handles screen events.
	void initTitle();				// Creates the title.
	void initButtons();				// Creates the buttons.
};