/**
 * @author Lucas Street
 * @date 4/3/17
 * CS 11, Dave Harden
 * Assignment 9.1 - a9_1.cpp
 */

#include <iostream>
#include <cassert>
#include "sequence.h"

using namespace std;
using namespace cs_sequence;






int main() {
    sequence s;
    assert(s.size() == 0 && !s.is_item());

    for (int i = 1; i <= 10; i++) {
        s.insert(i);
        assert(s.current() == i);
    }
    assert(s.size() == 10);

    for (s.start(); s.is_item(); s.advance()) {
        cout << s.current() << " ";
    }

    assert(!s.is_item());
    s.insert(100);
    assert(s.current() == 100);

    return 0;
}
