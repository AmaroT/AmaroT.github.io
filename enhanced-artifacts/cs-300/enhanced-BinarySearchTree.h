#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <string>
#include <vector>
#include <iostream>

struct Course {
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;
};

struct Node {
    Course course;
    Node* left;
    Node* right;
    int height;

    Node(Course c) : course(c), left(nullptr), right(nullptr), height(1) {}
};

class BinarySearchTree {
private:
    Node* root;

    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insertNode(Node* node, Course course);
    void inOrderTraversal(Node* node);
    Course* searchNode(Node* node, const std::string& courseNumber);
    void clear(Node* node);

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(root); }

    void insert(Course course);
    void printCourses();
    Course* search(const std::string& courseNumber);
};

#endif