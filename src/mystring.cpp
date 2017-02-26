/**
 * @author Lucas Street
 * @date 2/26/17
 * CS 11, Dave Harden
 * Assignment 5.1 - mystring.cpp
 *
 * TODO: Documentation
 */

#include <iostream>
#include <cstring>
#include <cassert>
#include "mystring.h"

using namespace std;

namespace cs_mystring {
    MyString::MyString() {
        chars = new char[1];
        strcpy(chars, "");
    }






    MyString::MyString(const char *in_chars) {
        chars = new char[strlen(in_chars) + 1];
        strcpy(chars, in_chars);
    }






    MyString::MyString(const MyString &right) {
        chars = new char[strlen(right.chars) + 1];
        strcpy(chars, right.chars);
    }






    MyString::~MyString() {
        delete[] chars;
    }






    int MyString::length() const {
        return static_cast<int>(strlen(chars));
    }






    MyString MyString::operator=(const MyString &right) {
        if (this != &right) {
            delete[] chars;
            chars = new char[strlen(right.chars) + 1];
            strcpy(chars, right.chars);
        }
        return *this;
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(chars));
        return chars[index];
    }






    char &MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(chars));
        return chars[index];
    }






    bool operator==(const MyString &first, const MyString &second) {
        return strcmp(first.chars, second.chars) == 0;
    }






    bool operator!=(const MyString &first, const MyString &second) {
        return !(first == second);
    }






    bool operator<(const MyString &first, const MyString &second) {
        return strcmp(first.chars, second.chars) < 0;
    }






    bool operator<=(const MyString &first, const MyString &second) {
        return !(first > second);
    }






    bool operator>(const MyString &first, const MyString &second) {
        return strcmp(first.chars, second.chars) > 0;
    }






    bool operator>=(const MyString &first, const MyString &second) {
        return !(first < second);
    }






    ostream &operator<<(ostream &stream, const MyString &my_string) {
        stream << my_string.chars;
        return stream;
    }
}

// Output
/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing apple to
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing  to Banana
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing Banana to Banana
    Is left < right? false
    Is left <= right? true
    Is left > right? false
    Is left >= right? true
    Does left == right? true
    Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing why to wackity
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after sElf assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
*/
