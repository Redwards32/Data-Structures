#include "BTree.h"
#include <iostream>

using namespace std;

BTree::BTree() { //constructor, binary tree is empty
    root = nullptr;
}

BTree::~BTree() { //destructor, deletes entire binary tree
    destroy_tree();
}

Node *BTree::BTree_root() { //pointer to the root
    return root;
}

void BTree::destroy_tree(Node *leaf) { //recursive function that destroys subtree
    if(leaf != nullptr) { //if leaf exists, destroy left & right child nodes
        destroy_tree(leaf -> left);
        destroy_tree(leaf -> right);
        delete leaf;
    }
}

void BTree::insert(int key, Node *leaf) {
    if (key < leaf -> key_value) {
        if (leaf -> left != nullptr)
            insert(key, leaf -> left); //recursive function
        else {
            leaf -> left = new Node;
            leaf -> left -> key_value = key;
            leaf -> left -> left = nullptr; //begins left child of child node to null
            leaf -> left -> right = nullptr; //sets right child of child node to null
        }
    } else if(key >= leaf -> key_value) {
        if (leaf -> right != nullptr)
            insert(key, leaf -> right);
        else {
            leaf -> right = new Node;
            leaf -> right -> key_value = key;
            leaf -> right -> left = nullptr; //vice versa
            leaf -> right -> right = nullptr; //vice versa
        }
    }
}

Node *BTree::search(int key, Node *leaf) {
    if (leaf != nullptr) {
        if (key == leaf -> key_value)
            return leaf;
        if (key < leaf -> key_value)
            return search(key, leaf -> left); //left child node of leaf
        else
            return search(key, leaf -> right); //right child node of leaf
    }
    else return nullptr; //reaches the end of the tree but no key is found
}

void BTree::insert(int key) {
    if (root != nullptr)
        insert(key, root);
    else { //if tree is empty
        root = new Node;
        root -> key_value = key;
        root -> left = nullptr;
        root -> right = nullptr;
    }
}

Node *BTree::search(int key) {
    return search(key, root);
}

void BTree::destroy_tree() {
    destroy_tree(root);
}



