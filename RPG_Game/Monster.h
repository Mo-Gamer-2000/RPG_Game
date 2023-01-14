#pragma once

class Monster {
public:
    Monster() {
        health = 50;
        attackPower = 5;
        defense = 2;
    }
    int getHealth() { return health; }
    int getAttackPower() { return attackPower; }
    int getDefense() { return defense; }
    void setHealth(int newHealth) { health = newHealth; }

private:
    int health;
    int attackPower;
    int defense;
};
