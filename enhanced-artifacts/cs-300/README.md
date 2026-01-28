# CS-499 Milestone Three: Enhanced Binary Search Tree (AVL Balancing)

## Original Artifact
- Course: CS-300 Data Structures and Algorithms
- File: ProjectTwo.cpp (Advising Assistance BST)
- Purpose: Loads courses from CSV, inserts into recursive BST, prints sorted list, searches for course details

## Enhancement Summary
- Added AVL tree balancing to guarantee O(log n) worst-case insert and search operations
- Added height field to Node structure
- Implemented leftRotate and rightRotate functions
- Modified insertNode to check balance factor and perform rotations when needed

## Before vs After
- Original BST: O(n) worst-case performance on sorted or nearly sorted input (degrades to linked list)
- Enhanced AVL BST: O(log n) worst-case and average-case performance for insert, search, and traversal

## How to Test
1. Compile: g++ enhanced-BinarySearchTree.cpp enhanced-ProjectTwo.cpp -o avl-test
2. Run: ./avl-test
3. Choose option 1 to load courses.csv (or your test CSV)
4. Choose option 2 to print sorted list (tree is now balanced)
5. Choose option 3 to search a course and verify functionality

## Files in this folder
- enhanced-BinarySearchTree.h     Header with AVL support (height, rotations)
- enhanced-BinarySearchTree.cpp   Implementation with balancing logic
- enhanced-ProjectTwo.cpp         Full program (original driver + enhanced BST)
- README.md                       This file

This enhancement aligns with Course Outcome 3 (algorithmic principles and trade-offs) and Outcome 4 (innovative techniques for efficient solutions).