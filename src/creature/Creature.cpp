/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - Creature.cpp
 */

#include <iostream>
#include <cstdlib>
#include "creature/Creature.h"

using namespace std;

namespace cs_Creature {
    Creature::Creature() {
        strength = 10;
        hitpoints = 10;
    }






    Creature::Creature(int strength, int hitpoints) {
        this->strength = strength;
        this->hitpoints = hitpoints;
    }






    int Creature::getDamage() const {
        int damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }






    int Creature::getStrength() const {
        return strength;
    }






    int Creature::getHitpoints() const {
        return hitpoints;
    }






    void Creature::setStrength(int strength) {
        this->strength = strength;
    }






    void Creature::setHitpoints(int hitpoints) {
        this->hitpoints = hitpoints;
    }
}
