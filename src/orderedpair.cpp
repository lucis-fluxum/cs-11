/**
 * @author Lucas Street
 * @date 3/25/17
 * CS 11, Dave Harden
 * Assignment 8.2 - orderedpair.cpp
 */

namespace cs_pairs {
    template<class T>
    orderedPair<T>::orderedPair(T newFirst, T newSecond) {
        setFirst(newFirst);
        setSecond(newSecond);
    }






    template<class T>
    void orderedPair<T>::setFirst(const T &newFirst) {
        if (newFirst == second && second != orderedPair<T>::DEFAULT_VALUE) {
            throw orderedPair<T>::DuplicateMemberError();
        }
        first = newFirst;
    }






    template<class T>
    void orderedPair<T>::setSecond(const T &newSecond) {
        if (newSecond == first && first != orderedPair<T>::DEFAULT_VALUE) {
            throw orderedPair<T>::DuplicateMemberError();
        }
        second = newSecond;
    }






    template<class T>
    T orderedPair<T>::getFirst() const {
        return first;
    }






    template<class T>
    T orderedPair<T>::getSecond() const {
        return second;
    }






    template<class T>
    orderedPair <T> orderedPair<T>::operator+(const orderedPair <T> &right) const {
        return orderedPair<T>(first + right.first, second + right.second);
    }






    template<class T>
    bool orderedPair<T>::operator<(const orderedPair <T> &right) const {
        return first + second < right.first + right.second;
    }






    template<class T>
    void orderedPair<T>::print() const {
        cout << "(" << first << ", " << second << ")";
    }
}
