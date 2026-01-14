# Linked List Bid Management System

## Project Overview
This project is a C++ program that implements a singly linked list to manage bid data for a municipal government auction system. The program reads bid data from CSV files, stores them in a linked list, and allows users to perform various operations, including appending, prepending, searching, displaying, and removing bids. Additionally, users can select between two CSV files to load data, providing flexibility in testing with different datasets.

## Features
- **Linked List Operations**: Supports essential linked list functionalities such as `Append`, `Prepend`, `Search`, and `Remove`, allowing dynamic management of bids.
- **File Handling**: Loads bid data from CSV files based on user input. Users can choose to load either a large dataset or a smaller subset.
- **Menu Options**: Provides an interactive console menu to guide the user through different operations on the bid data, including entering a new bid, loading bids, displaying all bids, finding a bid, and removing a bid.
- **Efficient Memory Management**: Designed with careful memory handling, using pointers and a destructor to manage dynamic memory allocation.

## Project Structure
```plaintext
LinkedListProject/
├── LinkedList.cpp           # Main program file with linked list and bid management functions
├── CSVparser.hpp            # Header file for CSV parser library
├── CSVparser.cpp            # CSV parser implementation for reading data files
├── eBid_Monthly_Sales.csv   # Large dataset of bids (12,023 bids)
├── eBid_Monthly_Sales_Dec_2016.csv # Small dataset of bids (76 bids)
├── CMakeLists.txt           # CMake configuration for building the project
└── README.md                # Project documentation
```
## Installation and Setup
1. Clone the Repository: Download the project to your local machine.
```plaintext
bash
Copy code
git clone https://github.com/AmaroT/CS-Portfolio-Projects.git
cd LinkedList
```
2. Build the Project:

- Ensure you have 'CMake' installed. On macOS, you can install it via Homebrew:
```plaintext
bash
Copy code
brew install cmake
```
- Create a build directory, navigate to it, and run `cmake`:
```plaintext
bash
Copy code
mkdir build
cd build
cmake ..
cmake --build .
```
3. Run the Program:
```plaintext
bash
Copy code
./LinkedList
```
## Usage Instructions
Upon running the program, you will see a menu with options to:

1. Enter a new bid manually.
2. Load bids from a CSV file.
3. Display all bids in the list.
4. Find a specific bid by its ID.
5. Remove a bid by its ID.
6. Exit the program.
## Loading Bids
To load bids, choose option 2 in the menu. You will then be prompted to select one of the following files:

- `eBid_Monthly_Sales.csv` - The larger dataset with 12,023 bids.
- `eBid_Monthly_Sales_Dec_2016.csv` - A smaller dataset with 76 bids.
  
The program will display the total number of bids loaded and the time taken to load them.

## Example Usage
1. Enter a Bid:

- Input the bid ID, title, fund, and amount.
- The bid is appended to the list, and details are displayed.
2. Find a Bid:
- Enter the bid ID, and the program will display the details if found.
3. Remove a Bid:
- Input the bid ID to remove from the list.
## Key Challenges and Solutions
1. Environment Setup on Mac (Apple Silicon): Configuring IntelliJ to build C++ on Mac with Apple Silicon required downloading and setting up tools like CMake and Homebrew for dependencies.
2. Dynamic File Selection: Modifying the code to prompt for a file selection during runtime enhanced user flexibility.
3. Pointer Management: Carefully handling pointers in linked list operations (such as updating `head` and `tail` pointers) ensured list integrity, particularly for `Remove` and `Append` functions.

## Requirements
- C++ compiler (GCC or Clang)
- CMake for build configuration
- CSV parser library (provided in the project)

## License
This project is licensed under the MIT License. See `License.txt` for more details.




