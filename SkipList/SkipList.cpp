#include "SkipList.hpp"
#include <iostream>
#include <algorithm>

SkipList::SkipList() {
    this->root = NULL;
}

Node *newNode(int key) {
    return new Node{ .key = key, .left = NULL, .right = NULL };
}

void SkipList::insert(int key) {
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


void SkipList::insert(std::vector<int> *keys) {
    std::for_each(keys->begin(), keys->end(), [this](int key){ this->insert(key); });
}

bool SkipList::find(int key) const {
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

void SkipList::print() {
	_print(this->root);
	std::cout << std::endl;
}

