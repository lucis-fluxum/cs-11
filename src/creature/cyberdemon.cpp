/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - cyberdemon.cpp
 */

#include "creature/cyberdemon.h"

namespace cs_Creature {
    cyberdemon::cyberdemon() {}






    cyberdemon::cyberdemon(int strength, int hitpoints) : demon(strength, hitpoints) {}






    const char *cyberdemon::getSpecies() const {
        return "cyberdemon";
    }
}
