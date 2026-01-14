//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Amaro Terrazas
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>
#include <time.h>
#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Forward declarations
double strToDouble(string str, char ch);

// Define a structure to hold bid information
struct Bid {
    string bidId; // Unique identifier
    string title; // Title of the bid
    string fund;  // Associated fund
    double amount; // Bid amount

    // Default constructor
    Bid() {
        amount = 0.0;
    }
};
void displayBid(Bid bid);

// Internal structure for tree node
struct Node {
    Bid bid;
    Node* left;
    Node* right;

    // Default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // Initialize with a bid
    Node(Bid aBid) : Node() {
        bid = aBid;
    }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree.
 */
class BinarySearchTree {

private:
    Node* root; // Root node of the tree

    // Private recursive helper methods
    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    void postOrderDelete(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();       // Constructor
    virtual ~BinarySearchTree();  // Destructor
    void InOrder();           // Public in-order traversal
    void PostOrder();         // Public post-order traversal
    void PreOrder();          // Public pre-order traversal
    void Insert(Bid bid);     // Insert a bid
    void Remove(string bidId); // Remove a bid
    Bid Search(string bidId); // Search for a bid
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr; // Initialize the root to nullptr
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    postOrderDelete(root); // Delete all nodes in post-order
}

/**
 * Helper method to delete all nodes in post-order
 */
void BinarySearchTree::postOrderDelete(Node* node) {
    if (node != nullptr) {
        postOrderDelete(node->left);
        postOrderDelete(node->right);
        delete node;
    }
}

/**
 * Public method to traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    inOrder(root);
}

/**
 * Recursive in-order traversal
 */
void BinarySearchTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        displayBid(node->bid); // Display the bid
        inOrder(node->right);
    }
}

/**
 * Public method to traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    postOrder(root);
}

/**
 * Recursive post-order traversal
 */
void BinarySearchTree::postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        displayBid(node->bid); // Display the bid
    }
}

/**
 * Public method to traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    preOrder(root);
}

/**
 * Recursive pre-order traversal
 */
void BinarySearchTree::preOrder(Node* node) {
    if (node != nullptr) {
        displayBid(node->bid); // Display the bid
        preOrder(node->left);
        preOrder(node->right);
    }
}

/**
 * Public method to insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    if (root == nullptr) {
        root = new Node(bid); // Create root if tree is empty
    } else {
        addNode(root, bid); // Call recursive addNode
    }
}

/**
 * Recursive helper method to add a bid to the tree
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    if (bid.bidId < node->bid.bidId) {
        // Traverse left subtree
        if (node->left == nullptr) {
            node->left = new Node(bid); // Create a new node if left is empty
        } else {
            addNode(node->left, bid); // Recurse down the left subtree
        }
    } else {
        // Traverse right subtree
        if (node->right == nullptr) {
            node->right = new Node(bid); // Create a new node if right is empty
        } else {
            addNode(node->right, bid); // Recurse down the right subtree
        }
    }
}

/**
 * Public method to remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    root = removeNode(root, bidId);
}

/**
 * Recursive helper method to remove a bid from the tree
 */
Node* BinarySearchTree::removeNode(Node* node, string bidId) {
    if (node == nullptr) return node; // Node not found

    if (bidId < node->bid.bidId) {
        node->left = removeNode(node->left, bidId); // Traverse left subtree
    } else if (bidId > node->bid.bidId) {
        node->right = removeNode(node->right, bidId); // Traverse right subtree
    } else {
        // Node found
        if (node->left == nullptr && node->right == nullptr) {
            delete node; // No children
            return nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node->right; // One child (right)
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left; // One child (left)
            delete node;
            return temp;
        } else {
            // Two children
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left; // Find the minimum value in the right subtree
            }
            node->bid = temp->bid; // Replace with the successor's value
            node->right = removeNode(node->right, temp->bid.bidId); // Remove successor
        }
    }
    return node;
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    Node* current = root;

    while (current != nullptr) {
        if (current->bid.bidId == bidId) {
            return current->bid; // Return the bid if found
        } else if (bidId < current->bid.bidId) {
            current = current->left; // Traverse left subtree
        } else {
            current = current->right; // Traverse right subtree
        }
    }
    return Bid(); // Return an empty bid if not found
}

/**
 * Display a bid's details
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | " << bid.fund << endl;
}

/**
 * Load a CSV file containing bids into a binary search tree
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    csv::Parser file = csv::Parser(csvPath);

    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << endl;

    try {
        for (unsigned int i = 0; i < file.rowCount(); i++) {
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');
            bst->Insert(bid);
        }
    } catch (csv::Error& e) {
        cerr << e.what() << endl;
    }
}

/**
 * Convert a string to a double
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * Main program
 */
int main(int argc, char* argv[]) {
    string csvPath, bidKey;
    switch (argc) {
        case 2:
            csvPath = argv[1];
            bidKey = "98223";
            break;
        case 3:
            csvPath = argv[1];
            bidKey = argv[2];
            break;
        default:
            csvPath = "eBid_Monthly_Sales.csv";
            bidKey = "98223";
    }

    clock_t ticks;
    BinarySearchTree* bst = new BinarySearchTree();

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:\n  1. Load Bids\n  2. Display All Bids\n  3. Find Bid\n  4. Remove Bid\n  9. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ticks = clock();
                loadBids(csvPath, bst);
                ticks = clock() - ticks;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                break;
            case 2:
                bst->InOrder();
                break;
            case 3:
                ticks = clock();
                displayBid(bst->Search(bidKey));
                ticks = clock() - ticks;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                break;
            case 4:
                bst->Remove(bidKey);
                break;
        }
    }

    delete bst;
    cout << "Goodbye." << endl;
    return 0;
}
