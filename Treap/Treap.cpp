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


typedef struct LinkedList {
	struct LinkedList* parent;
	TreapNode *node;
} LinkedList;


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
	LinkedList *llnode = NULL;

    while(*current) {
		llnode = new LinkedList{ .parent = llnode, .node = *current};

	    int currkey = (*current)->key;
		if (key > currkey)
			current = &((*current)->right);
		else
			current = &((*current)->left);
	}
	*current = this->newNode(key);
	if (!llnode) return;
	
	int priority = (*current)->priority;
	while (llnode->parent && (llnode->parent->node->priority < priority)) {
		TreapNode *granny = NULL;
		TreapNode *parentNode = llnode->parent->node;
		if (llnode->parent->parent) granny = llnode->parent->parent->node;
		
		if (parentNode->left == *current) {
			turnRight(*current, parentNode, granny);
		} else {
			turnLeft(*current, parentNode, granny);	
		}

		llnode = llnode->parent;
	}
}

void Treap::insert(std::vector<int> *keys) {
    std::for_each(keys->begin(), keys->end(), [this](int key){ this->insert(key); });
}

bool Treap::find(int key) {
    TreapNode *current = this->root;

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

