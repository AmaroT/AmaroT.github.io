# Algorithms & Data Structures

## Original Artifact
**Course**: CS-300 – Data Structures and Algorithms  
**Artifacts**:  
- Advising Assistance Project (Binary Search Tree for course management)  
- Hash Table Project (with chaining for fast lookups)

**Description**: C++ console applications that load data from CSV files, insert into a recursive BST or hash table with chaining, print sorted lists (BST), and support search operations for course or bid details.

## Enhancement Description
The enhancement focuses on improving performance and reliability:

### Key Enhancements
- Added **self-balancing (AVL rotations)** to the Binary Search Tree → guarantees O(log n) worst-case operations  
- Optional hybrid access: BST for ordered traversal + hash table for O(1) average-case lookups  
- Added performance benchmarking (timing comparisons on large datasets)  
- Improved error handling and input validation  

These changes address limitations in unbalanced trees and demonstrate deeper understanding of algorithmic trade-offs (space vs. time, worst-case vs. average-case).

### Alignment with Course Outcomes
- **Outcome 3**: Design and evaluate solutions using algorithmic principles and managing trade-offs  
- **Outcome 4**: Use of well-founded and innovative techniques (balancing, hybrid structures) for efficient computing  

### Visuals & Code
**Live Code & Details**  
[View enhanced CS-300 folder and code](https://github.com/AmaroT/AmaroT.github.io/tree/main/enhanced-artifacts/cs-300)  
[README with summary & test instructions](https://github.com/AmaroT/AmaroT.github.io/blob/main/enhanced-artifacts/cs-300/README.md)

**Time Complexity Comparison**  
- Original unbalanced BST: O(n) worst-case  
- Enhanced AVL BST: O(log n) worst-case & average  
- Hash Table: O(1) average-case lookup

This work showcases advanced data structure implementation and optimization skills.
