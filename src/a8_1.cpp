/**
 * @author Lucas Street
 * @date 3/25/17
 * CS 11, Dave Harden
 * Assignment 8.1 - a8_1.cpp
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct highscore {
    int score;
    char name[24];
};

void initializeData(vector<highscore> &scores);

void sortData(vector<highscore> &scores);

vector<highscore>::iterator
largestScore(const vector<highscore> &scores, vector<highscore>::iterator current);

void displayData(const vector<highscore> &scores);






int main() {
    cout << "How many scores will you enter?: ";
    vector<highscore>::size_type num_scores;
    cin >> num_scores;

    vector<highscore> scores(num_scores);

    initializeData(scores);
    sortData(scores);
    displayData(scores);

    return 0;
}






void initializeData(vector<highscore> &scores) {
    for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); ++i) {
        cout << "Enter the name for score #" << i - scores.begin() + 1 << ": ";
        cin >> i->name;
        cout << "Enter the score for score #" << i - scores.begin() + 1 << ": ";
        cin >> i->score;
    }
}






void sortData(vector<highscore> &scores) {
    for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); ++i) {
        vector<highscore>::iterator largest = largestScore(scores, i);
        swap(i->name, largest->name);
        swap(i->score, largest->score);
    }
}






vector<highscore>::iterator
largestScore(const vector<highscore> &scores, vector<highscore>::iterator current) {
    vector<highscore>::iterator target(current);
    current++;
    for (; current != scores.end(); ++current) {
        if (current->score > target->score) {
            target = current;
        }
    }
    return target;
}






void displayData(const vector<highscore> &scores) {
    cout << "\nTop Scorers:" << endl;
    for (vector<highscore>::const_iterator i = scores.begin(); i != scores.end(); ++i) {
        cout << i->name << ": " << i->score << endl;
    }
}

// Output
/*
How many scores will you enter?: 6
Enter the name for score #1: a
Enter the score for score #1: 1
Enter the name for score #2: j
Enter the score for score #2: 2
Enter the name for score #3: d
Enter the score for score #3: 3
Enter the name for score #4: g
Enter the score for score #4: 4
Enter the name for score #5: h
Enter the score for score #5: 5
Enter the name for score #6: p
Enter the score for score #6: 6

Top Scorers:
p: 6
h: 5
g: 4
d: 3
j: 2
a: 1
*/
