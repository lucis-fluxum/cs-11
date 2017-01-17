/**
 * @author Lucas Street
 * @date 1/24/17
 * CS 11, Dave Harden
 * Assignment 1.2 - a1_2.cpp
 *
 * Stores a data set consisting of names and corresponding scores, inputted by the user,
 * then sorts the data by score and displays the results in descending order.
 *
 * This program demonstrates the use of dynamically allocated arrays and a sorting
 * algorithm.
 */

#include <iostream>
#include <string>

using namespace std;

void initializeArrays(string names[], int scores[], int size);

void sortData(string names[], int scores[], int size);

int indexOfBiggest(const int list[], int startingIndex, int numItems);

void displayData(const string names[], const int scores[], int size);






/**
 * Fetches the number of scores, initializes two arrays to hold the names and scores,
 * fetches user input for each name and score, then sorts and displays the data.
 */
int main() {
    cout << "How many scores will you enter?: ";
    int num_scores;
    cin >> num_scores;

    string *names = new string[num_scores];
    int *scores = new int[num_scores];

    initializeArrays(names, scores, num_scores);
    sortData(names, scores, num_scores);
    displayData(names, scores, num_scores);

    return 0;
}






/**
 * Populate the names and scores array with user input.
 *
 * @pre The given names and scores arrays are empty, size is equal to the length of both
 * names and scores.
 * @post The given names and scores arrays contain user-inputted values corresponding to
 * name-score pairs.
 *
 * @param names the array to insert the names into
 * @param scores the array to insert the scores into
 * @param size the length of both names and scores
 */
void initializeArrays(string names[], int scores[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i];
    }
}






/**
 * Sorts the data in both names and scores, in descending order.
 *
 * @pre The given names and scores arrays are populated, size is equal to the length of
 * both names and scores.
 * @post The scores array is sorted such that its values are in descending order, and the
 * names array is sorted such that each name still corresponds to each score in the scores
 * array.
 *
 * @param names the populated array of names to sort
 * @param scores the populated array of scores to sort
 * @param size the length of both names and scores
 */
void sortData(string names[], int scores[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int target_index = indexOfBiggest(scores, i, size);
        string temp_name = names[target_index];
        int temp_score = scores[target_index];
        names[target_index] = names[i];
        scores[target_index] = scores[i];
        names[i] = temp_name;
        scores[i] = temp_score;
    }
}






/**
 * Locates the index of the largest integer value in a subset of a given list.
 *
 * @pre startingIndex is within the array index bounds of the given list.
 *
 * @param list the list to search
 * @param startingIndex the index at which to begin the search
 * @param numItems the length of the list
 * @return the index of the largest value in list[startingIndex..numItems-1]
 */
int indexOfBiggest(const int list[], int startingIndex, int numItems) {
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++) {
        if (list[count] > list[targetIndex]) {
            targetIndex = count;
        }
    }

    return targetIndex;
}






/**
 * Displays the data in the given names and scores arrays.
 *
 * @param names the array of names to print
 * @param scores the array of scores to print
 * @param size the length of both names and scores
 */
void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop Scorers:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}

// Output
/*
How many scores will you enter?: 5
Enter the name for score #1: A
Enter the score for score #1: 2500
Enter the name for score #2: B
Enter the score for score #2: 1000
Enter the name for score #3: C
Enter the score for score #3: 200
Enter the name for score #4: D
Enter the score for score #4: 3120
Enter the name for score #5: E
Enter the score for score #5: 9999

Top Scorers:
E: 9999
D: 3120
A: 2500
B: 1000
C: 200
*/
