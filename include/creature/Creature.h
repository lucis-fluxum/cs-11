/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - Creature.h
 */

#ifndef CS_11_CREATURE_H
#define CS_11_CREATURE_H

#include <string>

using std::string;

namespace cs_Creature {
    class Creature {
    private:
        int strength;
        int hitpoints;
    public:
        Creature();
        Creature(int strength, int hitpoints);
        virtual const char *getSpecies() const = 0;
        virtual int getDamage() const;
        int getStrength() const;
        int getHitpoints() const;
        void setStrength(int strength);
        void setHitpoints(int hitpoints);
    };
}

#endif 
