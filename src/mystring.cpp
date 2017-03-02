/**
 * @author Lucas Street
 * @date 3/2/17
 * CS 11, Dave Harden
 * Assignment 6.1 - mystring.cpp
 *
 * MyString objects always contain a pointer to a valid C-string.
 *
 * Private data members:
 *   chars: a pointer that references the content of the MyString
 *
 * chars is assigned to dynamically allocated character arrays as the contents of MyString
 * change.
 */

#include <iostream>
#include <cstring>
#include <cassert>
#include "mystring.h"

using namespace std;

namespace cs_mystring {
    const int MAX_USER_INPUT_SIZE = 128;






    MyString::MyString() {
        chars = new char[1];
        strcpy(chars, "");
    }






    MyString::MyString(const char *c_string) {
        chars = new char[strlen(c_string) + 1];
        strcpy(chars, c_string);
    }






    MyString::MyString(const MyString &other) {
        chars = new char[strlen(other.chars) + 1];
        strcpy(chars, other.chars);
    }






    MyString::~MyString() {
        delete[] chars;
    }






    int MyString::length() const {
        return static_cast<int>(strlen(chars));
    }






    void MyString::read(istream &stream, char delimiter) {
        char *temp_str = new char[MAX_USER_INPUT_SIZE];
        stream.getline(temp_str, MAX_USER_INPUT_SIZE, delimiter);

        delete[] chars;
        chars = new char[strlen(temp_str) + 1];
        strcpy(chars, temp_str);
        delete[] temp_str;
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






    MyString operator+(const MyString &first, const MyString &second) {
        char *concatenated = new char[first.length() + second.length() + 1];
        strcpy(concatenated, first.chars);
        strcat(concatenated, second.chars);
        MyString result(concatenated);
        delete[] concatenated;
        return result;
    }






    MyString operator+=(MyString &first, const MyString &second) {
        first = first + second;
        return first;
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






    istream &operator>>(istream &stream, MyString &my_string) {
        char *temp_str = new char[MAX_USER_INPUT_SIZE];
        stream >> temp_str;

        delete[] my_string.chars;
        my_string.chars = new char[strlen(temp_str) + 1];
        strcpy(my_string.chars, temp_str);
        delete[] temp_str;

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

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

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

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
*/
