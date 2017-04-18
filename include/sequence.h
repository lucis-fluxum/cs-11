/**
 * @author Lucas Street
 * @date 4/17/17
 * CS 11, Dave Harden
 * Assignment 11.1 - sequence.h
 */

#ifndef CS_11_SEQUENCE_H
#define CS_11_SEQUENCE_H

#include <cstdlib>
#include <stack>

namespace cs_sequence {
    class sequence {
    public:
        typedef int value_type;
        typedef std::size_t size_type;
        void start();
        void advance();
        void insert(const value_type &entry);
        void attach(const value_type &entry);
        void remove_current();
        size_type size() const;
        bool is_item() const;
        value_type current() const;
    private:
        std::stack<value_type> head, tail;
        void back();
        void end();
        bool has_next();
        void next();
        void set_invalid();
    };
}

#endif //CS_11_SEQUENCE_H
