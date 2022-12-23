// Includes located below:
#include <iostream>
#include <string>
#include <memory>    // for std::unique_ptr
#include <algorithm> // for std::copy

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

    int main() {
        // Create a unique pointer to a dynamically-allocated array of player objects
        std::unique_ptr<Player[]> players = std::make_unique<Player[]>(8);

        // Game loop
        for (int i = 0; i < 8; i++)
        {
            std::cout << "You are in a dungeon. What do you want to do?" << std::endl;
            std::cout << "1. Go north" << std::endl;
            std::cout << "2. Go east" << std::endl;
            std::cout << "3. Go south" << std::endl;
            std::cout << "4. Go west" << std::endl;
            std::cout << "5. Attack monster" << std::endl;
            std::cout << "6. Open chest" << std::endl;
            std::cout << "7. Drink potion" << std::endl;
            std::cout << "8. Quit game" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 1)
            {
                players[i].goNorth();
            }
            else if (choice == 2)
            {
                players[i].goEast();
            }
            else if (choice == 3)
            {
                players[i].goSouth();
            }
            else if (choice == 4)
            {
                players[i].goWest();
            }
            else if (choice == 5)
            {
                players[i].attack();
            }
            else if (choice == 6)
            {
                players[i].openChest();
            }
            else if (choice == 7)
            {
                players[i].drinkPotion();
            }
            else if (choice == 8)
            {
                players[i].quit();
                break;
            }
        }
}