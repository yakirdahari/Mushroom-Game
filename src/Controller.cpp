#include "Controller.h"


// Opening file
Controller::Controller()
    : m_window(sf::VideoMode(WindowWidth, WindowHeight), "Mushroom Game", sf::Style::Titlebar | sf::Style::Close),
	  m_level(1), player(std::make_unique<Player>(sf::Vector2f(0,0)))
{
	//m_view.setCenter(855.f, 357.5f);
	m_view.setCenter(855.f, 357.5f);
	m_view.setSize(WindowWidth, WindowHeight);
	m_window.setFramerateLimit(60);
	
}
//----------------------------------------------------
void Controller::run()
{
	readFile(Map::MushroomTown, player);

	while (m_window.isOpen())
	{
		draw();
		handleEvents();
		updateGameObjects();
	}
	Controller::~Controller();
}
//--------------------------------------------------
void Controller::draw()
{
	m_window.clear();
	if (auto debugSpriteSheet = 0) // use 1 to debug animation data
	{
		displayAll(m_window, Resources::instance().animationData(Resources::Player));
	}
	else
	{
		m_window.setView(m_view);
		m_window.draw(Map::instance().background());
		m_window.draw(Map::instance().map());

		for (auto& unmovable : Map::instance().unmovables())
		{
			unmovable->draw(m_window);
		}
		for (auto& movable : Map::instance().movables())
		{
			movable->draw(m_window);
		}
		player->draw(m_window);
	}
	m_window.display();
}
//--------------------------------------------------
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
			{
				m_window.close();
			}
			break;
		}			
	}
}
//--------------------------------------------------
void Controller::updateGameObjects()
{
	const auto delta = gameClock.restart();

	// movement + collision
	player->update(delta);
	handleCollisions(*player);
	player->updatePhysics();
	
	for (auto& movable : Map::instance().movables())
	{
		movable->update(delta);
		handleCollisions(*movable);
		movable->updatePhysics();
	}
}
void Controller::handleCollisions(gameObject& gameObject)
{
	// check collision with movables
	for (auto& movable : Map::instance().movables())
	{
		if (gameObject.collidesWith(movable->getGlobalBounds()))
		{
			gameObject.handleCollision(*movable);
		}
	}

	// check collision with unmovables
	for (auto& unmovable : Map::instance().unmovables())
	{
		if (gameObject.collidesWith(unmovable->getGlobalBounds()))
		{
			gameObject.handleCollision(*unmovable);
		}
	}
}
//--------------------------------------------------
Controller::~Controller()
{
}