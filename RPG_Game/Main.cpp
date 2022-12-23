// Includes located below:
#include <iostream>
#include <string>
#include <memory>    // for std::unique_ptr
#include <algorithm> // for std::copy

int main() {
    // Player class
    class Player
    {
    public:
        Player()
        {
            health = 100;
            attackPower = 10;
            defense = 5;
            gold = 0;
        }

        void goNorth()
        {
            std::cout << "You Walk towards North and find a Monster!" << std::endl;
        }
        void goEast()
        {
            std::cout << "You Walk towards East and find a Treasure Chest!" << std::endl;
        }
        void goSouth()
        {
            std::cout << "You Walk towards South and find a Potion!" << std::endl;
        }
        void goWest()
        {
            std::cout << "You Walk towards West and find a Staircase leading to the Next Level." << std::endl;
        }
        void attack()
        {
            std::cout << "You Attack the Monster and Deal " << attackPower << " Damage." << std::endl;
        }
        void openChest()
        {
            std::cout << "You find a Golden Coin in the Tresure Chest and add it to your Stash." << std::endl;
            gold++;
        }
        void drinkPotion()
        {
            std::cout << "You Drink the Potion and Restore 20 Health." << std::endl;
            health += 20;
        }
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
}