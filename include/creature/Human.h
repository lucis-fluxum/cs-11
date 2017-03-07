/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - Human.h
 */

#ifndef CS_11_HUMAN_H
#define CS_11_HUMAN_H

#include "Creature.h"

namespace cs_Creature {
    class Human : public Creature {
    public:
        Human();
        Human(int strength, int hitpoints);
        const char *getSpecies() const;
    };
}

#endif //CS_11_HUMAN_H
