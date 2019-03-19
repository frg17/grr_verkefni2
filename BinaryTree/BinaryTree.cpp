#include "BinaryTree.hpp"
#include <iostream>
#include <algorithm>

BinaryTree::BinaryTree() {
    this->root = NULL;
}

Node *newNode(int key) {
    return new Node{ .key = key, .left = NULL, .right = NULL };
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
    std::for_each(keys->begin(), keys->end(), [this](int key){ this->insert(key); });
}

bool BinaryTree::find(int key) {
    Node *current = this->root;

    while (true) {
        if (current == NULL) return false;
        if (current->key == key) {
            return true;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
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

