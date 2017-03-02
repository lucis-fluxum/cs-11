/**
 * @author Lucas Street
 * @date 3/2/17
 * CS 11, Dave Harden
 * Assignment 6.1 - mystring.h
 *
 * A MyString stores a dynamically allocated C-string. MyStrings can be compared,
 * concatenated, and inserted into and extracted from streams.
 * 
 * MyString();
 * @pre none
 * @post the constructed MyString has "" for its C-string value
 *
 * MyString(const char *c_string);
 * @pre none
 * @post the constructed MyString's C-string member points to a copy of the data pointed
 * to by the c_string parameter
 *
 * MyString(const MyString &other);
 * @pre other is a valid MyString
 * @post the constructed MyString is a deep copy of the given MyString
 *
 * ~MyString();
 * @pre the calling object's C-string member is valid
 * @post the memory for the calling object's C-string member has been deallocated
 *
 * int length() const;
 * @pre none
 * @post returns the length of the calling object's C-string member
 *
 * void read(istream &stream, char delimiter);
 * @pre stream must be valid/readable
 * @post 127 characters maximum have been read from the stream up to but not including the
 * given delimiter, and copied into the calling object's C-string member
 *
 * MyString operator=(const MyString &right);
 * @pre none
 * @post the calling object is equal to a deep copy of the given MyString
 *
 * char operator[](int index) const;
 * @pre 0 <= index < length()
 * @post returns the character at the given index of the calling object's C-string member
 *
 * char &operator[](int index);
 * @pre 0 <= index < length()
 * @post returns a mutable reference to the character at the given index of the calling
 * object's C-string member
 *
 * friend MyString operator+(const MyString &first, const MyString &second);
 * @pre none
 * @post returns a MyString with a C-string member equal to the concatenation of both the
 * given MyStrings' C-string members
 *
 * friend MyString operator+=(MyString &first, const MyString &second);
 * @pre second is either a MyString or C-string
 * @post the C-string member of first is expanded to include the data from the C-string
 * member of second
 *
 * friend bool operator==(const MyString &first, const MyString &second);
 * @pre the arguments are either MyStrings or C-strings
 * @post returns whether the two MyString objects are equal in value
 *
 * friend bool operator!=(const MyString &first, const MyString &second);
 * @pre the arguments are either MyStrings or C-strings
 * @post returns whether the two MyString objects are not equal in value
 *
 * friend bool operator<(const MyString &first, const MyString &second);
 * @pre the arguments are either MyStrings or C-strings
 * @post returns whether the first MyString is alphabetically less than the second
 *
 * friend bool operator<=(const MyString &first, const MyString &second);
 * @pre the arguments are either MyStrings or C-strings
 * @post returns whether the first MyString is alphabetically less than or equal to the
 * second
 *
 * friend bool operator>(const MyString &first, const MyString &second);
 * @pre the arguments are either MyStrings or C-strings
 * @post returns whether the first MyString is alphabetically greater than the second
 *
 * friend bool operator>=(const MyString &first, const MyString &second);
 * @pre the arguments are either MyStrings or C-strings
 * @post returns whether the first MyString is alphabetically greater than or equal to the
 * second
 *
 * friend ostream &operator<<(ostream &stream, const MyString &my_string);
 * @pre none
 * @post the contents of my_string's C-string member are inserted into the given stream
 *
 * friend istream &operator>>(istream &stream, MyString &my_string);
 * @pre none
 * @post the data from the input stream is copied into my_string's C-string member, with
 * leading whitespace removed
 */

#ifndef CS_11_MYSTRING_H
#define CS_11_MYSTRING_H

#include <iostream>

using std::ostream;
using std::istream;

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
        void read(istream &stream, char delimiter);

        // Operators
        MyString operator=(const MyString &right);
        char operator[](int index) const;
        char &operator[](int index);
        friend MyString operator+(const MyString &first, const MyString &second);
        friend MyString operator+=(MyString &first, const MyString &second);
        friend bool operator==(const MyString &first, const MyString &second);
        friend bool operator!=(const MyString &first, const MyString &second);
        friend bool operator<(const MyString &first, const MyString &second);
        friend bool operator<=(const MyString &first, const MyString &second);
        friend bool operator>(const MyString &first, const MyString &second);
        friend bool operator>=(const MyString &first, const MyString &second);
        friend ostream &operator<<(ostream &stream, const MyString &my_string);
        friend istream &operator>>(istream &stream, MyString &my_string);
    };
}

#endif //CS_11_MYSTRING_H
