#include "FileReader.h"

bool readFile(const int& mapNumber, std::unique_ptr<Player>& player)
{
	std::ifstream file;
	file.open("Board.txt");

	if (!file.is_open())
	{
		throw std::exception("Error loading board.txt");
	}

	std::vector<string> map;

	// check if no more levels
	if (mapNumber == 4)
	{
		return false;	// read unsuccessful
	}

	for (int currentMap = 1; currentMap <= mapNumber; currentMap++)
	{
		// clear existing map
		map.clear();
		
		Map::instance().movables().clear();
		Map::instance().unmovables().clear();

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
		if (currentMap != mapNumber)
		{
			continue;
		}

		// check if map is valid
		if (!isValid(map, player))
		{
			// Wrong Board.txt format!
			// Would you like to create a new map?
			// *enters editor*
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
			case Monster4_Char:
			{
				Map::instance().movables().push_back(std::move(std::make_unique<Mushroom>(position)));
			}
			}
			position.x += 10.f;
		}
		position.y += +10.f;
	}
	return playerCount == 1 ? true : false;
}