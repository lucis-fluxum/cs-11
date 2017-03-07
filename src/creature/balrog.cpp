/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - balrog.cpp
 */

#include <iostream>
#include <cstdlib>
#include "creature/balrog.h"

using namespace std;

namespace cs_Creature {
    balrog::balrog() {}






    balrog::balrog(int strength, int hitpoints) : demon(strength, hitpoints) {}






    const char *balrog::getSpecies() const {
        return "balrog";
    }






    int balrog::getDamage() const {
        int damage = demon::getDamage();
        int damage2 = (rand() % getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
}
