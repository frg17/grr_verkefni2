#include "Treap.hpp"
#include <iostream>
#include <algorithm>

Treap::Treap() {
    this->root = NULL;
	
	std::random_device rand_dev;
	this->generator = std::mt19937(rand_dev());
	this->distribution = std::uniform_int_distribution<int>(0, 1000000);

}

TreapNode *Treap::newNode(int key) {
	int priority = this->distribution(this->generator);
    return new TreapNode{ key: key, priority: priority, left: NULL, right: NULL };

}


void turnRight(TreapNode *current, TreapNode *parent, TreapNode *granny) {
	TreapNode *tmp = current->right;
	current->right = parent;
	parent->left = tmp;	

	if (!granny) return;
	
	if (granny->left == parent) {
		granny->left = current;
	} else {
		granny->right = current;
	}
}

void turnLeft(TreapNode *current, TreapNode *parent, TreapNode *granny) {
	TreapNode *tmp = current->left;
	current->left = parent;
	parent->right = tmp;

	if (!granny) return;

	if (granny->left == parent) {
		granny->left = current;
	} else {
		granny->right = current;
	}
}


void Treap::insert(int key) {
    TreapNode **current = &(this->root);
	std::vector<TreapNode*> links;

    while(*current) {
		links.push_back(*current);
	    int currkey = (*current)->key;
		if (key > currkey)
			current = &((*current)->right);
		else
			current = &((*current)->left);
	}

	*current = this->newNode(key);
	
	TreapNode *currNode = *current;
	TreapNode *parent = NULL;
	TreapNode *granny  = NULL;
	if (!links.empty()) {
		parent = links.back();
		links.pop_back();
	}
		
	int priority = (currNode)->priority;
	while (parent && (parent->priority < priority)) {
		
		if (!links.empty()) {
			granny = links.back();
			links.pop_back();
		} else {
			this->root = currNode;
		}
		
		if (parent->left == currNode) {
			turnRight(currNode, parent, granny);
		} else {
			turnLeft(currNode, parent, granny);	
		}

		parent = granny;
		granny = NULL;
	}
}

void Treap::insert(std::vector<int> *keys) {
    std::for_each(keys->begin(), keys->end(), [this](int key){ this->insert(key); });
}

bool Treap::find(int key) const {
    TreapNode *current = this->root;

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

void _print(TreapNode *n) {
	if (n == NULL) return;
	_print(n->left);
	std::cout << n->key << " ";
	_print(n->right);
}

void Treap::print() {
	_print(this->root);
	std::cout << std::endl;
}

