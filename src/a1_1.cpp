/**
 * @author Lucas Street
 * @date 1/17/17
 * CS 11, Dave Harden
 * Assignment 1.1 - a1_1.cpp
 *
 * Performs simple tasks with pointers, such as swapping values of variables or array elements.
 */

#include <iostream>

using std::cout;
using std::endl;

void noNegatives(int *x);

void swap(int *first, int *second);






/**
 * Demonstrates basic pointer operations, including array manipulation.
 */
int main() {
    int x, y;
    int *p1 = &x;
    *p1 = 99;
    cout << "x is: " << x << endl;
    cout << "x is: " << *p1 << endl;
    p1 = &y;
    *p1 = -300;

    int *p2 = &x;
    int temp = *p2;
    *p2 = *p1;
    *p1 = temp;

    noNegatives(&x);
    noNegatives(&y);

    cout << "x is: " << *p2 << endl;
    p2 = &y;
    cout << "y is: " << *p2 << endl;

    int a[2];
    p2 = a;
    p2[0] = x;
    p2[1] = y;

    cout << "&a[0] is: " << p2 << endl;
    cout << "&a[1] is: " << ++p2 << endl;

    p1 = a;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "a[0] is: " << a[0] << endl;
    cout << "a[1] is: " << a[1] << endl;

    swap(&x, &y);
    cout << "x is: " << x << endl;
    cout << "y is: " << y << endl;

    swap(&a[0], &a[1]);
    cout << "a[0] is: " << a[0] << endl;
    cout << "a[1] is: " << a[1] << endl;

    return 0;
}






/**
 * Changes the value of a variable to zero if it is negative.
 *
 * @param x a pointer to the value to test
 */
void noNegatives(int *x) {
    if (*x < 0) {
        *x = 0;
    }
}






/**
 * Swaps the values of its arguments.
 *
 * @param first a pointer to the first value
 * @param second a pointer to the second value
 */
void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Output
/*
x is: 99
x is: 99
x is: 0
y is: 99
&a[0] is: 0x7fffab775490
&a[1] is: 0x7fffab775494
a[0] is: 99
a[1] is: 0
x is: 99
y is: 0
a[0] is: 0
a[1] is: 99
*/
