// Author: Amaro Terrazas

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Structure to hold course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Node structure for Binary Search Tree
struct Node {
    Course course;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(Course courseData, Node* leftChild = nullptr, Node* rightChild = nullptr)
        : course(courseData), left(leftChild), right(rightChild){}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    void inOrderTraversal(Node* node);
    void addNode(Node*& node, Course course);
    Course* searchNode(Node* node, const string& courseNumber);

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(root); }

    void insert(Course course);
    void printCourses();
    Course* search(const string& courseNumber);
    void clear(Node* node);
};

void BinarySearchTree::inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->course.courseNumber << ", " << node->course.courseTitle << endl;
        inOrderTraversal(node->right);
    }
}

void BinarySearchTree::addNode(Node*& node, Course course) {
    if (node == nullptr) {
        node = new Node{course};
    } else if (course.courseNumber < node->course.courseNumber) {
        addNode(node->left, course);
    } else {
        addNode(node->right, course);
    }
}

Course* BinarySearchTree::searchNode(Node* node, const string& courseNumber) {
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

void BinarySearchTree::insert(Course course) {
    addNode(root, course);
}

void BinarySearchTree::printCourses() {
    inOrderTraversal(root);
}

Course* BinarySearchTree::search(const string& courseNumber) {
    return searchNode(root, courseNumber);
}

void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Helper function to convert string to uppercase
string toUpperCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to load courses from a CSV file into the BST
void loadCourses(const string& fileName, BinarySearchTree& bst) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << fileName << "'. Please ensure the file exists and is accessible." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        // Remove leading and trailing commas
        line.erase(0, line.find_first_not_of(","));
        line.erase(line.find_last_not_of(",") + 1);

        stringstream ss(line);
        string token;
        Course course;

        // Parse course number
        getline(ss, token, ',');
        if (token.empty()) continue; // Skip invalid lines
        course.courseNumber = token;

        // Parse course title
        getline(ss, token, ',');
        course.courseTitle = token;

        // Parse prerequisites
        while (getline(ss, token, ',')) {
            if (!token.empty()) { // Skip empty prerequisites
                course.prerequisites.push_back(token);
            }
        }

        // Insert the course into the BST
        bst.insert(course);
    }

    file.close();
    cout << "Courses loaded successfully." << endl;
}



// Function to print course information
void printCourseInformation(BinarySearchTree& bst, const string& courseNumber) {
    Course* course = bst.search(courseNumber);
    if (course != nullptr) {
        cout << course->courseNumber << ", " << course->courseTitle << endl;
        if (!course->prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < course->prerequisites.size(); ++i) {
                cout << course->prerequisites[i];
                if (i < course->prerequisites.size() - 1) {
                    cout << ", "; // Add a comma between prerequisites
                }
            }
            cout << endl;
        } else {
            // Handle case with no prerequisites
            cout << "Prerequisites: No prerequisites" << endl;
        }
    } else {
        cout << "Course not found." << endl;
    }
}



// Display the menu
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Load Course Data" << endl;
    cout << "2. Print All Courses" << endl;
    cout << "3. Print Course Information" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    BinarySearchTree bst;
    string filename;
    int choice = 0;

    while (choice != 9) {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter the file name: ";
                cin >> filename;
                loadCourses(filename, bst);
                break;

            case 2:
                cout << "Here is a sample schedule:" << endl;
                bst.printCourses();
                break;

            case 3: {
                string courseNumber;
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                printCourseInformation(bst, courseNumber);
                break;
            }

            case 9:
                cout << "Thank you for using the course planner!" << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}
