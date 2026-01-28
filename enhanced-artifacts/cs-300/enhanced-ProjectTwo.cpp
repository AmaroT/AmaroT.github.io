// Author: Amaro Terrazas
// Enhanced for CS-499: AVL-balanced BST

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

#include "enhanced-BinarySearchTree.h" 

using namespace std;

// (Removed duplicate struct Course - it's in the header)

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
        line.erase(0, line.find_first_not_of(","));
        line.erase(line.find_last_not_of(",") + 1);

        stringstream ss(line);
        string token;
        Course course;

        getline(ss, token, ',');
        if (token.empty()) continue;
        course.courseNumber = token;

        getline(ss, token, ',');
        course.courseTitle = token;

        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                course.prerequisites.push_back(token);
            }
        }

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
                    cout << ", ";
                }
            }
            cout << endl;
        } else {
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