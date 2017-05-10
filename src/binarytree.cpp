/**
 * @author Lucas Street
 * @date 5/9/17
 * CS 11, Dave Harden
 * Assignment 14.1 - binarytree.cpp
 */

#include <iostream>
#include "binarytree.h"

using namespace std;




// PUBLIC INTERFACE

binarytree::binarytree() {
    root = nullptr;
    mSize = 0;
}






binarytree::binarytree(const binarytree &other) {
    binarytree *new_tree = other.clone();
    this->root = new_tree->root;
    this->mSize = new_tree->mSize;
}






binarytree::~binarytree() {
    clear();
}






void binarytree::insert(int item) {
    insert_aux(root, item);
    mSize++;
}






void binarytree::print() const {
    print_aux(root);
}






binarytree::size_type binarytree::size() const {
    return mSize;
}






int binarytree::find(int target, bool &found) const {
    return find_aux(root, target, found);
}






void binarytree::del(int target, bool &found) {
    del_aux(root, target, found);
    if (found) {
        mSize--;
    }
}






binarytree::size_type binarytree::num_primes() const {
    return num_primes_aux(root);
}






LL<int> binarytree::toLL() const {
    LL<int> list;
    toLL_aux(root, list);
    return list;
}






binarytree *binarytree::clone() const {
    binarytree *new_tree = new binarytree;
    clone_aux(root, new_tree);
    return new_tree;
}






void binarytree::clear() {
    clear_aux(root);
    mSize = 0;
}






binarytree binarytree::operator=(const binarytree &right) {
    if (this != &right) {
        this->clear();
        binarytree *new_tree = right.clone();
        this->root = new_tree->root;
        this->mSize = new_tree->mSize;
    }
    return *this;
}




// FRIEND FUNCTIONS

bool isPrime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    for (int factor = 2; factor < num; ++factor) {
        if (num % factor == 0) {
            return false;
        }
    }
    return true;
}






binarytree::size_type num_primes_aux(const binarytree::treenode *node) {
    if (node == nullptr) {
        return 0;
    } else {
        if (isPrime(node->data)) {
            return 1 + num_primes_aux(node->right) + num_primes_aux(node->left);
        } else {
            return 0 + num_primes_aux(node->right) + num_primes_aux(node->left);
        }
    }
}






void insert_aux(binarytree::treenode *&root, int item) {
    if (root == nullptr) {
        // root = new treenode(item, nullptr, nullptr);
        root = new binarytree::treenode;
        root->data = item;
        root->left = nullptr;
        root->right = nullptr;
    } else if (item <= root->data) {
        insert_aux(root->left, item);
    } else {
        insert_aux(root->right, item);
    }
}






void print_aux(binarytree::treenode *root) {
    if (root != nullptr) {
        print_aux(root->left);
        cout << root->data << " ";
        print_aux(root->right);
    }
}






int find_aux(binarytree::treenode *root, int target, bool &found) {
    if (root == nullptr) {
        found = false;
        return 0;
    } else if (target == root->data) {
        found = true;
        return root->data;
    } else if (target < root->data) {
        return find_aux(root->left, target, found);
    } else {
        return find_aux(root->right, target, found);
    }
}






void del_aux(binarytree::treenode *&root, int target, bool &found) {
    if (root == nullptr) {
        found = false;
    } else if (target < root->data) {
        del_aux(root->left, target, found);
    } else if (target > root->data) {
        del_aux(root->right, target, found);
    } else if (root->left == nullptr) {
        binarytree::treenode *tempptr = root;
        root = root->right;
        delete tempptr;
        found = true;
    } else {
        int max;
        remove_max(root->left, max);
        root->data = max;
        found = true;
    }
}






void remove_max(binarytree::treenode *&root, int &max) {
    if (root->right == nullptr) {
        max = root->data;
        binarytree::treenode *tempptr = root;
        root = root->left;
        delete tempptr;
    } else {
        remove_max(root->right, max);
    }
}






void toLL_aux(binarytree::treenode *root, LL<int> &list) {
    if (root != nullptr) {
        toLL_aux(root->right, list);
        list.push_front(root->data);
        toLL_aux(root->left, list);
    }
}






void clone_aux(binarytree::treenode *root, binarytree *new_tree) {
    if (root != nullptr) {
        new_tree->insert(root->data);
        clone_aux(root->left, new_tree);
        clone_aux(root->right, new_tree);
    }
}






void clear_aux(binarytree::treenode *&root) {
    if (root != nullptr) {
        clear_aux(root->left);
        clear_aux(root->right);
        delete root;
        root = nullptr;
    }
}
