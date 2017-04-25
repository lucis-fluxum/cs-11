/**
 * @author Lucas Street
 * @date 4/24/17
 * CS 11, Dave Harden
 * Assignment 12.2 - a12_2.cpp
 *
 * Uses recursion to test if an arbitrary number of user-entered MyStrings are
 * palindromes.
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "mystring.h"

using namespace std;
using cs_mystring::MyString;

bool isAPalindrome(const MyString &string, int begin, int end);






/**
 * Keep asking the user for strings to test for palindromes, until the user enters 'quit'.
 */
int main() {
    MyString input;
    while (true) {
        cout << "Enter a string: ";
        input.read(cin, '\n');
        if (input == "quit") {
            break;
        } else if (isAPalindrome(input, 0, input.length() - 1)) {
            cout << input << " is a palindrome" << endl;
        } else {
            cout << input << " is not a palindrome" << endl;
        }
    }

    return 0;
}






/**
 * Determines whether the given MyString is a palindrome between the indices 'begin' and
 * 'end', inclusive.
 *
 * @param string the string to test
 * @param begin the index at which to begin the analysis
 * @param end the index at which to end the analysis
 * @return a boolean indicating whether the given MyString is a palindrome
 */
bool isAPalindrome(const MyString &string, int begin, int end) {
    if (begin >= end) {
        return true;
    } else {
        bool charAtBegin = !(ispunct(string[begin]) || isspace(string[begin]));
        bool charAtEnd = !(ispunct(string[end]) || isspace(string[end]));
        if (charAtBegin && charAtEnd) {
            if (toupper(string[begin]) == toupper(string[end])) {
                return isAPalindrome(string, begin + 1, end - 1);
            } else {
                return false;
            }
        } else {
            if (!charAtBegin) {
                begin++;
            }
            if (!charAtEnd) {
                end--;
            }
            return isAPalindrome(string, begin, end);
        }
    }
}

// Output
/*
Enter a string: A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal... Panama!
A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal... Panama! is a palindrome
Enter a string: ten ANIma.ls,.!I sl.am    in ..a,.,,neT
ten ANIma.ls,.!I sl.am    in ..a,.,,neT is a palindrome
Enter a string: rotator
rotator is a palindrome
Enter a string: socks
socks is not a palindrome
Enter a string: a
a is a palindrome
Enter a string: quit
*/
