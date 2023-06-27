#include "FileReader.h"
#include "Info.h"
#include "Mushroom.h"
#include "Ground.h"
#include "Player.h"
#include "Wall.h"
#include "MonsterWall.h"
#include "Ladder.h"
#include "Rope.h"
#include "Heena.h"
#include "Sera.h"
#include "Peter.h"
#include "TutorialJrSentinel.h"
#include "Snail.h"
#include "BlueSnail.h"
#include "Shroom.h"
#include "Maria.h"

bool readFile(const int& mapID)
{
	std::vector<string> map;
	std::ifstream file;

	file.open("Board.txt");
	if (!file.is_open())
		throw std::exception("Error loading board.txt");

	// check if there are no more levels
	if (mapID >= Map::Max)
		return false;	// read unsuccessful

	// read maps till we read wanted map
	for (int currentMap = 1; currentMap <= mapID; currentMap++)
	{
		// clear existing map
		map.clear();
		Map::instance().monsters().clear();
		Map::instance().unmovables().clear();
		Map::instance().portals().clear();
		Map::instance().npcs().clear();

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

		scan(map);
	}
	file.close();
	return true;	// successful read
}

void scan(const std::vector<string>& map)
{
	sf::Vector2f position(0, 0);  // position of object's sprite
	
	// stores objects in vectors
	for (int i = 0; i < map.size(); i++)
	{
		position.x = 0;   // reset x for each new line
		for (const auto& c : map[i])
		{
			insertObject(static_cast<Objects>(c), position);
			position.x += 10.f;
		}
		position.y += +9.9f;
	}
	
	if (Map::instance().mapID() == Map::MushroomTown)
		Info::instance().addGUI(Info::Tutorial);
}

void insertObject(const Objects& object, const sf::Vector2f& position)
{
	// Mushroom Town
	if (Map::instance().mapID() == Map::MushroomTown)
	{
		switch (object)
		{
		case NPC1_Char: Map::instance().npcs().push_back(std::move(std::make_unique<Heena>(position)));
			break;
		case NPC2_Char: Map::instance().npcs().push_back(std::move(std::make_unique<Sera>(position)));
			break;
		case Portal_Char: Map::instance().portals().push_back(std::move(std::make_unique<Portal>(position, Map::SmallForest)));
		}
		Map::instance().map() = std::make_unique<sf::Sprite>(Resources::instance().maps(Map::MushroomTown));
		Map::instance().background() = std::make_unique<sf::Sprite>(Resources::instance().backgrounds(Map::MushroomTown));
		
		if (!Map::instance().music())
			Map::instance().music()->setBuffer(Resources::instance().music(Map::MushroomTown));
	}

	// Small Forest
	if (Map::instance().mapID() == Map::SmallForest)
	{
		switch (object)
		{
		case Monster1_Char: Map::instance().monsters().push_back(std::move(std::make_unique<TutorialJrSentinel>(position)));
			break;
		case NPC1_Char: Map::instance().npcs().push_back(std::move(std::make_unique<Peter>(position)));
			break;
		case Portal_Char: Map::instance().portals().push_back(std::move(std::make_unique<Portal>(position, Map::SplitRoad)));
		}
		Map::instance().map() = std::make_unique<sf::Sprite>(Resources::instance().maps(Map::SmallForest));
		Map::instance().background() = std::make_unique<sf::Sprite>(Resources::instance().backgrounds(Map::SmallForest));

		if (!Map::instance().music())
			Map::instance().music()->setBuffer(Resources::instance().music(Map::SmallForest));
	}

	// Split Road
	if (Map::instance().mapID() == Map::SplitRoad)
	{
		switch (object)
		{
		case Monster1_Char: Map::instance().monsters().push_back(std::move(std::make_unique<Snail>(position)));
			break;
		case Monster2_Char: Map::instance().monsters().push_back(std::move(std::make_unique<BlueSnail>(position)));
			break;
		case Monster3_Char: Map::instance().monsters().push_back(std::move(std::make_unique<Shroom>(position)));
			break;
		case NPC1_Char: Map::instance().npcs().push_back(std::move(std::make_unique<Maria>(position)));
				break;
		case Portal_Char:
		{
			Map::instance().portals().push_back(std::move(std::make_unique<Portal>(position, Map::SmallForest, 0)));
		}
		}
		Map::instance().map() = std::make_unique<sf::Sprite>(Resources::instance().maps(Map::SplitRoad));
		Map::instance().background() = std::make_unique<sf::Sprite>(Resources::instance().backgrounds(Map::SplitRoad));
		Map::instance().music()->setBuffer(Resources::instance().music(Map::SplitRoad));
	}

	// everything else
	switch (object)
	{
	case Player_Char:
		if (!Map::instance().player())
			Map::instance().player() = std::make_unique<Player>(position);
		else
			Map::instance().player()->setSpawn(position);
		break;
	case Ground_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Ground>(position)));
		break;
	case Wall_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Wall>(position)));
		break;
	case MonsterWall_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<MonsterWall>(position)));
		break;
	case Ladder_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Ladder>(position)));
		break;
	case Rope_Char: Map::instance().unmovables().push_back(std::move(std::make_unique<Rope>(position)));
	}

	// center background
	Map::instance().background()->setOrigin(sf::Vector2f(Map::instance().background()->getGlobalBounds().width / 2.f, Map::instance().background()->getGlobalBounds().height / 2.f));

	if (Map::instance().music()->getStatus() == sf::Sound::Status::Stopped)
	{
		Map::instance().music()->play();
		Map::instance().music()->setLoop(true);
	}
}
