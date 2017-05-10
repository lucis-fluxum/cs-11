/**
 * @author Lucas Street
 * @date 5/9/17
 * CS 11, Dave Harden
 * Assignment 14.1 - binarytree.h
 */

#ifndef CS_11_BINARYTREE_H
#define CS_11_BINARYTREE_H

#include <cstdlib>    // for size_t
#include "LL.h"

class binarytree {

public:
    typedef std::size_t size_type;
    binarytree();
    binarytree(const binarytree &other);
    ~binarytree();
    void insert(int item);
    void print() const;
    size_type size() const;
    int find(int target, bool &found) const;
    void del(int target, bool &found);
    size_type num_primes() const;
    LL<int> toLL() const;
    binarytree operator=(const binarytree &right);
    binarytree *clone() const;
    void clear();
private:
    struct treenode {
        int data;
        treenode *left;
        treenode *right;
    };

    treenode *root;
    size_type mSize;
    friend bool isPrime(int num);
    friend size_type num_primes_aux(const treenode *node);
    friend void insert_aux(treenode *&root, int item);
    friend void print_aux(treenode *root);
    friend int find_aux(treenode *root, int target, bool &found);
    friend void del_aux(treenode *&root, int target, bool &found);
    friend void remove_max(treenode *&root, int &max);
    friend void toLL_aux(treenode *root, LL<int> &list);
    friend void clone_aux(treenode *root, binarytree *new_tree);
    friend void clear_aux(treenode *&root);
};

#endif //CS_11_BINARYTREE_H
