// Includes located below:
#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

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

// Global Variables for Characheter Below;
string charName = " ";
string charType = " ";
string charGender = " ";

int charLevel = 0;
int charXP = 0;
int charHealth = 0;
int charTotalHealth = 0;
int charMaxHealth = 0;
int charLevelUP = 0;
int charHeal = 0;

// Global Variables for Monster Below;
int monsterHP = 0;
int monsterXP = 0;
int monsterLevel = 0;

// Monster Names Array / Global Variables Below;
string monsterName[] = { "Goblin", "Dwarf", "Orge", "Witch", "Demon", "Wizard" };
int currentMonsterNames = 5;
string currentMonster = " ";

// Counter created for loading screen
int counter = 3;

// Monster Type Array
string playerType[] = {"eld", "dwarf", "firelord", "goblin", "human"};

// Main Function
int main() {

	// Creating Level Up and Health System
	charLevel = 1;
	charXP = 0;
	charLevelUP = 80;
	
	cout << "####################### \n";
	cout << "# SURVIVAL 'RPG' GAME # \n";
	cout << "####################### \n";
	Sleep(3000);
	system("cls");

	// Taking Charachter Data out And taking in to Assign to the Charachter Variables
	// Creating Charachter
	cout << "Enter the Charachter Name: ";
	cin >> charName;

	// Charachter Options
	cout << "Enter the Charachter Type: \n";
	cout << "Elf\n";
	cout << "Dwarf\n";
	cout << "Fire Lord\n";
	cout << "goblin\n";
	cout << "Human\n";
	cout << "Type Here: \n\n";
	cin >> charType;

	// this sets the cin the player input into lowercase so it,
	// matches the charType Array
	for_each(charType.begin(), charType.end(), [](char & c) {
		c = tolower(c);
		});
	// for loop for each charachter with their default HP when,
	// selecting charachter
	for (int i = 0; i < sizeof(playerType); i++) {
		if (charType == "elf") {
			charHealth = 80;
			break;
		}
		if (charType == "dwarf") {
			charHealth = 120;
			break;
		}
		if (charType == "firelord") {
			charHealth = 150;
			break;
		}
		if (charType == "goblin") {
			charHealth = 85;
			break;
		}
		if (charType == "human") {
			charHealth = 65;
			break;
		}
		else {
			charType = 100;
		}	
	}

	cout << "\n";
	cout << "Enter the Charachter Gender: ";
	cin >> charGender;

	// Small Little animation of Creating the Charachter
	// For Loop Method Used

	for (int i = 0; i < counter; i++) {
		if (i == 0)
			cout << "Creating Charachter.";
		if (i == 1)
			cout << "Creating Charachter..";
		if (i == 2)
			cout << "Creating Charachter...";

		Sleep(400);
		system("cls");
	}

	// Changing name, type and gender to upperCase from lowercase. 
	charName[0] = toupper(charName[0]);
	charType[0] = toupper(charType[0]);
	charGender[0] = toupper(charGender[0]);
	// Other bad example of creating the same Creating Charachter method Animation
	/*cout << "Creating Charachter. \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter.. \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter... \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter. \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter.. \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter... \n";
	Sleep(300);
	system("cls");
	cout << "Creating Charachter. \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter.. \n";
	Sleep(300);
	system("cls");

	cout << "Creating Charachter... \n";
	Sleep(300);
	system("cls");

	cout << "Charachter Created! \n";
	Sleep(800);
	system("cls");*/

	// charHealth = 100;
	charTotalHealth = charHealth;
	charMaxHealth = charTotalHealth;

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
	cout << "Name: " << charName << "\nHealth: " << charTotalHealth << "\nType: " << charType
		<< "\nGender: " << charGender << "\nLevel: " << charLevel << "\nXP: " << charXP
		<< "\nXP to Level Up: " << charLevelUP << endl;
	Moving();
}

// Created a basic Heads up Display of Comabat Details
void CombatHUD() {
	Sleep(500);
	system("cls");
	cout << "Name: " << charName << "		|		Monster Name: " << currentMonster << "\nHealth: " << charTotalHealth << "		|		Monster Health: " << monsterHP << 
		"\nLevel: " << charLevel << "		|		Monster Level: " << monsterLevel << endl;
}

// Charachter Combat
void Combat() {
	// CombatHud brought,attack and demage values added and CharChoice
	CombatHUD();

	int charChoice;
	int charDemage = 8 * charLevel / 2;
	int monsterAttack = 6 * monsterLevel / 2;

	if (charTotalHealth >= 1 && monsterHP >= 1) {
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
				charTotalHealth = charTotalHealth - monsterAttack;
				cout << "You just got Attacked by: " << currentMonster << "You have Lost: " << monsterAttack << " HP " << "You Health is now: " << charTotalHealth << endl;

				// Change to Function.
				if (charTotalHealth <= 0) {
					charTotalHealth = 0;
					system("cls");
					cout << "You Died! \n You were Level: " << charLevel << "you got Killed by " << currentMonster << endl;
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
				charHeal = charLevel * 10 / 2;
				cout << "You have Healed: " << charHeal << "HP" << endl;
				charTotalHealth += charHeal;
				Sleep(1000);
				Combat();
			}
			else {
				cout << "You hav Failed to Block the Monster Attack\n";
				charTotalHealth -= monsterAttack;
				cout << "You were Attacked for: " << monsterAttack << "Your HP is now: " << charTotalHealth << endl;
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
				charTotalHealth -= monsterAttack + 10;
				cout << "You Suffered " << monsterAttack + 10 << "You current Health is: " << charTotalHealth << endl;
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
	cout << "What would you Like to do Next?: " << charName << endl;
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
		if (charTotalHealth <= 99) {
			charTotalHealth += 10 * charLevel;
		}
		cout << "You Have Healed by Resting. Health is now: " << charTotalHealth << endl;
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
	charXP = charXP + monsterXP;

	// Level up feature below
	if (charXP >= charLevelUP) {
		charLevel++;
		charLevelUP = charLevelUP * 3 / 2;
		charTotalHealth = charTotalHealth + 20;
		charMaxHealth = charTotalHealth;
		cout << "Hey, " << charName << "You have just been Leveled-up! " << charLevel << endl;
		cout << "You Max Health has been Incresead by 20 HP. You total Health is now: " << charTotalHealth << endl;
		Sleep(2000);
		HUD();
	}
}
// Create Monster
void CreateMonster() {
	monsterHP = 30;
	monsterLevel = (rand() % 3) + charLevel;

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