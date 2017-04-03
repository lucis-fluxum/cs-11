/**
 * @author Lucas Street
 * @date 4/3/17
 * CS 11, Dave Harden
 * Assignment 9.1 - sequence.h
 */

#ifndef CS_11_SEQUENCE_H
#define CS_11_SEQUENCE_H

#include <cstdlib>

namespace cs_sequence {
    class sequence {
    public:
        typedef int value_type;
        typedef std::size_t size_type;
        sequence();
        void start();
        void advance();
        void insert(const value_type &entry);
//        void attach(const value_type &entry);
//        void remove_current();
        size_type size() const;
        bool is_item() const;
        value_type current() const;
    private:
        size_type num_items;
        struct node {
            value_type data;
            node *next;
        };
        node *headptr;
        node *precursor;
        node *cursor;
        node *tailptr;
    };
}

#endif //CS_11_SEQUENCE_H
