#include "Controller.h"


// Opening file
Controller::Controller()
    : m_window(sf::VideoMode(WindowWidth, WindowHeight), "Pacman", sf::Style::Close),
	  m_level(1), player(std::make_unique<Player>(sf::Vector2f(0,0)))
{
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
		//displayAll(m_window, Resources::instance().animationData(Resources::RedDemon));
	}
	else
	{
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

	for (auto& movable : Map::instance().movables())
	{
		movable->update(delta);
	}
}
//--------------------------------------------------
Controller::~Controller()
{
}
//--------------------------------------------------
//void Controller::readFile(int mapNumber)
//{
//	std::ifstream m_file;
//	m_file.open("Board.txt");
//
//	if (!m_file.is_open())
//	{
//		throw std::exception("Error loading board.txt");
//	}
//
//	std::vector<string> map;
//
//	// check if no more levels
//	if (mapNumber == 4)
//	{
//		Controller::~Controller();
//	}
//
//	for (int currentMap = 1; currentMap <= mapNumber; currentMap++)
//	{
//		// clear existing map
//		map.clear();
//		m_movables.clear();
//		m_unmovables.clear();
//
//		// read height, width
//		string line;
//		m_file >> line;
//		m_mapHeight = stoi(line);
//		std::getline(m_file, line);
//		m_mapWidth = stoi(line);
//		std::getline(m_file, line);
//
//		// put each line in map vector
//		for (int i = 0; i < m_mapHeight; i++)
//		{
//			std::getline(m_file, line);
//			map.push_back(line);
//		}
//
//		// eat space between maps
//		std::getline(m_file, line);
//
//		// skip maps till reached wanted map
//		if (currentMap != mapNumber)
//		{
//			continue;
//		}
//
//		// check if map is valid
//		if (!isValid(map))
//		{
//			// Wrong Board.txt format!
//			// Would you like to create a new map?
//			// *enters editor*
//		}
//	}
//	m_file.close();
//}
////--------------------------------------------------
//// checks if map is valid
//// creates objects
//// sorts movables and unmovables
//
//bool Controller::isValid(const std::vector<string>& map)
//{
//	int playerCount = 0;
//
//	sf::Vector2f position(20, 140);  // position of object's sprite
//	sf::Vector2f mapSize(m_mapWidth, m_mapHeight);
//	sf::Vector2f resolution(WindowWidth, WindowHeight);
//
//	// stores objects in vectors
//	for (int i = 0; i < map.size(); i++)
//	{
//		position.x = 20;   // reset x for each new line
//		for (const auto& c : map[i])
//		{
//			switch (c)
//			{
//			case PlayerChar: 
//			{
//				playerCount++;
//				player = std::make_unique<Player>(position,
//												   mapSize,
//											   resolution);
//			}
//			break;
//			case DemonChar: 
//			{
//				m_movables.push_back(std::make_unique<Demon>(position,
//					                                          mapSize,
//														 resolution));
//			}
//			}
//			position.x += (float)(WindowWidth / m_mapWidth) * 1.f;
//		}
//		position.y += (float)(WindowHeight / m_mapHeight) * 0.7f;
//	}
//	return playerCount == 1 ? true : false;
//}