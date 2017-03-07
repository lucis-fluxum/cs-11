/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - demon.cpp
 */

#include <iostream>
#include <cstdlib>
#include "creature/demon.h"

using namespace std;

namespace cs_Creature {
    demon::demon() {}






    demon::demon(int strength, int hitpoints) : Creature(strength, hitpoints) {}






    const char *demon::getSpecies() const {
        return "demon";
    }






    int demon::getDamage() const {
        int damage = Creature::getDamage();
        if (rand() % 4 == 0) {
            damage += 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
}
