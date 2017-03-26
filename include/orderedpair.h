/**
 * @author Lucas Street
 * @date 3/25/17
 * CS 11, Dave Harden
 * Assignment 8.2 - orderedpair.h
 */

#ifndef CS_11_ORDEREDPAIR_H
#define CS_11_ORDEREDPAIR_H

#include <iostream>

using std::cout;

/* precondition for setFirst and setSecond: the values of first and second cannot be equal,
except when they are both equal to DEFAULT_VALUE.
*/

namespace cs_pairs {
    template<class T>
    class orderedPair {
    public:
        static const T DEFAULT_VALUE;

        class DuplicateMemberError {
        };

        orderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE);
        void setFirst(const T &newFirst);
        void setSecond(const T &newSecond);
        T getFirst() const;
        T getSecond() const;
        orderedPair operator+(const orderedPair &right) const;
        bool operator<(const orderedPair &right) const;
        void print() const;
    private:
        T first;
        T second;
    };

    template<class T>
    const T orderedPair<T>::DEFAULT_VALUE = T();
}

#include "../src/orderedpair.cpp"

#endif //CS_11_ORDEREDPAIR_H
