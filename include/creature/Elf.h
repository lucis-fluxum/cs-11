/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - Elf.h
 */

#ifndef CS_11_ELF_H
#define CS_11_ELF_H

#include "Creature.h"

namespace cs_Creature {
    class Elf : public Creature {
    public:
        Elf();
        Elf(int strength, int hitpoints);
        const char *getSpecies() const;
        int getDamage() const;
    };
}

#endif //CS_11_ELF_H
