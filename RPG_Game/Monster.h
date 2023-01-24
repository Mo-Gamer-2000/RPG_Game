#pragma once
#include "Header.h"

class Monster
{
public:
    int health; // represents the monster's health points
    int attack; // represents the monster's attack points
    int gold; // represents the amount of gold the player will get when they defeat the monster
    int XP; // represents the amount of experience points the player will get when they defeat the monster

    // constructor that takes four integer arguments (h, a, g, x), and initializes the health, attack, gold and XP member variables with these arguments
    Monster(int h, int a, int g, int x) : health(h), attack(a), gold(g), XP(x) {}
};
