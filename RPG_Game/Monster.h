#pragma once
#include "Header.h"

class Monster {
public:
    // Constructor for the Monster class
    Monster() {
        health = 50;
        attackPower = 15;
    }

    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    void setHealth(int value) { health = value; }

private:
    int health;
    int attackPower;
};