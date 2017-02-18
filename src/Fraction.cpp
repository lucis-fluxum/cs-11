/**
 * @author Lucas Street
 * @date 2/17/17
 * CS 11, Dave Harden
 * Assignment 4.1 - Fraction.cpp
 *
 * Fraction objects are always stored in lowest terms, and never have denominators of 0.
 *
 * Private data members:
 *   numerator: an integer representing the numerator of the fraction
 *   denominator: an integer representing the denominator of the fraction
 *
 * Both the numerator and denominator are used to calculate the various arithmetic
 * operations on fractions, testing equality, comparison, and simplification.
 */

#include <cassert>
#include <cmath>
#include "Fraction.h"

using namespace std;

namespace cs_Fraction {
    int get_gcf(int numerator, int denominator);






    Fraction::Fraction(int numerator, int denominator) {
        assert(denominator != 0);
        this->numerator = numerator;
        this->denominator = denominator;
        this->simplify();
    }






    Fraction Fraction::operator++() {
        *this = *this + 1;
        return *this;
    }






    Fraction Fraction::operator++(int) {
        Fraction old = *this;
        ++*this;
        return old;
    }






    Fraction Fraction::operator--() {
        *this = *this - 1;
        return *this;
    }






    Fraction Fraction::operator--(int) {
        Fraction old = *this;
        --*this;
        return old;
    }






    /**
     * Reduces the calling Fraction by dividing the numerator and the denominator by their
     * greatest common factor. Fractions with a numerator of 0 are given a denominator of 1
     * and any negatives in the denominator are moved to the numerator.
     */
    void Fraction::simplify() {
        if (numerator == 0) {
            denominator = 1;
        } else {
            int gcf = get_gcf(numerator, denominator);
            numerator /= gcf;
            denominator /= gcf;

            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
    }






    /**
     * This function finds the greatest common factor between the given arguments.
     *
     * @param numerator the numerator of a fraction
     * @param denominator the denominator of a fraction
     * @return the greatest common factor between numerator and denominator
     */
    int get_gcf(int numerator, int denominator) {
        int factor = 1;
        int gcf = 1;

        while (abs(numerator) >= factor && abs(denominator) >= factor) {
            if (numerator % factor == 0 && denominator % factor == 0) {
                gcf = factor;
            }
            factor++;
        }

        return gcf;
    }






    Fraction operator+(const Fraction &first, const Fraction &second) {
        int common_denom = first.denominator * second.denominator;
        int new_numerator =
                (first.numerator * second.denominator) +
                (second.numerator * first.denominator);
        Fraction result(new_numerator, common_denom);
        result.simplify();
        return result;
    }






    Fraction operator+=(Fraction &first, const Fraction &second) {
        first = first + second;
        return first;
    }






    Fraction operator-(const Fraction &first, const Fraction &second) {
        return first + (second * -1);
    }






    Fraction operator-=(Fraction &first, const Fraction &second) {
        first = first - second;
        return first;
    }






    Fraction operator*(const Fraction &first, const Fraction &second) {
        Fraction result(first.numerator * second.numerator,
                        first.denominator * second.denominator);
        result.simplify();
        return result;
    }






    Fraction operator*=(Fraction &first, const Fraction &second) {
        first = first * second;
        return first;
    }






    Fraction operator/(const Fraction &first, const Fraction &second) {
        Fraction reciprocal(second.denominator, second.numerator);
        return first * reciprocal;
    }






    Fraction operator/=(Fraction &first, const Fraction &second) {
        first = first / second;
        return first;
    }






    bool operator==(const Fraction &first, const Fraction &second) {
        int term1 = first.numerator * second.denominator;
        int term2 = first.denominator * second.numerator;
        return term1 == term2;
    }






    bool operator!=(const Fraction &first, const Fraction &second) {
        return !(first == second);
    }






    bool operator<(const Fraction &first, const Fraction &second) {
        int term1 = first.numerator * second.denominator;
        int term2 = first.denominator * second.numerator;
        return term1 < term2;
    }






    bool operator<=(const Fraction &first, const Fraction &second) {
        return (first < second) || (first == second);
    }






    bool operator>(const Fraction &first, const Fraction &second) {
        return !(first <= second);
    }






    bool operator>=(const Fraction &first, const Fraction &second) {
        return !(first < second);
    }






    /**
     * The calculation of the mixed number uses the integer quotient of the numerator and
     * denominator combined with the absolute value of the remainder of said quotient.
     */
    ostream &operator<<(ostream &stream, const Fraction &fraction) {
        if (fraction.denominator == 1) {
            stream << fraction.numerator;
        } else if (abs(fraction.numerator) > abs(fraction.denominator)) {
            int whole_part = fraction.numerator / fraction.denominator;
            int remainder = fraction.numerator % fraction.denominator;
            remainder = static_cast<int>(abs(remainder));

            if (remainder == 0) {
                stream << whole_part;
            } else {
                stream << whole_part << "+" << remainder << "/" << fraction.denominator;
            }
        } else {
            stream << fraction.numerator << '/' << fraction.denominator;
        }
        return stream;
    }






    /**
     * The extraction of mixed numbers uses the extraction of a normal fraction after
     * extracting the whole number from the mixed number, finally adding the two values
     * together.
     */
    istream &operator>>(istream &stream, Fraction &fraction) {
        int first;
        stream >> first;
        if (stream.peek() == '+') {
            stream.ignore();
            stream >> fraction; // get remainder
            if (first < 0) {
                fraction *= -1; // subtract if whole part < 0
            }
            fraction += first;  // then add whole part
        } else {
            fraction.numerator = first;
            if (stream.peek() == '/') {
                stream.ignore();
                stream >> fraction.denominator;
                fraction.simplify();
            }
        }
        return stream;
    }
}

// Output
/*
----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing -1/2 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
*/
