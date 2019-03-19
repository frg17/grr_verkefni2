#include "BinaryTree.hpp"
#include <iostream>
#include <algorithm>

BinaryTree::BinaryTree() {
    this->root = NULL;
}

Node *newNode(int key) {
    return new Node{ key, NULL, NULL };
}

void BinaryTree::insert(int key) {
    Node **current = &(this->root);
    while(*current) {
	    int currkey = (*current)->key;
		if (key > currkey)
			current = &((*current)->right);
		else
			current = &((*current)->left);
	}
	*current = newNode(key);
}


void BinaryTree::insert(std::vector<int> *keys) {
    for (int key : *keys) {
        this->insert(key);
    }
}

bool BinaryTree::find(int key) const {
    Node *current = this->root;

    while (current) {
        if (current->key == key) {
            return true;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}

void _print(Node *n) {
	if (n == NULL) return;
	_print(n->left);
	std::cout << n->key << " ";
	_print(n->right);
}

void BinaryTree::print() {
	_print(this->root);
	std::cout << std::endl;
}

