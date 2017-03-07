/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - balrog.h
 */

#ifndef CS_11_BALROG_H
#define CS_11_BALROG_H

#include "demon.h"

namespace cs_Creature {
    class balrog : public demon {
    public:
        balrog();
        balrog(int strength, int hitpoints);
        const char *getSpecies() const;
        int getDamage() const;
    };
}

#endif //CS_11_BALROG_H
