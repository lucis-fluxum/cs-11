/**
 * @author Lucas Street
 * @date 4/24/17
 * CS 11, Dave Harden
 * Assignment 12.3 - a12_3.cpp
 *
 * Uses recursion in an application of selection sort on lists of integers.
 */

#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

void sort_list(int *list, int size);

int index_of_smallest(const int *list, int size);

void print_array(const int *array, int size);






/**
 * Sort a simple list of integers to test the recursive sorting function below.
 */
int main() {
    int list[] = {3, 2, 1, 5, 4};
    const int length = 5;

    cout << "before: ";
    print_array(list, length);
    sort_list(list, length);
    cout << "after: ";
    print_array(list, length);

    return 0;
}






/**
 * Sorts the given array using a recursive style of selection sort.
 *
 * @param list the list of integers to sort
 * @param size the length of the list
 */
void sort_list(int *list, int size) {
    if (size > 1) {
        std::swap(list[0], list[index_of_smallest(list, size)]);
        list++;
        size--;
        sort_list(list, size);
    } else {
        return;
    }
}






/**
 * Locates the index of the smallest integer value in a given list.
 *
 * @param list the list to search
 * @param size the length of the list
 * @return the index of the smallest value in list[0..size-1]
 */
int index_of_smallest(const int *list, int size) {
    int min = 0;
    for (int i = 1; i < size; ++i) {
        if (list[i] < list[min]) {
            min = i;
        }
    }
    return min;
}






/**
 * Prints the contents of an int array.
 *
 * @param array the array to print
 * @param size the length of the array
 */
void print_array(const int *array, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

// Output
/*
before: [ 3 2 1 5 4 ]
after: [ 1 2 3 4 5 ]
*/
