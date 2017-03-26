/**
 * @author Lucas Street
 * @date 3/25/17
 * CS 11, Dave Harden
 * Assignment 8.2 - a8_2.cpp
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "orderedpair.h"

using namespace std;
using namespace cs_pairs;

void testInt();

void testString();






int main() {
    testInt();
    testString();
    return 0;
}






void testInt() {
    int num1, num2;
    orderedPair<int> list[10];

    srand(time(0));
    cout << "default value: ";
    list[0].print();
    cout << endl;

    for (int i = 0; i < 10; i++) {
        list[i].setFirst(rand() % 50);
        list[i].setSecond(rand() % 50 + 50);
    }

    list[2] = list[0] + list[1];

    if (list[0] < list[1]) {
        list[0].print();
        cout << " is less than ";
        list[1].print();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        list[i].print();
        cout << endl;
    }

    cout << "Enter two numbers to use in an orderedPair. "
         << "Make sure they are different numbers: ";
    cin >> num1 >> num2;
    orderedPair<int> x;
    try {
        x.setFirst(num1);
        x.setSecond(num2);
    } catch (orderedPair<int>::DuplicateMemberError e) {
        x.setFirst(0);
        x.setSecond(0);
    }

    cout << "The resulting orderedPair: ";
    x.print();
    cout << endl;
}






void testString() {
    string str1, str2;
    orderedPair<string> list[10];

    srand(time(0));
    cout << "default value: ";
    list[0].print();
    cout << endl;

    for (int i = 0; i < 10; i++) {
        string empty = "";
        list[i].setFirst(empty + char('a' + rand() % 26));
        list[i].setSecond(empty + char('A' + rand() % 26));
    }

    list[2] = list[0] + list[1];

    if (list[0] < list[1]) {
        list[0].print();
        cout << " is less than ";
        list[1].print();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        list[i].print();
        cout << endl;
    }

    cout << "Enter two strings to use in an orderedPair. "
         << "Make sure they are different strings: ";
    cin >> str1 >> str2;
    orderedPair<string> x2;
    try {
        x2.setFirst(str1);
        x2.setSecond(str2);
    } catch (orderedPair<string>::DuplicateMemberError e) {
        x2.setFirst(string());
        x2.setSecond(string());
    }

    cout << "The resulting orderedPair: ";
    x2.print();
    cout << endl;
}

// Output
/*
default value: (0, 0)
(39, 77) is less than (48, 94)
(39, 77)
(48, 94)
(87, 171)
(37, 79)
(23, 72)
(4, 59)
(0, 60)
(36, 53)
(2, 53)
(16, 75)
Enter two numbers to use in an orderedPair. Make sure they are different numbers: 0 1
The resulting orderedPair: (0, 1)
default value: (, )
(a, H) is less than (d, N)
(a, H)
(d, N)
(ad, HN)
(h, F)
(u, U)
(t, C)
(u, T)
(d, V)
(z, Q)
(a, M)
Enter two strings to use in an orderedPair. Make sure they are different strings: abc str
The resulting orderedPair: (abc, str)
*/
