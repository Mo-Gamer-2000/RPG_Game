#include "Header.h"

int main()
{
    //// Run class game.
    //startGame start;
    //start.start();

    //// Run class display.
    //Intro intro;
    //intro.display();

    std::unique_ptr<Player> player = std::make_unique<Player>("Bob", "Male", "Warrior", 150, 25);
    player->travel("forest");
    player->displayBattleHUD();

    int choice;
    while (true)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "5. Quit Game!\n";
        std::cout << "1. Travel Towards North\n";
        std::cout << "2. Travel Towards South\n";
        std::cout << "3. Travel Towards East\n";
        std::cout << "4. Travel Towards West\n";
        std::cin >> choice;
        if (choice == 5)
        {
            std::cout << "Thanks for playing!\n";
            exit(0);
        }
        else if (choice == 1)
        {
            player->travel("north");
        }
        else if (choice == 2)
        {
            player->travel("south");
        }
        else if (choice == 3)
        {
            player->travel("east");
        }
        else if (choice == 4)
        {
            player->travel("west");
        }
        else
        {
            std::cout << "Invalid choice. Please choose again.\n";
        }

        player->displayBattleHUD();
        player->levelUp();
        player->travel("north");

        if (player->encounteredMonster())
        {
            std::unique_ptr<Monster> monster =
                std::make_unique<Monster>(50, 10, 20, 10);
            while (monster->health > 0 && player->health > 0)
            {
                std::cout << "What would you like to do?\n";
                std::cout << "1. Attack the Monster\n";
                std::cout << "2. Bribe the Monster\n";
                std::cout << "3. Run Away from the Monster\n";
                std::cin >> choice;
                if (choice == 1)
                {
                    player->attackMonster(monster);
                }
                else if (choice == 2)
                {
                    if (player->gold >= monster->gold)
                    {
                        player->bribeMonster(monster);
                        break;
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
                    break;
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
                    player->takeDamage(monster->attack);
                }
            }
            if (player->health > 0 && choice != 2)
            {
                std::cout << "Player wins the battle!\n";
                player->reward(monster);
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