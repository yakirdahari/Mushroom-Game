#include "FileReader.h"

bool readFile(const int& mapID, std::unique_ptr<Player>& player)
{
	std::ifstream file;
	file.open("Board.txt");

	if (!file.is_open())
	{
		throw std::exception("Error loading board.txt");
	}

	std::vector<string> map;

	// check if there are no more levels
	if (mapID >= Map::Max)
	{
		return false;	// read unsuccessful
	}

	// read maps till we read wanted map
	for (int currentMap = 1; currentMap <= mapID; currentMap++)
	{
		// clear existing map
		map.clear();
		
		Map::instance().movables().clear();
		Map::instance().unmovables().clear();
		Map::instance().portals().clear();
		//Map::instance().map().release();
		//Map::instance().background().release();


		// assign mapID
		Map::instance().mapID() = mapID;

		// read height, width
		string line;
		file >> line;
		Map::instance().mapHeight() = stoi(line);
		std::getline(file, line);
		Map::instance().mapWidth() = stoi(line);
		std::getline(file, line);

		// put each line in map vector
		for (int i = 0; i < Map::instance().mapHeight(); i++)
		{
			std::getline(file, line);
			map.push_back(line);
		}

		// eat space between maps
		std::getline(file, line);

		// skip maps till reached wanted map
		if (currentMap != mapID)
		{
			continue;
		}

		// check if map is valid
		if (currentMap == mapID && !isValid(map, player))
		{
			throw std::exception("Invalid map!");
		}
	}
	file.close();
	return true;	// successful read
}

bool isValid(const std::vector<string>& map, std::unique_ptr<Player>& player)
{
	int playerCount = 0;

	sf::Vector2f position(0, 0);  // position of object's sprite
	
	// stores objects in vectors
	for (int i = 0; i < map.size(); i++)
	{
		position.x = 0;   // reset x for each new line
		for (const auto& c : map[i])
		{
			switch (c)
			{
			case Player_Char:
			{
				playerCount++;
				player->setPosition(position);
			}
			break;
			default: insertObject(static_cast<Objects>(c), position);
			}
			position.x += 10.f;
		}
		position.y += +10.f;
	}
	return playerCount == 1 || Map::instance().portals().size() != 0 ? true : false;
}

void insertObject(Objects object, sf::Vector2f position)
{
	// Mushroom Town
	if (Map::instance().mapID() == Map::MushroomTown)
	{
		switch (object)
		{
		case Monster4_Char: Map::instance().movables().push_back(std::move(std::make_unique<Mushroom>(position)));
			break;
		case Portal_Char: Map::instance().portals().push_back(std::move(std::make_unique<Portal>(position, Map::SmallForest, 1)));
		}
		Map::instance().map() = std::make_unique<sf::Sprite>(Resources::instance().maps().at(Map::MushroomTown));
		Map::instance().background() = std::make_unique<sf::Sprite>(Resources::instance().backgrounds().at(Map::MushroomTown));
	}

	// Mushroom Town
	if (Map::instance().mapID() == Map::SmallForest)
	{
		switch (object)
		{
		case Portal_Char: Map::instance().portals().push_back(std::move(std::make_unique<Portal>(position, Map::MushroomTown, 0)));
		}
		Map::instance().map() = std::make_unique<sf::Sprite>(Resources::instance().maps().at(Map::SmallForest));
		Map::instance().background() = std::make_unique<sf::Sprite>(Resources::instance().backgrounds().at(Map::SmallForest));
	}

	// everything else
	switch (object)
	{
	case Ground_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Ground>(position)));
		break;
	case Wall_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Wall>(position)));
		break;
	case MonsterWall_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<MonsterWall>(position)));
		break;
	case Ladder_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Ladder>(position)));
	}
}
