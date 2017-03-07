/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - Elf.cpp
 */

#include <iostream>
#include <cstdlib>
#include "creature/Elf.h"

using namespace std;

namespace cs_Creature {
    Elf::Elf() {}






    Elf::Elf(int strength, int hitpoints) : Creature(strength, hitpoints) {}






    const char *Elf::getSpecies() const {
        return "Elf";
    }






    int Elf::getDamage() const {
        int damage = Creature::getDamage();
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!"
                 << endl;
            damage *= 2;
        }
        return damage;
    }
}
