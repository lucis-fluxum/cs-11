/**
 * @author Lucas Street
 * @date 2/17/17
 * CS 11, Dave Harden
 * Assignment 4.1 - Fraction.h
 *
 * A Fraction stores a quotient of two numbers in the form NUMERATOR/DENOMINATOR.
 * Fractions may be added, subtracted, multiplied, and divided by each other and by
 * compatible types. Fractions may be inserted into output streams and extracted from
 * input streams.
 *
 * Fraction(int numerator = 0, int denominator = 1);
 * @pre the given denominator != 0
 * @post the constructed fraction has a value of 0/1
 *
 * Fraction operator++();
 * @pre the calling object is a valid Fraction
 * @post the calling object has been increased by 1 and the result of the expression is
 * the newly modified calling object
 *
 * Fraction operator++(int);
 * @pre the calling object is a valid Fraction
 * @post the calling object has been increased by 1 and the result of the expression is
 * the previous value of the calling object
 *
 * Fraction operator--();
 * @pre the calling object is a valid Fraction
 * @post the calling object has been decreased by 1 and the result of the expression is
 * the newly modified calling object
 *
 * Fraction operator--(int);
 * @pre the calling object is a valid Fraction
 * @post the calling object has been decreased by 1 and the result of the expression is
 * the previous value of the calling object
 *
 * friend Fraction operator+(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the value returned is a Fraction with a value equal to the sum of the calling
 * Fraction and the argument
 *
 * friend Fraction operator+=(Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the first argument has been increased by the value of the second argument, and
 * the value returned is a Fraction with a value equal to the sum of the first and the
 * second argument
 *
 * friend Fraction operator-(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the value returned is a Fraction with a value equal to the difference between the
 * first and the second argument
 *
 * friend Fraction operator-=(Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the first argument has been decreased by the value of the second argument, and
 * the value returned is a Fraction with a value equal to the difference between the
 * first and the second argument
 *
 * friend Fraction operator*(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the value returned is a Fraction with a value equal to the product of the first
 * and the second argument
 *
 * friend Fraction operator*=(Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the first argument has been multiplied by the value of the second argument, and
 * the value returned is a Fraction with a value equal to the product of the first and the
 * second argument
 *
 * friend Fraction operator/(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the value returned is a Fraction with a value equal to the quotient of the first
 * and the second argument
 *
 * friend Fraction operator/=(Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post the first argument has been divided by the value of the second argument, and
 * the value returned is a Fraction with a value equal to the quotient of the first and
 * the second argument
 *
 * friend bool operator==(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post returns whether the first argument and second arguments are equal in value
 *
 * friend bool operator!=(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post returns whether the first argument and second arguments are not equal in value
 *
 * friend bool operator<(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post returns whether the value of the first argument is less than the value of the
 * second argument
 *
 * friend bool operator<=(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post returns whether the value of the first argument is less than or equal to the
 * value of the second argument
 *
 * friend bool operator>(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post returns whether the value of the first argument is greater than the value of the
 * second argument
 *
 * friend bool operator>=(const Fraction &first, const Fraction &second);
 * @pre the given arguments are valid Fractions or can be coerced to valid Fractions
 * @post returns whether the value of the first argument is greater than or equal to the
 * value of the second argument
 *
 * friend ostream &operator<<(ostream &stream, const Fraction &fraction);
 * @pre the second argument to the insertion operator is a valid Fraction
 * @post inserts a string representation of the given Fraction into the output stream,
 * according to the following rules:
 *   - If the fraction has a denominator of 1, only the numerator is inserted
 *   - If the fraction is improper, the stream receives a representation of a mixed
 *     number in the example format 3+1/2 or -4+5/6
 *   - Otherwise, the stream receives a representation of a fraction in the example format
 *     1/2 or 4/5
 *
 * friend istream &operator>>(istream &stream, Fraction &fraction);
 * @pre the second argument to the extraction operator is a valid Fraction, and the
 * incoming content of the stream is in the format of a whole number, a mixed number, or
 * a normal fraction
 * @post the value of the Fraction argument passed to the function is now equal to the
 * value entered into the input stream
 */

#ifndef CS_11_FRACTION_H
#define CS_11_FRACTION_H

#include <iostream>

using std::ostream;
using std::istream;

namespace cs_Fraction {
    class Fraction {
    private:
        int numerator, denominator;
        void simplify();
    public:
        Fraction(int numerator = 0, int denominator = 1);
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        friend Fraction operator+(const Fraction &first, const Fraction &second);
        friend Fraction operator+=(Fraction &first, const Fraction &second);
        friend Fraction operator-(const Fraction &first, const Fraction &second);
        friend Fraction operator-=(Fraction &first, const Fraction &second);
        friend Fraction operator*(const Fraction &first, const Fraction &second);
        friend Fraction operator*=(Fraction &first, const Fraction &second);
        friend Fraction operator/(const Fraction &first, const Fraction &second);
        friend Fraction operator/=(Fraction &first, const Fraction &second);
        friend bool operator==(const Fraction &first, const Fraction &second);
        friend bool operator!=(const Fraction &first, const Fraction &second);
        friend bool operator<(const Fraction &first, const Fraction &second);
        friend bool operator<=(const Fraction &first, const Fraction &second);
        friend bool operator>(const Fraction &first, const Fraction &second);
        friend bool operator>=(const Fraction &first, const Fraction &second);
        friend ostream &operator<<(ostream &stream, const Fraction &fraction);
        friend istream &operator>>(istream &stream, Fraction &fraction);
    };
}

#endif //CS_11_FRACTION_H
