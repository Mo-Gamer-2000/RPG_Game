#pragma once
#include "Header.h"

//Initialize player position
int playerX = 0;
int playerY = 0;

int main()
{
    // Run class game.
    startGame game;
    game.start();

    // Run class display.
    Intro intro;
    intro.display();

    Location location("start", 0, 0); // create an object of the class and initialize it with the constructor
    std::cout << "Name: " << location.getName() << std::endl; // access the name using the getName() function
    std::cout << "X: " << location.getX() << std::endl; // access the X using the getX() function
    std::cout << "Y: " << location.getY() << std::endl; // access the Y using the getY() function

    HUD hudObject("Bob", "Male", "Theif"); // create an object of the class and initialize it with the constructor
    std::cout << "Example: " << std::endl;
    std::cout << "Name: " << hudObject.getName() << std::endl; // access the name using the getName() function
    std::cout << "Gender: " << hudObject.getGender() << std::endl; // access the gender using the getGender() function
    std::cout << "Type: " << hudObject.getType() << std::endl; // access the type using the getType() function

    // Counter created for creating character For loop.
    int counter = 0;

    // Built Animation to build character.
    std::string name;
    std::string gender;
    std::string type;

    // Prompt the user to enter the name, gender, and type of their character.
    std::cout << "\033[1;32m" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "|  BUILD YOUR CHARACTER  |" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "\033[0m" << std::endl;
    std::cout << "Enter Name of your Character: ";
    std::cin >> name;
    std::cout << "Enter Gender of your Character (Male/Female): ";
    std::cin >> gender;
    std::cout << "Enter Type of your Character (Warrior/Mage/Thief): ";
    std::cin >> type;

    // Clear the console.
    system("cls");

    // Animation of Creating the Charachter.
    // For Loop Method Used
    for (int i = 0; i <= counter; i++)
    {
        if (i == 0)
            cout << "Building Charachter.";
        if (i == 1)
            cout << "Building Charachter..";
        if (i == 2)
            cout << "Building Charachter...";
        if (i == 3)
        {
            cout << "Building Charachter....";
            break;
        }

        // Pause for 800 milliseconds.
        Sleep(800);

        // Clear the console.
        system("cls");

        // Increment the counter.
        counter++;
    }

    // Clear the console.
    system("cls");

    // Heads Up Display for character.
    HUD hud(name, gender, type);
    std::cout << "---------------------------" << std::endl;
    std::cout << "|  CHARACTER INFORMATION  |" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "|       Name: " << hud.getName();
    std::cout << "       |" << std::endl;
    std::cout << "|       Gender: " << hud.getGender();
    std::cout << "      |" << std::endl;
    std::cout << "|       Type: " << hud.getType();
    std::cout << "     |" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << " " << std::endl;

    // Create a 2-dimensional dynamic array to represent the game map
    int mapX = 10;
    int mapY = 10;

    // Smart Pointer = Unique_Pinter retriving cout from players class
    std::unique_ptr<std::unique_ptr<Player[]>[]> map = std::make_unique<std::unique_ptr<Player[]>[]>(mapX);
    for (int i = 0; i < mapX; i++) {
        map[i] = std::make_unique<Player[]>(mapY);
    }

    // variable to check if the player wants to quit
    bool quit = false;

    // Loop through until the player chooses to quit
    while (!quit) {
        // Print a message to the console with the player's name
        std::cout << "You are in a Dungeon! What do you want to do?" << std::endl;
        std::cout << "Your current position is X: " << playerX << " Y: " << playerY << std::endl;

        // Print a list of options to the console
        std::cout << "W. Go North" << std::endl;
        std::cout << "A. Go West" << std::endl;
        std::cout << "S. Go South" << std::endl;
        std::cout << "D. Go East" << std::endl;
        std::cout << "Y. Attack Monster" << std::endl;
        std::cout << "U. Open Treasure Chest" << std::endl;
        std::cout << "I. Drink Potion" << std::endl;
        std::cout << "Q. Quit Game" << std::endl;

        // Get the player's choice as a character
        char choice;
        std::cin >> choice;
        choice = toupper(choice);

        // Execute the corresponding action based on the player's choice
        if (choice == 'W')
        {
            if (playerY > 0) {
                map[playerX][playerY].goNorth();
                playerY--;
            }
            else {
                std::cout << "Cannot go North, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'A')
        {
            if (playerX > 0) {
                map[playerX][playerY].goWest();
                playerX--;
            }
            else {
                std::cout << "Cannot go West, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'S')
        {
            if (playerY < mapY - 1) {
                map[playerX][playerY].goSouth();
                playerY++;
            }
            else {
                std::cout << "Cannot go South, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'D')
        {
            if (playerX < mapX - 1) {
                map[playerX][playerY].goEast();
                playerX++;
            }
            else {
                std::cout << "Cannot go East, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'Y')
        {
            map[playerX][playerY].attack();
        }
        else if (choice == 'U')
        {
            map[playerX][playerY].openChest();
        }
        else if (choice == 'I')
        {
            map[playerX][playerY].drinkPotion();
        }
        else if (choice == 'Q')
        {
            map[playerX][playerY].quit();
            quit = true;
        }
    }
    return 0;
}

/*
My aim for this game was to showcase Pointers, Smart Pointers, Dynamic Arrays and Object Oriented Programming.
I think there is a big potential to add more feature to this game like having a battle between Character and Monster, and add feature such as winning the battle and losing.
Also, healing, level up and getting loot from winning battles.
laslty, including leveling up increases character stats such as health and demage.
I have stopped the game here as the scope of this assignment is to showcase Pointers, Smart Pointers, Dynamic Arrays and Object Oriented Programming.
I want to keep this game simple.
*/