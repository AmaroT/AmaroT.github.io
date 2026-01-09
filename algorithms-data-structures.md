# Algorithms & Data Structures

## Original Artifact
**Course**: CS-300 – Data Structures and Algorithms  
**Artifacts**:  
- Advising Assistance Project (Binary Search Tree for course management)  
- Hash Table Project (with chaining for fast lookups)

**Description**: C++ implementations for storing, searching, and sorting course/bid data using BST and hash tables.

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
[View the enhanced BST/Hash Table repository](https://github.com/AmaroT/cs300-enhanced) *(pending real link)*

*(Add before/after screenshots or complexity table here)*  
**Time Complexity Comparison**  
- Original unbalanced BST: O(n) worst-case  
- Enhanced AVL BST: O(log n) worst-case & average  
- Hash Table: O(1) average-case lookup

This work showcases advanced data structure implementation and optimization skills.
