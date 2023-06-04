#pragma once

#include <vector>
#include <memory>
#include <fstream>
#include "Map.h"
#include "Demon.h"

enum Objects 
{
    PlayerChar = 'a',
    DemonChar = '&',
    WallChar = '#',
    DoorChar = 'D',
    KeyChar = '%',
    CookieChar = '*',
    GiftChar = '$',
    Empty = ' ',
};

//----------------------
//  reads board.txt and inserts objects to map
bool readFile(const int& mapNumber, std::unique_ptr<Player>& player);
bool isValid(const std::vector<string>& map, std::unique_ptr<Player>& player);
