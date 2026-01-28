#include "enhanced-BinarySearchTree.h"
#include <algorithm>

int BinarySearchTree::height(Node* node) {
    return node ? node->height : 0;
}

int BinarySearchTree::getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* BinarySearchTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* BinarySearchTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* BinarySearchTree::insertNode(Node* node, Course course) {
    if (!node) return new Node(course);

    if (course.courseNumber < node->course.courseNumber)
        node->left = insertNode(node->left, course);
    else if (course.courseNumber > node->course.courseNumber)
        node->right = insertNode(node->right, course);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && course.courseNumber < node->left->course.courseNumber)
        return rightRotate(node);

    if (balance < -1 && course.courseNumber > node->right->course.courseNumber)
        return leftRotate(node);

    if (balance > 1 && course.courseNumber > node->left->course.courseNumber) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && course.courseNumber < node->right->course.courseNumber) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void BinarySearchTree::insert(Course course) {
    root = insertNode(root, course);
}

void BinarySearchTree::inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->course.courseNumber << ", " << node->course.courseTitle << std::endl;
        inOrderTraversal(node->right);
    }
}

Course* BinarySearchTree::searchNode(Node* node, const std::string& courseNumber) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->course.courseNumber == courseNumber) {
        return &node->course;
    } else if (courseNumber < node->course.courseNumber) {
        return searchNode(node->left, courseNumber);
    } else {
        return searchNode(node->right, courseNumber);
    }
}

void BinarySearchTree::printCourses() {
    inOrderTraversal(root);
}

Course* BinarySearchTree::search(const std::string& courseNumber) {
    return searchNode(root, courseNumber);
}

void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}