# Advising Assistance Project

## Overview

The Advising Assistance Project is a C++ command-line application designed to assist academic advisors in efficiently managing course information. The application allows users to load course data, print a list of courses in alphanumeric order, and display detailed information about a specific course, including its title and prerequisites. This project demonstrates the use of Binary Search Trees (BSTs) to store and retrieve course data efficiently.

## Features

1. **Load Course Data:**
    - Load course information from a CSV file into a Binary Search Tree (BST) for efficient storage and retrieval.

2. **Print All Courses:**
    - Display all courses in alphanumeric order based on their course numbers.

3. **Print Course Information:**
    - Search for a specific course and display its title along with any prerequisites.
    - If no prerequisites are required, the program will indicate "No prerequisites."

4. **Error Handling:**
    - Handles invalid file names, ensuring that errors are displayed when a file cannot be opened.
    - Validates menu input to prevent infinite loops or crashes due to invalid entries.

5. **Industry Best Practices:**
    - Clean and modular code design with appropriate naming conventions.
    - In-line comments for enhanced readability and maintainability.

## Menu Options

- **Option 1:** Load course data from a CSV file.
- **Option 2:** Print an alphanumeric list of all courses.
- **Option 3:** Search for a course by its number and display its details, including prerequisites.
- **Option 9:** Exit the program.

## How to Use

### Prerequisites
1. A C++ compiler (e.g., GCC, Clang) supporting C++11 or later.
2. A CSV file containing course data in the following format:

Example: CSCI100,Introduction to Computer Science CSCI101,Introduction to Programming in C++,CSCI100 CSCI200,Data Structures,CSCI101


### Steps
1. Place the `ProjectTwo.cpp` file and the course data CSV file (e.g., `courses.csv`) in the same directory.
2. Compile the program using a C++ compiler:
```bash
g++ ProjectTwo.cpp -o AdvisingAssistance
```
3. Run the program 
```bash
./AdvisingAssistance
```
4.Follow the on-screen menu to load course data, view courses, or search for a specific course.

###Project Structure
-   ProjectTwo.cpp: Main program file containing the implementation of the Advising Assistance application.
-   Binary Search Tree (BST): 
    -   Stores course data for efficient insertion, retrieval, and traversal. 
    -   Handles course search and retrieval in logarithmic time complexity (O(log n)) for balanced trees.
### Example Run
Input
```bash
Menu:
1. Load Course Data
2. Print All Courses
3. Print Course Information
9. Exit
   Enter your choice: 1
   Enter the file name: courses.csv
```
Output
```bash
Courses loaded successfully.

Menu:
1. Load Course Data
2. Print All Courses
3. Print Course Information
9. Exit
Enter your choice: 2

Here is a sample schedule:
CSCI100, Introduction to Computer Science
CSCI101, Introduction to Programming in C++
CSCI200, Data Structures
MATH201, Discrete Mathematics
CSCI300, Introduction to Algorithms
CSCI301, Advanced Programming in C++
CSCI350, Operating Systems
CSCI400, Large Software Development

Menu:
1. Load Course Data
2. Print All Courses
3. Print Course Information
9. Exit
Enter your choice: 3
What course do you want to know about? CSCI300

CSCI300, Introduction to Algorithms
Prerequisites: CSCI200, MATH201
```

### Key Concepts and Technologies
1.Binary Search Tree (BST):
-   Used for efficient storage and retrieval of course data.
-   In-order traversal ensures that courses are displayed in sorted order. 
    
2.File Handling:

-   Reads course data from a CSV file.
-   Handles invalid file names and format issues gracefully.

3.Error Handling:

-   Validates menu input to prevent crashes.
-   Displays meaningful error messages for invalid inputs or file issues.

4.Code Modularity:

-   Functions are logically separated, each performing a single responsibility.
-   Ensures maintainability and reusability of code.

### Future Enhancements
1. Add support for additional file formats (e.g., JSON, XML).
2. Implement a graphical user interface (GUI) for enhanced usability.
3. Add functionality to update or delete course information dynamically.

### Author
Amaro Terrazas

This project is part of the CS 300 course for demonstrating mastery of data structures and algorithm design in C++.