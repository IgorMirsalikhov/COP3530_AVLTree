#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

#include "AVLTree.hpp"

// ==================================================
// Constructor and Destructor
// ==================================================

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {

}

template <typename T>
AVLTree<T>::~AVLTree() {
    clear(root);
}

template <typename T>
void AVLTree<T>::clear(AVLNode<T>* node) {
    if (!node) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}

// ==================================================
// Basic BST Operations
// ==================================================

template <typename T>
bool AVLTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
bool AVLTree<T>::contains(const T& val) const {
    return search(root, val) != nullptr;
}

template <typename T>
const AVLNode<T>* AVLTree<T>::search(const AVLNode<T>* node, const T& val) const {
    if (!node || node->data == val) {
        return node;
    }

    if (val < node->data) {
        return search(node->left, val);
    }

    return search(node->right, val);
}

template <typename T>
const AVLNode<T>* AVLTree<T>::getMinNode(const AVLNode<T>* node) const {
    if (!node) {
        return nullptr;
    }

    while (node->left) {
        node = node->left;
    }

    return node;
}

// ==================================================
// Traversal
// ==================================================

template <typename T>
void AVLTree<T>::inorder() const {
    inorder(root);
}

template <typename T>
void AVLTree<T>::inorder(const AVLNode<T>* node) const {
    if (!node) {
        return;
    }

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

// ==================================================
// Printing
// ==================================================

template <typename T>
void AVLTree<T>::print() const {
    std::cout << "===============================\n";
    print("", root, false);
    std::cout << "===============================\n";
}

template <typename T>
void AVLTree<T>::print(const std::string& prefix, const AVLNode<T>* node, bool isRight) const {
    if (!node) {
        return;
    }

    std::cout << prefix;

    if (node != root) {
        std::cout << (isRight ? "R--" : "L--");
    }
    else {
        std::cout << "---";
    }

    std::cout << node->data
              << ", " << getBalance(node)
              << std::endl;

    print(prefix + "   ", node->right, true);
    print(prefix + "   ", node->left, false);
}

// ==================================================
// Rotations (Previous Lecture)
// ==================================================

template <typename T>
void AVLTree<T>::rotateRight(AVLNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }

    AVLNode<T>* left_kid = node->left;

    node->left = left_kid->right;
    left_kid->right = node;

    node = left_kid;
}

template <typename T>
void AVLTree<T>::rotateLeft(AVLNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }

    AVLNode<T>* right_kid = node->right;

    node->right = right_kid->left;
    right_kid->left = node;

    node = right_kid;
}

template <typename T>
void AVLTree<T>::rotateLeftRight(AVLNode<T>*& node) {
    if (!node || !node->left || !node->left->right) {
        return;
    }

    rotateLeft(node->left);
    rotateRight(node);
}

template <typename T>
void AVLTree<T>::rotateRightLeft(AVLNode<T>*& node) {
    if (!node || !node->right || !node->right->left) {
        return;
    }

    rotateRight(node->right);
    rotateLeft(node);
}

// ==================================================
// AVL Height Management (TODO)
// ==================================================

template <typename T>
int AVLTree<T>::getHeight(const AVLNode<T>* node) const {
    // TODO: Return the stored height of a node
    throw std::logic_error("TODO: getHeight");
}

template <typename T>
int AVLTree<T>::getBalance(const AVLNode<T>* node) const {
    // TODO: Calculate the balance factor
    throw std::logic_error("TODO: getBalance");
}

template <typename T>
void AVLTree<T>::updateHeight(AVLNode<T>* node) {
    // TODO: Update the node's height
}

// ==================================================
// Automatic Balancing (TODO)
// ==================================================

template <typename T>
void AVLTree<T>::balance(AVLNode<T>*& node) {
    // TODO: Restore AVL balance using rotations
}

// ==================================================
// Insertion (TODO)
// ==================================================

template <typename T>
void AVLTree<T>::insert(const T& val) {
    // TODO: Call recursive insert
}

template <typename T>
void AVLTree<T>::insert(
    const T& val, AVLNode<T>*& node) {

    // TODO: Implement recursive AVL insertion
}

