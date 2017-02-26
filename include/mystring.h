/**
 * @author Lucas Street
 * @date 2/26/17
 * CS 11, Dave Harden
 * Assignment 5.1 - mystring.h
 *
 * TODO: Documentation
 */

#ifndef CS_11_MYSTRING_H
#define CS_11_MYSTRING_H

#include <iostream>

using std::ostream;

namespace cs_mystring {
    class MyString {
    private:
        char *chars;
    public:
        // Constructors/Destructors
        MyString();
        MyString(const char *c_string);
        MyString(const MyString &other);
        ~MyString();

        // Instance methods
        int length() const;

        // Operators
        MyString operator=(const MyString &right);
        char operator[](int index) const;
        char &operator[](int index);
        friend bool operator==(const MyString &first, const MyString &second);
        friend bool operator!=(const MyString &first, const MyString &second);
        friend bool operator<(const MyString &first, const MyString &second);
        friend bool operator<=(const MyString &first, const MyString &second);
        friend bool operator>(const MyString &first, const MyString &second);
        friend bool operator>=(const MyString &first, const MyString &second);
        friend ostream &operator<<(ostream &stream, const MyString &my_string);
    };
}

#endif //CS_11_MYSTRING_H
