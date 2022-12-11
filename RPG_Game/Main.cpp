// Includes located below:
#include <iostream>
#include <windows.h>
#include <string>

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

// Main Function
int main() {

	// Creating Level Up and Health System
	charLevel = 1;
	charXP = 0;
	charHealth = 100;
	charLevelUP = 80;
	charTotalHealth = charHealth;
	charMaxHealth = charTotalHealth;

	cout << "####################### \n";
	cout << "# SURVIVAL 'RPG' GAME # \n";
	cout << "####################### \n";
	Sleep(3000);
	system("cls");

	// Taking Charachter Data out And taking in to Assign to the Charachter Variables
	// Creating Charachter
	cout << "Enter the Charachter Name: ";
	cin >> charName;

	cout << "Enter the Charachter Type: ";
	cin >> charType;

	cout << "Enter the Charachter Gender: ";
	cin >> charGender;

	// Small Little animation of Creating the Charachter
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
	system("cls");

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
	Moving();
}

// Charachter Combat
void Combat() {
	// Do Do
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

// Create Monster
void CreateMonster() {
	monsterHP = 30;
	monsterLevel = (rand() % 3) + charLevel;

	// If Monster level equal 0 then monster level value goes between 3 + charLevel
	// This is to stop monster to have health 0
	if (monsterLevel == 0) {
		monsterLevel = (rand() % 3) + charLevel;
	}

	// Monster health random value betweeen 30 and charTotalHealth
	// May need to fix this value
	monsterHP = (rand() % 30) * charTotalHealth;

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