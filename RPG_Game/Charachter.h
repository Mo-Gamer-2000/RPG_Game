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

	int charLevel;
	int charXP;
	int charHealth;
	int charTotalHealth;
	int charMaxHealth;
	int charLevelUP ;
	int charHeal;



	void charachterCreation();
};

