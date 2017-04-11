/**
 * @author Lucas Street
 * @date 4/9/17
 * CS 11, Dave Harden
 * Assignment 10.1 - sequence.cpp
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






    sequence::sequence(const sequence &other) {
        headptr = precursor = cursor = tailptr = NULL;
        num_items = other.num_items;
        if (num_items > 0) {
            copyList(other);
            copy_cursors(other);
        }
    }






    sequence::~sequence() {
        deleteList();
    }






    sequence &sequence::operator=(const sequence &other) {
        if (this != &other) {
            deleteList();
            sequence *tmp = new sequence(other);
            num_items = tmp->num_items;
            headptr = tmp->headptr;
            precursor = tmp->precursor;
            cursor = tmp->cursor;
            tailptr = tmp->tailptr;
        }
        return *this;
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
        node *new_item = new node;
        *new_item = {entry, NULL};

        if (headptr == NULL) {
            headptr = new_item;
            tailptr = new_item;
        } else if (!is_item() || cursor == headptr) {
            prepend_to_sequence(new_item);
        } else {
            new_item->next = cursor;
            precursor->next = new_item;
        }
        cursor = new_item;
    }






    void sequence::attach(const value_type &entry) {
        if (headptr == NULL) {
            insert(entry);
        } else if (!is_item() || cursor == tailptr) {
            num_items++;
            node *new_item = new node;
            *new_item = {entry, NULL};
            append_to_sequence(new_item);
        } else {
            advance();
            insert(entry);
        }
    }






    void sequence::remove_current() {
        assert(is_item());
        num_items--;
        if (headptr == tailptr) {
            delete cursor;
            cursor = precursor = headptr = tailptr = NULL;
        } else if (cursor == headptr) {
            delete_current_at_head();
        } else if (cursor == tailptr) {
            delete_current_at_tail();
        } else {
            delete_current_with_backup();
        }
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




    // Private interface -----------------------------------------------------------------

    void sequence::copyList(const sequence &other) {
        headptr = new node;
        tailptr = headptr;
        const node *iterator = other.headptr;
        while (iterator != other.tailptr) {
            tailptr->data = iterator->data;
            iterator = iterator->next;
            tailptr->next = new node;
            tailptr = tailptr->next;
        }
        tailptr->data = other.tailptr->data;
        tailptr->next = NULL;
    }






    void sequence::copy_cursors(const sequence &other) {
        const node *iterator = other.headptr;
        node *temp = headptr;
        while (iterator != NULL) {
            if (iterator == other.precursor) {
                precursor = temp;
                cursor = temp->next;
                break;
            } else if (iterator == other.cursor) {
                cursor = temp;
                break;
            }
            iterator = iterator->next;
            temp = temp->next;
        }
    }






    void sequence::prepend_to_sequence(node *new_item) {
        new_item->next = headptr;
        headptr = new_item;
    }






    void sequence::append_to_sequence(node *new_item) {
        precursor = tailptr;
        tailptr->next = new_item;
        tailptr = new_item;
        cursor = new_item;
    }






    void sequence::delete_current_at_head() {
        cursor = cursor->next;
        delete headptr;
        headptr = cursor;
    }






    void sequence::delete_current_at_tail() {
        delete cursor;
        tailptr = precursor;
        tailptr->next = NULL;
        cursor = precursor = NULL;
    }






    /**
     * Explanation: assuming current is somewhere in the middle of 3+ items:
     *
     * [o,p] -> [c] -> []  // make a backup of the precursor
     *
     * [o,p]  [c] -> []    // link the backup to the node after current
     *   |___________|
     *
     * [o] [p] -> [c]      // advance one node forward
     *  |__________|
     *
     * [o,p] -> [c]        // delete precursor node and set it to the backup
     */
    void sequence::delete_current_with_backup() {
        node *backup = precursor;
        backup->next = cursor->next;
        advance();
        delete precursor;
        precursor = backup;
    }






    void sequence::deleteList() {
        start();
        while (is_item()) {
            remove_current();
        }
    }
}
