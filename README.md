# CodeStack - Competitive Programming & Algorithm Collection

A comprehensive collection of C++ implementations for competitive programming, data structures, and algorithms. This repository contains optimized solutions for common algorithmic problems and patterns.

## Repository Structure

### Tree Algorithms
- **`morrisInorder.cpp`** - Morris Inorder Traversal (O(1) space complexity)

### Backtracking & Recursion
- **`combinationSum.cpp`** - Combination Sum I (with repetition allowed)
- **`combinationSum2.cpp`** - Combination Sum II (unique combinations)
- **`combinationSum3.cpp`** - Combination Sum III (fixed count)
- **`nQueen.cpp`** - N-Queens Problem solver
- **`permutation.cpp`** - Generate all permutations
- **`wordSearch.cpp`** - 2D grid word search with backtracking
- **`Rec.cpp`** - General recursion patterns
- **`recKunal1.cpp`** - Recursion practice problems

### Dynamic Programming
- **`knapsack.cpp`** - 0/1 Knapsack with memoization
- **`genParaDP.cpp`** - Generate parentheses using DP
- **`uniquePathLc.cpp`** - Unique paths in grid (space-optimized)
- **`subsetSum.cpp`** - Subset sum problem

### Number Theory & Mathematics
- **`seive.cpp`** - Incremental Sieve of Eratosthenes
- **`numTheory.cpp`** - Number theory algorithms

### Sorting & Searching
- **`mergeSort.cpp`** - Merge sort implementation

### Sliding Window
- **`sliding.cpp`** - General sliding window pattern template

### String Algorithms
- **`string.cpp`** - String manipulation algorithms
- **`subString.cpp`** - Substring generation
- **`SubSeq.cpp`** - Subsequence generation (recursive & iterative)
- **`letterCombo.cpp`** - Letter combinations (phone keypad)
- **`palindromparti.cpp`** - Palindrome partitioning

### Array & Subarray Problems
- **`subArray.cpp`** - Subarray algorithms

### Competitive Programming
- **`serviceq1.cpp`** - Service queue problem

## Key Features

### Optimized Implementations
- **Space-optimized algorithms** (Morris traversal, DP optimizations)
- **Incremental data structures** (Sieve with dynamic expansion)
- **Template-based solutions** for reusability

### Problem Categories Covered
- **Backtracking**: N-Queens, Combination problems, Word search
- **Dynamic Programming**: Knapsack, Path counting, Subset problems
- **Tree Traversals**: Morris algorithm for constant space
- **Number Theory**: Prime generation, Mathematical computations
- **String Processing**: Pattern matching, Subsequence generation

### Coding Patterns
- **DFS with backtracking**
- **Memoization techniques**
- **Sliding window approach**
- **Two-pointer methods**

## Usage

### Compilation
```bash
g++ -o output filename.cpp
./output
```

### For competitive programming:
```bash
g++ -std=c++17 -O2 -o solution filename.cpp
```

## Algorithm Complexities

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Morris Inorder | O(n) | O(1) |
| N-Queens | O(N!) | O(N²) |
| Knapsack (Memo) | O(n×W) | O(n×W) |
| Merge Sort | O(n log n) | O(n) |
| Sieve of Eratosthenes | O(n log log n) | O(n) |
| Combination Sum | O(2^n) | O(target/min) |

## Problem Sources
- LeetCode problems
- Competitive programming contests
- Algorithm design patterns
- Data structure implementations

## Code Style
- Clean, readable C++ code
- Comprehensive comments
- Optimized for competitive programming
- Standard template library usage

## Requirements
- C++11 or higher
- Standard Template Library (STL)
- Compatible with most online judges

---
*This collection serves as a reference for competitive programming and algorithm interviews.*