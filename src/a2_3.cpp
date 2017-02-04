/**
 * @author Lucas Street
 * @date 2/4/17
 * CS 11, Dave Harden
 * Assignment 2.3 - a2_3.cpp
 *
 * Stores a data set consisting of names and corresponding scores, inputted by the user,
 * then sorts the data by score and displays the results in descending order.
 *
 * This program demonstrates the use of dynamically allocated arrays of structs and a
 * sorting algorithm.
 */

#include <iostream>
#include <utility>

using namespace std;

struct highscore {
    int score;
    char name[24];
};

void initializeData(highscore scores[], int size);

void sortData(highscore scores[], int size);

int indexOfBiggest(const highscore scores[], int start_index, int size);

void displayData(const highscore scores[], int size);






/**
 * Fetch the number of scores, initialize an array of highscore structs to hold the names
 * and scores, fetch user input for each name and score, then sort and display the data.
 */
int main() {
    cout << "How many scores will you enter?: ";
    int num_scores;
    cin >> num_scores;

    highscore *scores = new highscore[num_scores];

    initializeData(scores, num_scores);
    sortData(scores, num_scores);
    displayData(scores, num_scores);

    return 0;
}






/**
 * Populate the scores array with user-inputted names and scores.
 *
 * @param scores the array of highscore structs to modify
 * @param size the length of the scores array
 */
void initializeData(highscore scores[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> scores[i].name;
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i].score;
    }
}






/**
 * Sort the given highscore array in place, by scores.
 *
 * @param scores the array of highscore structs to sort
 * @param size the length of the scores array
 */
void sortData(highscore scores[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int largest_index = indexOfBiggest(scores, i, size);
        swap(scores[i], scores[largest_index]);
    }
}






/**
 * Find the index of the largest score in scores[start_index..size-1]
 *
 * @param scores the array of highscore structs to search
 * @param start_index the index to begin the search
 * @param size the length of the scores array
 * @return the index of the largest score in the subset scores[start_index..size-1]
 */
int indexOfBiggest(const highscore scores[], int start_index, int size) {
    int target_index = start_index;
    for (int i = start_index + 1; i < size; ++i) {
        if (scores[i].score > scores[target_index].score) {
            target_index = i;
        }
    }
    return target_index;
}






/**
 * Display the data in the given array of highscore structs.
 *
 * @param scores the array of highscore structs to display
 * @param size the length of the scores array
 */
void displayData(const highscore scores[], int size) {
    cout << "\nTop Scorers:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    }
}

// Output
/*
How many scores will you enter?: 3
Enter the name for score #1: A
Enter the score for score #1: 10
Enter the name for score #2: B
Enter the score for score #2: 25
Enter the name for score #3: C
Enter the score for score #3: 50

Top Scorers:
C: 50
B: 25
A: 10
*/
