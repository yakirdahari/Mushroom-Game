#pragma once

#include <string>

struct Data
{
	int level = 1;					// player level
	int EXP = 0;					// current experience points
	int MaxEXP = 15;				// amount needed to level up
	int mesos = 0;					// game currency
	int HP = 100;					// health points
	int MaxHP = 100;				// maxiumum health points
	int MP = 100;					// mana points
	int MaxMP = 100;		   		// maximum mana points
	int damage = 25;				// amount of damage dealt
	bool wasHit = false;			// for hit detection
	std::string job = "Beginner";	// current job
	std::string name;

	// monster rewards
	int expReward;
	int mesosReward;
};