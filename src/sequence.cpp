/**
 * @author Lucas Street
 * @date 4/3/17
 * CS 11, Dave Harden
 * Assignment 9.1 - sequence.cpp
 */

#include <cassert>
#include "sequence.h"

namespace cs_sequence {
    sequence::sequence() {
        num_items = 0;
        headptr = NULL;
        cursor = NULL;
        precursor = NULL;
        tailptr = NULL;
    }






    void sequence::start() {
        precursor = NULL;
        cursor = headptr;
    }






    void sequence::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->next;
        if (cursor == NULL) {
            precursor = NULL;
        }
    }






    void sequence::insert(const value_type &entry) {
        num_items++;
        node *tempptr = new node;
        tempptr->data = entry;

        if (headptr == NULL) {
            tempptr->next = NULL;
            headptr = tempptr;
            tailptr = tempptr;
        } else if (cursor == NULL || cursor == headptr) {
            tempptr->next = headptr;
            headptr = tempptr;
        } else {
            tempptr->next = cursor;
            precursor->next = tempptr;
        }

        cursor = tempptr;
    }






    sequence::size_type sequence::size() const {
        return num_items;
    }






    bool sequence::is_item() const {
        return cursor != NULL;
    }






    sequence::value_type sequence::current() const {
        assert(is_item());
        return cursor->data;
    }
}
