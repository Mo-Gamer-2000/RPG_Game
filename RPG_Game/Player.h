#pragma once
#include "Header.h"

using namespace std;

// Class definition for a Player
class Player {

public:
    // Constructor for the Player class
    // This function is called whenever a new Player object is created
    // It initializes the player's health, attack power, defense, and gold to specific values
    Player() {
        health = 100;
        attackPower = 10;
        defense = 5;
        gold = 0;
    }

    // Member function that allows the player to move towards the north
    void goNorth()
    {
        // Prints a message indicating that the player has found a monster while moving towards the north
        cout << "You Walked Towards North and Found a Monster!" << endl;
    }

    // Member function that allows the player to move towards the east
    void goEast()
    {
        // Prints a message indicating that the player has found a treasure chest while moving towards the east
        cout << "You Walked Towards East and Found a Treasure Chest!" << endl;
    }

    // Member function that allows the player to move towards the south
    void goSouth()
    {
        // Prints a message indicating that the player has found a potion while moving towards the south
        cout << "You Walked Towards South and Found a Potion!" << endl;
    }

    // Member function that allows the player to move towards the west
    void goWest()
    {
        // Prints a message indicating that the player has found a staircase leading to the next level while moving towards the west
        cout << "You Walked Towards West and Found a Staircase leading to the Next Level." << endl;
    }

    // Member function that allows the player to attack a monster
    void attack()
    {
        // Prints a message indicating the amount of damage dealt to the monster
        cout << "You Attacked the Monster and Dealt " << attackPower << " Damage." << endl;
    }

    // Member function that allows the player to open a treasure chest
    void openChest()
    {
        // Prints a message indicating that the player has found a golden coin in the treasure chest and adds it to the player's stash
        cout << "You Found a Golden Coin in the Tresure Chest and it has been added to your Stash." << endl;
        gold++;
    }

    // Member function that allows the player to drink a potion
    void drinkPotion()
    {
        // Prints a message indicating that the player has restored some health by drinking a potion
        cout << "You Drank the Potion and Restored 20 Health." << endl;
        health += 20;
    }

    // Member function that allows the player to quit the game
    void quit()
    {
        // Prints a message indicating that the player has quit the game
        cout << "Thanks for Playing!" << endl;
    }



private:
    // Member variables for the player's health, attack power, defense, and gold
    // These variables are private and can only be accessed and modified from within the Player class or by friend functions and classes
    int health;
    int attackPower;
    int defense;
    int gold;
};