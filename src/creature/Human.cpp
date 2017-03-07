/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - Human.cpp
 */

#include "creature/Human.h"

namespace cs_Creature {
    Human::Human() {}






    Human::Human(int strength, int hitpoints) : Creature(strength, hitpoints) {}






    const char *Human::getSpecies() const {
        return "Human";
    }
}
