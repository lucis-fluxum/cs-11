/**
 * @author Lucas Street
 * @date 3/14/17
 * CS 11, Dave Harden
 * Assignment 7 - a7.cpp
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "creature/Human.h"
#include "creature/Elf.h"
#include "creature/cyberdemon.h"
#include "creature/balrog.h"

using namespace std;
using namespace cs_Creature;

void battleArena(Creature &creature1, Creature &creature2);


int battleResult(Creature &creature1, Creature &creature2);


int getWinner(const Creature &creature1, const Creature &creature2, bool firstDead,
              bool secondDead);






int main() {
    srand(time(0));

    Human h1;
    Elf e1;
    cyberdemon c1;
    balrog b1;

    Human h(80, 150);
    Elf e(100, 110);
    cyberdemon c(50, 120);
    balrog b(80, 80);

    battleArena(h1, e1);
    battleArena(c1, b1);
    battleArena(e, c);
    battleArena(h, b);
}






void battleArena(Creature &creature1, Creature &creature2) {
    cout << "\n" << creature1.getSpecies() << ": " << creature1.getHitpoints() << " HP\n"
         << creature2.getSpecies() << ": " << creature2.getHitpoints() << " HP\n" << endl;

    switch (battleResult(creature1, creature2)) {
        case 0:
            cout << "Battle ends in a tie." << endl;
            break;
        case 1:
            cout << "The first creature (" << creature1.getSpecies() << ") wins!\n";
            break;
        case 2:
            cout << "The second creature (" << creature2.getSpecies() << ") wins!\n";
            break;
        default:
            battleArena(creature1, creature2);
            break;
    }
}






int battleResult(Creature &creature1, Creature &creature2) {
    int hp2 = creature2.getHitpoints() - creature1.getDamage();
    int hp1 = creature1.getHitpoints() - creature2.getDamage();
    creature1.setHitpoints(hp1);
    creature2.setHitpoints(hp2);
    bool firstDead = hp1 <= 0;
    bool secondDead = hp2 <= 0;
    return getWinner(creature1, creature2, firstDead, secondDead);
}






int getWinner(const Creature &creature1, const Creature &creature2, bool firstDead,
              bool secondDead) {
    if (firstDead && secondDead) {
        cout << "\nBoth creatures die!" << endl;
        return 0;
    } else if (!firstDead && secondDead) {
        cout << "\nThe second creature (" << creature2.getSpecies() << ") dies!" << endl;
        return 1;
    } else if (firstDead) {
        // secondDead is guaranteed to be false
        cout << "\nThe first creature (" << creature1.getSpecies() << ") dies!" << endl;
        return 2;
    } else {
        return -1;
    }
}

// Output
/*
Human: 10 HP
Elf: 10 HP

The Human attacks for 4 points!
The Elf attacks for 3 points!

Human: 7 HP
Elf: 6 HP

The Human attacks for 6 points!
The Elf attacks for 3 points!
Magical attack inflicts 3 additional damage points!

The second creature (Elf) dies!
The first creature (Human) wins!

cyberdemon: 10 HP
balrog: 10 HP

The cyberdemon attacks for 6 points!
The balrog attacks for 5 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 4 additional damage points!

The first creature (cyberdemon) dies!
The second creature (balrog) wins!

Elf: 110 HP
cyberdemon: 120 HP

The Elf attacks for 47 points!
Magical attack inflicts 47 additional damage points!
The cyberdemon attacks for 49 points!

Elf: 61 HP
cyberdemon: 26 HP

The Elf attacks for 69 points!
Magical attack inflicts 69 additional damage points!
The cyberdemon attacks for 37 points!

The second creature (cyberdemon) dies!
The first creature (Elf) wins!

Human: 150 HP
balrog: 80 HP

The Human attacks for 60 points!
The balrog attacks for 67 points!
Balrog speed attack inflicts 52 additional damage points!

Human: 31 HP
balrog: 20 HP

The Human attacks for 65 points!
The balrog attacks for 72 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 42 additional damage points!

Both creatures die!
Battle ends in a tie.
*/
