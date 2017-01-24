/**
 * @author Lucas Street
 * @date 1/31/17
 * CS 11, Dave Harden
 * Assignment 2.1 - a2_1.cpp
 *
 * This program demonstrates some basic algorithms on C-style strings, such as reversing
 * and replacing.
 */

#include <iostream>
#include <cstring>

using namespace std;

int lastIndexOf(const char *inString, char target);

void reverse(char *inString);

int replace(char *inString, char target, char replacementChar);

bool isPalindrome(const char *inString);

void toupper(char *inString);

int numLetters(const char *inString);

void test(bool condition, const char *msg);






/**
 * Thoroughly test the functions listed above. I use a function called 'test' to make
 * assertions about test results. Passing tests are indicated with a '.' to stdout.
 */
int main() {
    // lastIndexOf
    int testLastIndex1 = lastIndexOf("stringy string", 'i');
    test(testLastIndex1 == 11, "lastIndexOf for valid char is incorrect");
    int testLastIndex2 = lastIndexOf("stringaling", 'z');
    test(testLastIndex2 == -1, "lastIndexOf for invalid char is incorrect");
    int testLastIndex3 = lastIndexOf("STRING", 'g');
    int testLastIndex4 = lastIndexOf("STRING", 'G');
    test(testLastIndex3 == -1 && testLastIndex4 == 5,
         "case-sensitive lastIndexOf is incorrect");

    // reverse
    char testReverse[] = "string";
    reverse(testReverse);
    test(strcmp(testReverse, "gnirts") == 0, "string wasn't reversed correctly");

    // replace
    char testReplace[] = "aaabbbccc";
    int result = replace(testReplace, 'b', 'd');
    test(strcmp(testReplace, "aaadddccc") == 0, "valid string replacement is incorrect");
    test(result == 3, "number of valid char replacements is incorrect");
    int result2 = replace(testReplace, 'z', 'd');
    test(strcmp(testReplace, "aaadddccc") == 0, "invalid replacement is incorrect");
    test(result2 == 0, "invalid replacement count is nonzero");

    // isPalindrome
    char testIsPalindrome[] = "rotator";
    test(isPalindrome(testIsPalindrome), "isPalindrome result is incorrect");
    char testIsPalindrome2[] = "rot ato r";
    test(!isPalindrome(testIsPalindrome2),
         "isPalindrome result with whitespace is incorrect");
    char testIsPalindrome3[] = "roTaTOr";
    test(isPalindrome(testIsPalindrome3),
         "case-insensitive isPalindrome result is incorrect");

    // toupper
    char testToUpper[] = "string";
    toupper(testToUpper);
    test(strcmp(testToUpper, "STRING") == 0, "toupper result is incorrect");

    // numLetters
    char testNumLetters[] = "stringitystring";
    test(numLetters(testNumLetters) == 15, "numLetters result is incorrect");

    return 0;
}






/**
 * Return the last index of a target character in a given C-style string. If the
 * character is not found, return -1.
 *
 * @param inString the string to search
 * @param target the target character
 * @return the last index of the target character, or -1 if not found
 */
int lastIndexOf(const char *inString, char target) {
    int i = 0;
    int last_index = -1;
    while (inString[i] != '\0') {
        if (inString[i] == target) {
            last_index = i;
        }
        i++;
    }
    return last_index;
}






/**
 * Reverse a C-style string in place.
 *
 * @param inString the string to reverse
 */
void reverse(char *inString) {
    int length = numLetters(inString);
    for (int i = 0; i < length / 2; i++) {
        char temp = inString[i];
        inString[i] = inString[length - i - 1];
        inString[length - i - 1] = temp;
    }
}






/**
 * Replace all instances of a given character with a replacement character in a C-style
 * string, modifying the original string in place.
 *
 * @param inString the string on which to perform the replacement
 * @param target the character to be replaced
 * @param replacementChar the character to be substituted in place of the target character
 * @return the number of replacements performed
 */
int replace(char *inString, char target, char replacementChar) {
    int i = 0;
    int num_replacements = 0;
    while (inString[i] != '\0') {
        if (inString[i] == target) {
            inString[i] = replacementChar;
            num_replacements++;
        }
        i++;
    }

    return num_replacements;
}






/**
 * Determine whether the given C-style string is a case-insensitive palindrome.
 *
 * @param inString the string to test
 * @return a boolean indicating the result
 */
bool isPalindrome(const char *inString) {
    int length = numLetters(inString);
    for (int i = 0; i < length / 2; i++) {
        if (toupper(inString[i]) != toupper(inString[length - i - 1])) {
            return false;
        }
    }
    return true;
}






/**
 * Convert a C-style string to all uppercase characters.
 *
 * @param inString the string to convert to uppercase
 */
void toupper(char *inString) {
    int i = 0;
    while (inString[i] != '\0') {
        inString[i] = static_cast<char>(toupper(inString[i]));
        i++;
    }
}






/**
 * Determine the amount of characters in a string.
 *
 * @param inString the string to count
 * @return the length of the string
 */
int numLetters(const char *inString) {
    return static_cast<int>(strlen(inString));
}






/**
 * Test a boolean condition, printing a failure message if the condition is false.
 * Passing tests are indicated with a '.'
 *
 * @param condition the condition to test
 * @param msg a message to print in case of failure
 */
void test(bool condition, const char *msg) {
    if (condition) {
        cout << ".";
    } else {
        cout << endl << "Fail: " << msg << endl;
    }
}
