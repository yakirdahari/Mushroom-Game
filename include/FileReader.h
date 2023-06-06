#pragma once

#include <vector>
#include <memory>
#include <fstream>
#include "Map.h"
#include "Monster.h"

enum Objects 
{
    Player_Char = 'P',
    Monster1_Char = '1',
    Monster2_Char = '2',
    Monster3_Char = '3',
    Monster4_Char = '4',
    NPC1_Char = '!',
    NPC2_Char = '@',
    NPC3_Char = '#',
    NPC4_Char = '$',
    Ground_Char = '_',
    Wall_Char = '|',
    MonsterWall_Char = ']',
    Empty = ' ',
};

//----------------------
//  reads board.txt and inserts objects to map
bool readFile(const int& mapNumber, std::unique_ptr<Player>& player);
bool isValid(const std::vector<string>& map, std::unique_ptr<Player>& player);
