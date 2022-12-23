#include "Player.h"
// Player class
class Player
{
public:
    // Player Constructor
    Player()
    {
        health = 100;
        attackPower = 10;
        defense = 5;
        gold = 0;
    }
    // goNorth Function
    void goNorth()
    {
        std::cout << "You Walk towards North and find a Monster!" << std::endl;
    }
    // goEast Function
    void goEast()
    {
        std::cout << "You Walk towards East and find a Treasure Chest!" << std::endl;
    }
    // goSouth Function
    void goSouth()
    {
        std::cout << "You Walk towards South and find a Potion!" << std::endl;
    }
    // goWest Function
    void goWest()
    {
        std::cout << "You Walk towards West and find a Staircase leading to the Next Level." << std::endl;
    }
    // Attack Function
    void attack()
    {
        std::cout << "You Attack the Monster and Deal " << attackPower << " Damage." << std::endl;
    }
    // openChest Function
    void openChest()
    {
        std::cout << "You find a Golden Coin in the Tresure Chest and add it to your Stash." << std::endl;
        gold++;
    }
    // drinkPotion Function
    void drinkPotion()
    {
        std::cout << "You Drink the Potion and Restore 20 Health." << std::endl;
        health += 20;
    }
    // Quit Function
    void quit()
    {
        std::cout << "Thanks for Playing!" << std::endl;
    }

private:
    int health;
    int attackPower;
    int defense;
    int gold;
};