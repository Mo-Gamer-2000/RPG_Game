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
string monsterName[] = { "Goblin", "Dwarf", "Orge", "Witch", "Demon","Wizard" };
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
	cout << "Name: " << charName << "\nHealth: " << charTotalHealth << "\nType: " << charType
		<< "\nGender: " << charGender << "\nLevel: " << charLevel << "\nXP: " << charXP
		<< "\nXP to Level Up: " << charLevelUP << endl;
}

// Charachter Movment
void Moving() {

	int selection;

	cout << "\n\n";
	cout << "1. Move Forward\n";
	cout << "2. Have Rest\n";
	cout << "3. Move Backwards\n";
	cout << "\n\n";

	cin >> selection;

	if (selection == 1) {
		// Do Do
	}
	else if (selection == 2) {
		// Do Do
	}
	else if (selection == 3) {
		// Do Do
	}
	else {
		cout << "Inavlid Selection. Please, Try Again!";
		Sleep(500);
		Moving();
	}
}