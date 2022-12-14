#include "Charachter.h"

Charachter::Charachter()
{
	// Global Variables for Characheter Below;
	charName = " ";
	charType = " ";
	charGender = " ";

	playerType = { "elf", "dwarf", "firelord", "goblin", "human" };

	level = 0;
	charHealth = 100;
	charTotalHealth = 0;
	charMaxHealth = 0;
	charHeal = 0;

	level = 1;
	current_XP = 0;
	base_XP = 80;
	minLevel = 1;
	maxLevel = 10;
	levelUpXP = base_XP;
}

void Charachter::charachterCreation() {

	// Counter
	int counter = 0;

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
	cout << "FireLord\n";
	cout << "Goblin\n";
	cout << "Human\n";
	cout << "Type Here: \n\n";
	cin >> charType;

	// this sets the cin the player input into lowercase so it,
	// matches the charType Array
	for_each(charType.begin(), charType.end(), [](char& c) {
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
			charType = "Viking";
			charHealth = 200;
			break;
		}
	}

	cout << "\n";
	cout << "Enter the Charachter Gender: ";
	cin >> charGender;
	system("cls");

	// Small Little animation of Creating the Charachter
	// For Loop Method Used

	for (int i = 0; i <= counter; i++) {
		if (i == 0)
			cout << "Creating Charachter.";
		if (i == 1)
			cout << "Creating Charachter..";
		if (i == 2) {
			cout << "Creating Charachter...";
			break;
		}

		Sleep(400);
		system("cls");
		counter++;
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
}