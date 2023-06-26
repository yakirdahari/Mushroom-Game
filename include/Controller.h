#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <memory>
#include <ctime>
#include "Player.h"
#include "FileReader.h"
#include "Resources.h"
#include "DebugUtils.h"
#include "Info.h"

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
		WindowWidth = 1366,
		WindowHeight = 768,
	};
	//----------------------
	// Destructor
	~Controller();

private:
	
	// Variables
	sf::RenderWindow m_window;
	sf::RectangleShape m_transitionScreen;
	sf::Clock gameClock;
	sf::Sound m_teleportSound;
	sf::Sprite cursor;
	sf::View m_view;
	sf::View m_GUIview;
	bool m_changingMap;

	// Private Functions
	void draw();              // draws objects
	void handleEvents();
	void updateGameObjects(); // movement
	void updateInfo();
	void handleCollisions(gameObject& gameObject);
	void spawn(const int& mapID);
	void changeMap(const int& mapID, const int& exitPortal);
	void fadeIn();	  // screen fades in when changing maps
	void fadeOut();	  // screen fades out when changing maps
	void checkPortals();      // player on a portal = can change map
	void updateView();		  // moves camera towards player
};