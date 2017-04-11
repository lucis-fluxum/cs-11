/**
 * @author Lucas Street
 * @date 4/9/17
 * CS 11, Dave Harden
 * Assignment 10.1 - sequence.h
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
        sequence(const sequence &other);
        ~sequence();
        sequence &operator=(const sequence &other);
        void start();
        void advance();
        void insert(const value_type &entry);
        void attach(const value_type &entry);
        void remove_current();
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
        void copyList(const sequence &other);
        void copy_cursors(const sequence &other);
        void prepend_to_sequence(node *new_item);
        void append_to_sequence(node *new_item);
        void delete_current_at_head();
        void delete_current_at_tail();
        void delete_current_with_backup();
        void deleteList();
    };
}

#endif //CS_11_SEQUENCE_H
