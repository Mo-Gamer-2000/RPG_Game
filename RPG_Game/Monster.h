#pragma once
#include "Header.h"

class Monster
{
public:
    int health;
    int attack;
    int gold;
    int XP;

    Monster(int h, int a, int g, int x) : health(h), attack(a), gold(g), XP(x) {}
};