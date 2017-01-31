/**
 * @author Lucas Street
 * @date 2/4/17
 * CS 11, Dave Harden
 * Assignment 2.2 - a2_2.cpp
 *
 * Calculates a frequency table for an inputted stream of characters, and displays the
 * table sorted from greatest frequency to lowest frequency.
 *
 * This program demonstrates the use of structs, arrays of structs, a sorting algorithm,
 * and character manipulation.
 */

#include <iostream>
#include <cstring>

using namespace std;


const int NUM_LETTERS = 26;

struct letter_frequency {
    char letter;
    int occurrences;
};


void initializeFrequencies(letter_frequency frequencies[]);

void incrementFrequency(letter_frequency frequencies[], char c);

void sortFrequencies(letter_frequency frequencies[]);

void swapFrequencies(int first, int second, letter_frequency frequencies[]);

int largestFrequency(const letter_frequency frequencies[], int start_index);

void printFrequencies(const letter_frequency frequencies[]);






/**
 * Create a letter frequency table, gather user input, calculate the frequency for each
 * inputted character, sort the frequencies, and display the results.
 */
int main() {
    letter_frequency frequencies[NUM_LETTERS];
    initializeFrequencies(frequencies);

    char input_char = '\0';
    while (input_char != '.') {
        cin >> input_char;
        incrementFrequency(frequencies, input_char);
    }

    sortFrequencies(frequencies);
    printFrequencies(frequencies);

    return 0;
}






/**
 * Initialize the frequency table with NUM_LETTERS characters, starting at 'a'. The
 * initial frequency of all characters is set to 0.
 *
 * @param frequencies an array of letter_frequency structs to initialize
 */
void initializeFrequencies(letter_frequency frequencies[]) {
    char c = 'a';
    for (int i = 0; i < NUM_LETTERS; ++i, ++c) {
        frequencies[i].letter = c;
        frequencies[i].occurrences = 0;
    }
}






/**
 * Increment the frequency of a specified character for a specified frequency table.
 *
 * @param frequencies the frequency table to modify
 * @param c the character whose frequency to increment
 */
void incrementFrequency(letter_frequency frequencies[], char c) {
    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (frequencies[i].letter == tolower(c)) {
            frequencies[i].occurrences++;
            break;
        }
    }
}






/**
 * Sort the specified frequency table in place, by character frequency.
 *
 * @param frequencies the frequency table to sort
 */
void sortFrequencies(letter_frequency frequencies[]) {
    for (int i = 0; i < NUM_LETTERS; ++i) {
        swapFrequencies(i, largestFrequency(frequencies, i), frequencies);
    }
}






/**
 * Swap two frequencies in a given frequency table.
 *
 * @param first the index of the first letter_frequency
 * @param second the index of the second letter_frequency
 * @param frequencies the frequency table to modify
 */
void swapFrequencies(int first, int second, letter_frequency frequencies[]) {
    if (first != second) {
        char first_letter = frequencies[first].letter;
        int first_occurrences = frequencies[first].occurrences;
        frequencies[first].letter = frequencies[second].letter;
        frequencies[first].occurrences = frequencies[second].occurrences;
        frequencies[second].letter = first_letter;
        frequencies[second].occurrences = first_occurrences;
    }
}






/**
 * Return the index of the frequency with the largest number of occurrences in a subset of
 * the specified frequency table.
 *
 * @param frequencies the frequency table to search
 * @param start_index the index to begin the search
 * @return the index of the frequency with the largest number of occurrences, from
 * [start_index..n-1]
 */
int largestFrequency(const letter_frequency frequencies[], int start_index) {
    int largest = start_index;
    for (int i = ++start_index; i < NUM_LETTERS; ++i) {
        if (frequencies[i].occurrences > frequencies[largest].occurrences) {
            largest = i;
        }
    }
    return largest;
}






/**
 * Display all letter frequencies in the given frequency table whose occurrences are
 * greater than 0.
 *
 * @param frequencies the frequency table to display
 */
void printFrequencies(const letter_frequency frequencies[]) {
    cout << "Letter:    Number of Occurrences:" << endl;
    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (frequencies[i].occurrences > 0) {
            cout << "     " << frequencies[i].letter << "     "
                 << frequencies[i].occurrences << endl;
        }
    }
}

// Output
/*
I don't mean to brag,
I don't mean to boast,
But we like hot butter on our breakfast toast. -SHG
Letter:    Number of Occurrences:
     t     12
     o     9
     a     7
     e     6
     n     5
     b     5
     r     4
     i     3
     s     3
     u     3
     k     2
     m     2
     d     2
     l     1
     f     1
     g     1
     h     1
     w     1
*/
