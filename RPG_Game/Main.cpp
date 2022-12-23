#include "Player.h"

int main() {
        // Create a Unique Pointer to a Dynamically-Allocated array of Player Objects
        std::unique_ptr<Player[]> players = std::make_unique<Player[]>(8);

        // Game For Loop
        for (int i = 0; i < 8; i++)
        {
            std::cout << "You are in a Dungeon. What do you want to do?" << std::endl;
            std::cout << "1. Go North" << std::endl;
            std::cout << "2. Go East" << std::endl;
            std::cout << "3. Go South" << std::endl;
            std::cout << "4. Go West" << std::endl;
            std::cout << "5. Attack Monster" << std::endl;
            std::cout << "6. Open Treasure Chest" << std::endl;
            std::cout << "7. Drink Potion" << std::endl;
            std::cout << "8. Quit Game" << std::endl;

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
