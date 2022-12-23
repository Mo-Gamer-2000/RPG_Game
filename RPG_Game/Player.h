#pragma once
#include "Header.h"

using namespace std;

class Player {

public:

    // Constructor Player with Variables / PUBLIC - PRIVATE
    Player() {
        health = 100;
        attackPower = 10;
        defense = 5;
        gold = 0;
    }

    // goNorth Function
    void goNorth()
    {
        // Initializes goNorth
        cout << "You Walked Towards North and Found a Monster!" << endl;
    }

    // goEast Function
    void goEast()
    {
        // Initializes goEast
        cout << "You Walked Towards East and Found a Treasure Chest!" << endl;
    }

    // goSouth Function
    void goSouth()
    {
        // Initializes goSouth
        cout << "You Walked Towards South and Found a Potion!" << endl;
    }

    // goWest Function
    void goWest()
    {
        // Initializes goWest
        cout << "You Walked Towards West and Found a Staircase leading to the Next Level." << endl;
    }

    // Attack Function
    void attack()
    {
        // Initializes attack
        cout << "You Attacked the Monster and Dealt " << attackPower << " Damage." << endl;
    }

    // openChest Function
    void openChest()
    {
        // Initializes openChest
        cout << "You Found a Golden Coin in the Tresure Chest and it has been added to your Stash." << endl;
        gold++;
    }

    // drinkPotion Function
    void drinkPotion()
    {
        // Initializes drinkPotion
        cout << "You Drank the Potion and Restored 20 Health." << endl;
        health += 20;
    }

    // Quit Function
    void quit()
    {
        // Initializes Quit
        cout << "Thanks for Playing!" << endl;
    }

private:
    int health;
    int attackPower;
    int defense;
    int gold;

};