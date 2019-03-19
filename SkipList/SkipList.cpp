#include "SkipList.hpp"
#include <iostream>
#include <algorithm>


SkipListNode *SkipList::createNewChain() {
	SkipListNode *end = new SkipListNode{ this->MAX, NULL, this->end };
	SkipListNode *start = new SkipListNode{ this->MIN, end, this->head };
	this->head = start;
	this->end = end;
	return start;
}

SkipList::SkipList() {
    std::random_device rand_dev;
	this->generator = std::mt19937(rand_dev());
	this->distribution = std::uniform_int_distribution<int>(0, 1);
	
	this->head = this->createNewChain();
}

bool SkipList::flipCoin() {
    return this->distribution(this->generator) == 1;
}

SkipListNode *newNode(SkipListNode *right, SkipListNode *down, int key) {
    return new SkipListNode{ key, right, down };
}

void SkipList::insert(int key) {
	this->down(this->head, key);

	if (this->size == this->nextSplit) {
		this->addLevel();
		this->nextSplit *= 2;
	}
}

void SkipList::addLevel() {
	SkipListNode *current = this->head;
	SkipListNode *topLevelNode = this->createNewChain();

	current = current->right;
	while (current->right) {
		if (flipCoin()) {
			SkipListNode *nextNode = newNode(topLevelNode->right, current, current->key);
			topLevelNode->right = nextNode;
			topLevelNode = nextNode;
		}
		current = current->right;
	}
}

SkipListNode *SkipList::down(SkipListNode *current, int key) {
	while (key > current->right->key) {
		current = current->right;
	}

	if (current->down) {
		SkipListNode *downNode = this->down(current->down, key);
		if (downNode) {
			SkipListNode *nextNode = newNode(current->right, downNode, key);
			current->right = nextNode;

			if (flipCoin()) {
				return nextNode;
			}
			else {
				return NULL;
			}
		}

		return NULL;
	}
	else {
		SkipListNode *nextNode = newNode(current->right, NULL, key);
		current->right = nextNode;
		this->size += 1;

		if (flipCoin()) {
			return nextNode;
		}
		else {
			return NULL;
		}
	}
	
}

void SkipList::insert(std::vector<int> *keys) {
	for (int key : *keys) {
		this->insert(key);
	}
}

bool _find(SkipListNode *current, int key) {
	while (key > current->right->key) {
		current = current->right;
	}

	if (key == current->right->key) {
		return true;
	}
	else if (current->down) {
		return _find(current->down, key);
	}
	
	return false;
}

bool SkipList::find(int key) const {
	return _find(this->head, key);
}

void _print(SkipListNode *current) {
	current = current->right;
	while (current->right) {
		std::cout << current->key << "(";
		if (current->down) {
			std::cout << current->down->key;
		}
		std::cout << ") ";
		current = current->right;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void SkipList::print() {
	SkipListNode *current = this->head;
	while (current) {
		_print(current);
		current = current->down;
	}
}

