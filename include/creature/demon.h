/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - demon.h
 */

#ifndef CS_11_DEMON_H
#define CS_11_DEMON_H

#include "Creature.h"

namespace cs_Creature {
    class demon : public Creature {
    public:
        demon();
        demon(int strength, int hitpoints);
        virtual const char *getSpecies() const;
        virtual int getDamage() const;
    };

}
#endif //CS_11_DEMON_H
