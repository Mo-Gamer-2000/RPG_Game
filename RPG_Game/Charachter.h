#pragma once

#include "Header.h"
using namespace std;

class Charachter
{


public:
	// Constructor
	Charachter();

	// Global Variables for Characheter Below;
	string charName;
	string charType;
	string charGender;

	// Monster Type Array
	vector<string> playerType;

	int charHealth;
	int charTotalHealth;
	int charMaxHealth;
	int charHeal;

	int level;
	int current_XP;
	int base_XP;
	int levelUpXP;
	int minLevel;
	int maxLevel;



	void charachterCreation();
};

