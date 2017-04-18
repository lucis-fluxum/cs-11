/**
 * @author Lucas Street
 * @date 4/17/17
 * CS 11, Dave Harden
 * Assignment 11.1 - sequence.cpp
 */

#include <cassert>
#include "sequence.h"

using std::stack;

namespace cs_sequence {
    void sequence::start() {
        set_invalid();
        next();
    }






    void sequence::advance() {
        assert(is_item());
        next();
    }






    void sequence::insert(const sequence::value_type &entry) {
        if (is_item()) {
            back();
            head.push(entry);
        } else {
            tail.push(entry);
            start();
        }
    }






    void sequence::attach(const sequence::value_type &entry) {
        if (is_item()) {
            head.push(entry);
        } else {
            end();
            head.push(entry);
        }
    }






    void sequence::remove_current() {
        assert(is_item());
        head.pop();
        next();
    }






    sequence::size_type sequence::size() const {
        return head.size() + tail.size();
    }






    bool sequence::is_item() const {
        return !head.empty();
    }






    sequence::value_type sequence::current() const {
        assert(is_item());
        return head.top();
    }






    void sequence::back() {
        tail.push(current());
        head.pop();
    }






    void sequence::end() {
        while (has_next()) {
            next();
        }
    }






    bool sequence::has_next() {
        return !tail.empty();
    }






    void sequence::next() {
        if (has_next()) {
            value_type next = tail.top();
            head.push(next);
            tail.pop();
        } else {
            set_invalid();
        }
    }






    void sequence::set_invalid() {
        while (is_item()) {
            back();
        }
    }
}
