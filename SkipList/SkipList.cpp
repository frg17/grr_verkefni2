#include "SkipList.hpp"
#include <iostream>
#include <algorithm>

SkipList::SkipList() {
    std::random_device rand_dev;
	this->generator = std::mt19937(rand_dev());
	this->distribution = std::uniform_int_distribution<int>(0, 1);
}

int SkipList::flipCoin() {
    return this->distribution(this->generator);
}

SkipListNode *newNode(int key) {

    return new SkipListNode{ .key = key, .right = NULL, .down = NULL };
}

void SkipList::insert(int key) {

}


void SkipList::insert(std::vector<int> *keys) {
    std::for_each(keys->begin(), keys->end(), [this](int key){ this->insert(key); });
}

bool SkipList::find(int key) const {
}

void _print(SkipListNode *n) {
}

void SkipList::print() {
}

