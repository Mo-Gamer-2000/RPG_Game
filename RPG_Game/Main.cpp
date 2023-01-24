#include "Header.h"

int main()
{
    // Run class game.
    startGame start; // creates an object of the startGame class
    start.start(); // calls the start() function of the startGame object

    // Run class display.
    Intro intro; // creates an object of the Intro class
    intro.display(); // calls the display() function of the Intro object

    std::unique_ptr<Player> player = std::make_unique<Player>("Bob", "Male", "Warrior", 150, 25); // calls the travel method on the player object and passes in "forest" as an argument
    player->travel("forest"); // calls the travel method on the player object and passes in "forest" as an argument
    player->displayBattleHUD(); // calls the displayBattleHUD method on the player object

    int choice;
    while (true)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "5. Quit Game!\n";
        std::cout << "1. Travel Towards North\n";
        std::cout << "2. Travel Towards South\n";
        std::cout << "3. Travel Towards East\n";
        std::cout << "4. Travel Towards West\n";
        std::cin >> choice; // declares a variable to store the player's choice
        if (choice == 5)
        {
            std::cout << "Thanks for playing!\n";
            exit(0); // exits the game
        }
        else if (choice == 1)
        {
            player->travel("north"); // calls the travel method on the player object and passes in "north" as an argument
        }
        else if (choice == 2)
        {
            player->travel("south"); // calls the travel method on the player object and passes in "south" as an argument
        }
        else if (choice == 3)
        {
            player->travel("east"); // calls the travel method on the player object and passes in "east" as an argument
        }
        else if (choice == 4)
        {
            player->travel("west"); // calls the travel method on the player object and passes in "west" as an argument
        }
        else
        {
            std::cout << "Invalid choice. Please choose again.\n";
        }

        player->displayBattleHUD();
        player->levelUp();
        player->travel("north");

        // checks if the player has encountered a monster
        if (player->encounteredMonster())
        {
            std::unique_ptr<Monster> monster =
                std::make_unique<Monster>(50, 10, 20, 10);

            // enters into a battle loop as long as both the player and the monster are alive
            while (monster->health > 0 && player->health > 0)
            {
                std::cout << "What would you like to do?\n";
                std::cout << "1. Attack the Monster\n";
                std::cout << "2. Bribe the Monster\n";
                std::cout << "3. Run Away from the Monster\n";
                std::cin >> choice;
                if (choice == 1)
                {
                    player->attackMonster(monster); // calls the attackMonster method on the player object and passes in the monster object as an argument
                }
                else if (choice == 2)
                {
                    if (player->gold >= monster->gold) // checks if the player has enough gold to bribe the monster
                    {
                        player->bribeMonster(monster); // calls the bribeMonster method on the player object and passes in the monster object as an argument
                        break; // exits the battle loop
                        player->displayBattleHUD();
                        player->levelUp();
                        player->travel("North");
                    }
                    else
                    {
                        std::cout << "You do not have enough gold to bribe the monster!\n";
                    }
                }
                else if (choice == 3)
                {
                    std::cout << "You ran away from the monster like a coward!\n";
                    break; // exits the battle loop
                    player->displayBattleHUD();
                    player->levelUp();
                    player->travel("North");
                }
                else
                {
                    std::cout << "Invalid choice. Please try again.\n";
                }
                if (monster->health > 0)
                {
                    player->takeDamage(monster->attack); // calls the takeDamage method on the player object and passes in the monster's attack as an argument
                }
            }
            if (player->health > 0 && choice != 2)
            {
                std::cout << "Player wins the battle!\n";
                player->reward(monster); // calls the reward method on the player object and passes in the monster object as an argument
            }
            else
            {
                if (choice != 2)
                    std::cout << "Player loses the battle.\n";
            }

            player->displayBattleHUD();
            player->levelUp();
            player->travel("North");

            return 0;
        }
    }
}