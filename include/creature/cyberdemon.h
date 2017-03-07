/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - cyberdemon.h
 */

#ifndef CS_11_CYBERDEMON_H
#define CS_11_CYBERDEMON_H

#include "demon.h"

namespace cs_Creature {
    class cyberdemon : public demon {
    public:
        cyberdemon();
        cyberdemon(int strength, int hitpoints);
        const char *getSpecies() const;
    };
}

#endif //CS_11_CYBERDEMON_H
