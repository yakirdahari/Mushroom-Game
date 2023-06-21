#include "Controller.h"


// Opening file
Controller::Controller()
	: m_window(sf::VideoMode(WindowWidth, WindowHeight), "Mushroom Game", sf::Style::Titlebar | sf::Style::Close),
	  m_transitionScreen(sf::Vector2f(WindowWidth, WindowHeight)),
	  player(std::make_unique<Player>(sf::Vector2f(0,0))), m_changingMap(false)
{
	m_window.setFramerateLimit(60);	
	m_transitionScreen.setFillColor(sf::Color::Transparent);
}
//----------------------------------------------------
void Controller::run()
{
	spawn(Map::MushroomTown);

	while (m_window.isOpen())
	{
		draw();
		handleEvents();
		updateGameObjects();
		updateInfo();
	}
	Controller::~Controller();
}
//----------------------------------------------------
void Controller::draw()
{
	m_window.clear();
	if (auto debugSpriteSheet = 0) // use 1 to debug animation data
	{
		displayAll(m_window, Resources::instance().animationData(Resources::Portal));
	}
	else
	{
		m_window.draw(*Map::instance().background());
		m_window.draw(*Map::instance().map());

		for (auto& unmovable : Map::instance().unmovables())
			unmovable->draw(m_window);

		for (auto& movable : Map::instance().movables())
			movable->draw(m_window);

		for (auto& portal : Map::instance().portals())
			portal->draw(m_window);

		player->draw(m_window);
		Info::instance().draw(m_window);
		m_window.draw(m_transitionScreen);
	}
	m_window.display();
}
//----------------------------------------------------
void Controller::handleEvents()
{
	for (auto event = sf::Event{}; m_window.pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				m_window.close();

			if (event.key.code == sf::Keyboard::Up)
				checkPortals();
		}			
	}
}
//----------------------------------------------------
void Controller::updateGameObjects()
{
	const auto delta = gameClock.restart();

	// movement + collision
	player->update(delta);
	player->updatePhysics();
	handleCollisions(*player);
	
	for (auto& movable : Map::instance().movables())
	{
		movable->update(delta);
		handleCollisions(*movable);
		movable->updatePhysics();
	}
	
	for (auto& portal : Map::instance().portals())
		portal->update(delta);

	Map::instance().respawn();
}
//----------------------------------------------------
void Controller::updateInfo()
{
	Info::instance().update(player->getData());
}
//----------------------------------------------------
void Controller::handleCollisions(gameObject& gameObject)
{
	// check collision with movables
	for (auto& movable : Map::instance().movables())
		if (gameObject.collidesWith(movable->getGlobalBounds()))
			gameObject.handleCollision(*movable);

	// check collision with unmovables
	for (auto& unmovable : Map::instance().unmovables())
		if (gameObject.collidesWith(unmovable->getGlobalBounds()))
			gameObject.handleCollision(*unmovable);
}
//----------------------------------------------------
void Controller::spawn(const int& mapID)
{
	// transition screen
	readFile(mapID, player);

	// so we don't fall off the map
	for (auto& movable : Map::instance().movables())
		for (int i = 0; i < 5; i++)
			handleCollisions(*movable);

	for (int i = 0; i < 5; i++)
		handleCollisions(*player);

	fadeOut();

	gameClock.restart();	// unfreeze clock
}
//----------------------------------------------------
void Controller::changeMap(const int& mapID, const int& exitPortal)
{
	m_changingMap = true;

	fadeIn();			// transition screen

	readFile(mapID, player);

	player->setPosition(Map::instance().portals()[exitPortal]->getPosition()); 	// spawn in exit portal
	
	// so we don't fall off the map
	for (auto& movable : Map::instance().movables())
		for (int i=0 ; i<5 ; i++)
			handleCollisions(*movable);

	for (int i=0; i<5; i++)
		handleCollisions(*player);

	fadeOut();			// transition screen

	gameClock.restart();	// unfreeze clock
	handleEvents();
	m_changingMap = false;
}
//----------------------------------------------------
void Controller::fadeIn()
{
	bool fadingIn = true;
	m_transitionScreen.setFillColor(sf::Color::Transparent); // Start with a black screen

	float alpha = 0.f; // Initial alpha value for fading

	while (fadingIn)
	{
		// Apply the alpha value to the screen
		alpha += 5.0f;								// speed of the fade
		sf::Color screenColor = m_transitionScreen.getFillColor();
		screenColor.a = static_cast<sf::Uint8>(alpha);
		m_transitionScreen.setFillColor(screenColor);
		draw();

		if (alpha == 255.f)
			fadingIn = false;
	}
}
//----------------------------------------------------
void Controller::fadeOut()
{
	bool fadingOut = true;
	m_transitionScreen.setFillColor(sf::Color::Black); // Start with a black screen

	float alpha = 255.f; // Initial alpha value for fading

	while (fadingOut)
	{
		// Apply the alpha value to the screen
		alpha -= 5.0f;								// speed of the fade
		sf::Color screenColor = m_transitionScreen.getFillColor();
		screenColor.a = static_cast<sf::Uint8>(alpha);
		m_transitionScreen.setFillColor(screenColor);
		draw();

		if (alpha == 0.f)
			fadingOut = false;
	}
}
//----------------------------------------------------
void Controller::checkPortals()
{
	// when player is on a portal he can change map
	for (auto& portal : Map::instance().portals())
	{
		if (!m_changingMap &&
			player->collidesWith(portal->getGlobalBounds()) &&
			player->getGlobalBounds().left > portal->getGlobalBounds().left &&
			player->getGlobalBounds().left < portal->getGlobalBounds().left + player->getGlobalBounds().width &&
			player->getGlobalBounds().top > portal->getGlobalBounds().top + player->getGlobalBounds().height)
		{
			changeMap(portal->destination(), portal->exitPortal());
		}
	}
}
//----------------------------------------------------
Controller::~Controller()
{
}