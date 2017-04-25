/**
 * @author Lucas Street
 * @date 4/24/17
 * CS 11, Dave Harden
 * Assignment 12.1 - a12_1.cpp
 *
 * Uses recursion to reverse C-strings or parts of C-strings.
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using std::size_t;
using std::cout;
using std::endl;

void reverseWithinBounds(char *chars, size_t begin, size_t end);

void reverseCstring(char *string);

void assertEqual(const char *expected, const char *actual);






/**
 * Performs tests on reverseWithinBounds and reverseCstring, using assertEqual to test
 * each case. Successful tests will output a '.', failures will output an 'X'
 */
int main() {
    char *string = new char[7];
    std::strcpy(string, "abcdef");

    reverseWithinBounds(string, 2, 10);
    assertEqual("abcdef", string);
    reverseWithinBounds(string, 4, 2);
    assertEqual("abcdef", string);
    reverseWithinBounds(string, 2, 4);
    assertEqual("abedcf", string);
    reverseWithinBounds(string, 3, 3);
    assertEqual("abedcf", string);
    reverseCstring(string);
    assertEqual("fcdeba", string);
    reverseCstring(string);
    assertEqual("abedcf", string);

    return 0;
}






/**
 * Reverses a C-string from a specified beginning to a specified ending point, inclusive.
 *
 * @param chars the array of chars to operate on
 * @param begin the index to begin the reverse
 * @param end the index to end the reverse
 */
void reverseWithinBounds(char *chars, size_t begin, size_t end) {
    size_t length = std::strlen(chars);
    if (begin < end && begin < length && end < length) {
        std::swap(chars[begin], chars[end]);
        reverseWithinBounds(chars, begin + 1, end - 1);
    } else {
        return;
    }
}






/**
 * Reverses an entire C-string, from 0 to length-1
 *
 * @param string the array of chars to reverse
 */
void reverseCstring(char *string) {
    reverseWithinBounds(string, 0, std::strlen(string) - 1);
}






/**
 * Asserts both arguments are equal C-strings, and if not, prints a failure message
 *
 * @param expected the expected value
 * @param actual the actual value
 */
void assertEqual(const char *expected, const char *actual) {
    if (std::strcmp(expected, actual) == 0) {
        cout << ".";
    } else {
        cout << "X\n" << actual << " =/= " << expected << endl;
    }
}

// Output
/*
......
*/
