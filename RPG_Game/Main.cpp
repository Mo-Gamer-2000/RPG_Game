#include "Charachter.h"

// Using Directive
using namespace std;

// Function HUD
void HUD();

// Function Combat
void Combat();

// Function CombatHUD
void CombatHUD();

// Function Moving
void Moving();

// Function CreateMonster
void CreateMonster();

// Function LevelUP
void LevelUP();

// Global Variables for Monster Below;
int monsterHP = 0;
int monsterXP = 0;
int monsterLevel = 0;

// Monster Names Array / Global Variables Below;
string monsterName[] = { "Goblin", "Dwarf", "Orge", "Witch", "Demon", "Wizard" };
int currentMonsterNames = 5;
string currentMonster = " ";

// Counter created for loading screen
int counter = 0;

// Constructor to access its properties in main.cpp
Charachter character;

// Main Function
int main() {

	// Calling charachterCreation function from charachter
	character.charachterCreation();

	HUD();
	Moving();

	system("pause");

	return 0;
}

// Created a basic Heads up Display of Charchter Details
void HUD() {
	Sleep(500);
	system("cls");
	cout << "Charachter information: \n";
	cout << "Name: " << character.charName << "\nHealth: " << character.charTotalHealth << "\nType: " << character.charType
		<< "\nGender: " << character.charGender << "\nLevel: " << character.charLevel << "\nXP: " << character.charXP
		<< "\nXP to Level Up: " << character.charLevelUP << endl;
	Moving();
}

// Created a basic Heads up Display of Comabat Details
void CombatHUD() {
	Sleep(500);
	system("cls");
	cout << "Name: " << character.charName << "		|		Monster Name: " << currentMonster << "\nHealth: " << character.charTotalHealth << "		|		Monster Health: " << monsterHP <<
		"\nLevel: " << character.charLevel << "		|		Monster Level: " << monsterLevel << endl;
}

// Charachter Combat
void Combat() {
	// CombatHud brought,attack and demage values added and CharChoice
	CombatHUD();

	int charChoice;
	int charDemage = 8 * character.charLevel / 2;
	int monsterAttack = 6 * monsterLevel / 2;

	if (character.charTotalHealth >= 1 && monsterHP >= 1) {
		cout << "\n";
		cout << "1. Attack\n";
		cout << "2. Block\n";
		cout << "3. RUN!\n";
		cout << "\n";
		cin >> charChoice;

		if (charChoice == 1) {
			// ATTACK
			cout << "Attacking... You did: " << charDemage << " to the " << currentMonster << endl;
			monsterHP = monsterHP - charDemage;
			Sleep(1000);
			CombatHUD();

			if (monsterHP >= 1) {
				cout << "\n";
				cout << "Monster is Attacking!\n";
				character.charTotalHealth = character.charTotalHealth - monsterAttack;
				cout << "You just got Attacked by: " << currentMonster << "You have Lost: " << monsterAttack << " HP " << "You Health is now: " << character.charTotalHealth << endl;

				// Change to Function.
				if (character.charTotalHealth <= 0) {
					character.charTotalHealth = 0;
					system("cls");
					cout << "You Died! \n You were Level: " << character.charLevel << "you got Killed by " << currentMonster << endl;
					Sleep(2000);
					exit(0);

				}
			}
			else if (monsterHP <= 0) {
				monsterHP = 0;
				LevelUP();
				cout << "\n";
				cout << "You have Beaten " << currentMonster << " you have been Rewarded with " << monsterXP << "XP.\nMission Completed!\n";
				Sleep(1000);
				HUD();
			}
			Sleep(1000);
			Combat();
		}
		else if (charChoice == 2) {
			// BLOCK
			cout << "Blocking\n";
			int i = rand() % 100 + 1;
			if (i >= 50) {
				cout << "You have Blocked the Attack!\n";
				character.charHeal = character.charLevel * 10 / 2;
				cout << "You have Healed: " << character.charHeal << "HP" << endl;
				character.charTotalHealth += character.charHeal;
				Sleep(1000);
				Combat();
			}
			else {
				cout << "You hav Failed to Block the Monster Attack\n";
				character.charTotalHealth -= monsterAttack;
				cout << "You were Attacked for: " << monsterAttack << "Your HP is now: " << character.charTotalHealth << endl;
				Sleep(1000);
				Combat();
			}
		}
		else if (charChoice == 3) {
			// RUN!!!
			cout << "You try to Run!\n";
			int x = rand() % 100 +1;
			if (x >= 50) {
				cout << "You Ran awey from the Battle!\n";
				HUD();
			}
			else {
				cout << "You have Failed to Run awey!\n";
				cout << "Monster Attacked you!\n";
				character.charTotalHealth -= monsterAttack + 10;
				cout << "You Suffered " << monsterAttack + 10 << "You current Health is: " << character.charTotalHealth << endl;
				Sleep(1000);
				Combat();
			}
		}
		else {
			cout << "Inavlid Selection. Please, Try Again!";
			Sleep(500);
			Combat();
		}
	}
}

// Charachter Movment
void Moving() {

	int selection;

	cout << "\n";
	cout << "What would you Like to do Next?: " << character.charName << endl;
	cout << "\n";
	cout << "1. Move Forward\n";
	cout << "2. Have Rest\n";
	cout << "3. Move Backwards\n";
	cout << "\n";

	cout << "Type Your Selection Here: ";
	cin >> selection;
	cout << "\n";
	// Moving Forward Selection Created
	if (selection == 1) {
		// Random Randit used to move the charachter by 1
		// If int temp greater then or equal to 50, then we encounter a (RANDOM) Monster
		int temp = rand() % 100 + 1;
		cout << "You Have Just Moved Forward...\n";
		if (temp >= 50) {
			// Encounter a Monster Function
			// Encoutering Random Monster
			CreateMonster();
			string tempName = monsterName[rand() % currentMonsterNames];
			cout << "You Came Across a: " << tempName << " ,Get Ready for The Battle!!!\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		cout << "You Have Found Nothing Interesting.\n";
			Sleep(1000);
			HUD();

	}
	// Resting Selection Created
	else if (selection == 2) {
		// Text and if Char helth less then or equal to 99
		// Then Char heals it self by 10 * charLevel
		cout << "You Have Set up a Cozy Camp for The Evening.\n";
		if (character.charTotalHealth <= 99) {
			character.charTotalHealth += 10 * character.charLevel;
		}
		cout << "You Have Healed by Resting. Health is now: " << character.charTotalHealth << endl;
		Sleep(1000);
		HUD();
	}
	// Moving Backward Selection Created
	else if (selection == 3) {
		// Random Randit used to move the charachter by 1
		// If int temp greater then or equal to 50, then we encounter a (RANDOM) Monster
		int temp = rand() % 100 + 1;
		cout << "You Have Just Moved Backwards...\n";
		if (temp >= 50) {
			// Encounter a Monster Function
			// Encoutering Random Monster
			CreateMonster();
			string tempName = monsterName[rand() % currentMonsterNames];
			cout << "You Came Across a: " << tempName << " ,Get Ready for The Battle!!!\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		cout << "You Have Found Nothing Interesting.\n";
		Sleep(1000);
		HUD();
	}
	else {
		cout << "Inavlid Selection. Please, Try Again!";
		Sleep(500);
		Moving();
	}
}

// Charachter LevelUP
void LevelUP() {
	character.charXP = character.charXP + monsterXP;

	// Level up feature below
	if (character.charXP >= character.charLevelUP) {
		character.charLevel++;
		character.charLevelUP = character.charLevelUP * 3 / 2;
		character.charTotalHealth = character.charTotalHealth + 20;
		character.charMaxHealth = character.charTotalHealth;
		cout << "Hey, " << character.charName << "You have just been Leveled-up! " << character.charLevel << endl;
		cout << "You Max Health has been Incresead by 20 HP. You total Health is now: " << character.charTotalHealth << endl;
		Sleep(2000);
		HUD();
	}
}

// Create Monster
void CreateMonster() {
	monsterHP = 30;
	monsterLevel = (rand() % 3) + character.charLevel;

	// If Monster level equal 0 then monster level value goes between 3 + charLevel
	// This is to stop monster to have health 0
	//if (monsterLevel == 0) {
	//	monsterLevel = (rand() % 3) + charLevel;
	//}

	// Monster health random value betweeen 30 and charTotalHealth
	// May need to fix this value
	monsterHP = (rand() % 30) * monsterLevel;

	// If monster health 0 then random between 30 and charTotalhealth
	/*if (monsterHP == 0) {
		monsterHP = (rand() % 30) * charTotalHealth;
	}*/
	// XP given = HP of the Monster
	monsterXP = monsterHP;

	// If monsterHP = 0 then execute the function Again
	if (monsterHP == 0)
		CreateMonster();
	if (monsterLevel == 0)
		CreateMonster();
}