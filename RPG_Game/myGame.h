#pragma once
#include "Header.h"

class MyGame
{
public:
    Player player;
    MyGame(const char* arg1, const char* arg2, const char* arg3, const char* arg4)
        : arg1_(arg1), arg2_(arg2), arg3_(arg3), arg4_(arg4), player("Bob", "Male", "Warrior", 150, 25) {}
    void run()
    {
        // Create a vector to store the monsters
        std::vector<std::unique_ptr<Monster>> monsters;

        // Add some monsters to the vector
        monsters.push_back(std::make_unique<Monster>(10, 2, 5, 1));
        monsters.push_back(std::make_unique<Monster>(20, 5, 10, 2));
        monsters.push_back(std::make_unique<Monster>(30, 8, 15, 3));

        // Iterate through the vector of monsters
        for (auto& monster : monsters)
        {
            std::cout << "Player encounters a monster with " << monster->health << " health." << std::endl;

            player.encounteredMonster_ = true;
            while (player.encounteredMonster())
            {
                // code to handle the battle
                player.attackMonster(monster);
                if (monster->health <= 0)
                {
                    // code to handle the monster being defeated
                    break;
                }
            }
        }
    }

private:
    const char* arg1_;
    const char* arg2_;
    const char* arg3_;
    const char* arg4_;
};