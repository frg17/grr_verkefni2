#include "BinaryTree.hpp"
#include <algorithm>

BinaryTree::BinaryTree() {
    this->root = NULL;
}

Node *newNode(int key) {
    return new Node{ .key = key, .left = NULL, .right = NULL };
}

void BinaryTree::insert(int key) {
    if (this->root == NULL) {
        this->root = newNode(key);
    } else {
        Node *current = this->root;
        while (true) {
            if (key < current->key) {
                if (current->left == NULL) {
                    current->left = newNode(key);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = newNode(key);
                    return;
                }
                current = current->right;
            }
        }
    }
}


void BinaryTree::insert(std::vector<int> keys) {
    std::for_each(keys.begin(), keys.end(), [this](int key){ this->insert(key); });
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
