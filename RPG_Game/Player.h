#pragma once
#include "Header.h"

class Player
{
public:
    // existing member variables and functions
    bool encounteredMonster_;
    // constructor and other member functions
    bool encounteredMonster() { return encounteredMonster_; }
    std::string name;
    std::string gender;
    std::string type;
    int health;
    int attack;
    int gold;
    int XP;
    int level;

    // constructor that initializes the player's attributes when a new player object is created
    Player(std::string n, std::string g, std::string t, int h, int a)
        : name(n), gender(g), type(t), health(h), attack(a), gold(0), XP(0), level(1) {}

    // function to attack a monster
    void attackMonster(std::unique_ptr<Monster>& m)
    {
        m->health -= attack;
        std::cout << "Player deals " << attack << " damage to the monster.\n";
        std::cout << "Monster has " << m->health << " health remaining.\n";
    }

    // function to bribe a monster
    void bribeMonster(std::unique_ptr<Monster>& m)
    {
        std::cout << "Player bribed the monster for " << m->gold << " gold.\n" << "You had a Meal with the Monster and gained 15 Health\n";
        gold -= m->gold;
        XP += m->XP / 2;
        health += m->health + 15;
    }

    // function to take damage
    void takeDamage(int damage)
    {
        health -= damage;
        std::cout << "Player takes " << damage << " damage.\n";
        std::cout << "Player has " << health << " health remaining.\n";
    }

    // function to earn rewards
    void reward(std::unique_ptr<Monster>& m)
    {
        gold += m->gold;
        XP += m->XP;
        health += m->health + 25;
        std::cout << "Player earns " << m->gold << " gold and " << m->XP << " XP.\n";
    }

    // function to display the player's information
    void displayBattleHUD()
    {
        std::cout << "\n";
        std::cout << "Player Information\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Gender: " << gender << "\n";
        std::cout << "Type: " << type << "\n";
        std::cout << "Health: " << health << "\n";
        std::cout << "Gold: " << gold << "\n";
        std::cout << "XP: " << XP << "\n";
        std::cout << "Level: " << level << "\n";
        std::cout << "\n";
    }

    // function to level up
    void levelUp()
    {
        if (XP >= 60)
        {
            XP = 0;
            level++;
            attack += 5;
            health += 15;
            std::cout << "Level Up!\n";
        }
    }

    // function to travel to different locations
    void travel(std::string destination)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 2);
        int random = dis(gen);
        if (random == 1)
        {
            std::cout << "Then suddenly from a bush a Monster faced Bob.\n";
            std::unique_ptr<Monster> monster = std::make_unique<Monster>(55, 12, 23, 15);
            while (monster->health > 0)
            {
                std::cout << "What do you want to do Bob?\n";
                std::cout << "1. Attack the Monster\n";
                std::cout << "2. Bribe the Monster\n";
                std::cout << "3. Run Away from the Monster\n";
                int choice;
                std::cin >> choice;
                if (choice == 1)
                {
                    attackMonster(monster);
                    takeDamage(monster->attack);
                    if (health <= 0)
                    {
                        std::cout << "You died!\n";
                        break;
                    }
                }
                else if (choice == 2)
                {
                    bribeMonster(monster);
                    break;
                }
                else
                {
                    std::cout << "You ran away from the monster like a coward!\n";
                    break;
                }
            }
            if (monster->health <= 0)
            {
                reward(monster);
                levelUp();
            }
        }
    }
};