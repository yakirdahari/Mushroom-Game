#pragma once

struct Data
{
	int lvl = 1;			// player level
	int exp = 0;			// experience points
	int mesos = 0;			// game currency
	int HP = 100;			// health points
	int MaxHP = 100;		// maxiumum health points
	int MP = 100;			// mana points
	int MaxMP = 100;	    // maximum mana points
	int damage = 25;		// amount of damage dealt
	bool wasHit = false;	// for hit detection

	// monster rewards
	int expReward;
	int mesosReward;
};