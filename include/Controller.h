#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <memory>
#include <ctime>
#include "Player.h"
#include "GameOver.h"
#include "Victory.h"
#include "Map.h"
#include "FileReader.h"
#include "Resources.h"
#include "DebugUtils.h"

class Controller
{
public:
	// Constructor
	Controller();

	// Public Functions
	void run();

	//----------------------
	enum Settings
	{
		WindowWidth = 1710,
		WindowHeight = 715,
	};
	//----------------------
	// Destructor
	~Controller();

private:
	
	// Variables
	sf::RenderWindow m_window;
	std::unique_ptr<Player> player;
	sf::Clock gameClock;
	int m_level;

	sf::View m_view;

	// Private Functions
	void draw();         // draws objects
	void handleEvents();
	void updateGameObjects();  // movement
	void handleCollisions(gameObject& gameObject);

};