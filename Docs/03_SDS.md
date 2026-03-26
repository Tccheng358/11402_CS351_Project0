
# Software Design Specification (SDS)

## 1. Overview
This document describes the design of a Two Sum problem solver application written in C++.

## 2. System Architecture
The application consists of two main components:
- **main.cpp**: Entry point and user interface
- **twosum.cpp**: Core algorithm implementation

## 3. Components

### 3.1 Main Module (main.cpp)
**Purpose**: Program entry point and user interaction
- Handles input/output operations
- Calls the Two Sum solver function
- Manages program flow

### 3.2 Two Sum Module (twosum.cpp)
**Purpose**: Core problem-solving logic
- Implements algorithm to find two numbers that sum to a target value
- Returns indices of a matching pair
- Optimized for performance

## 4. Data Structures
- Array/Vector for input numbers
- Hash map for O(1) lookup (if hash-based approach used)

## 5. Algorithm
- **Approach A (twoSumArray)**: Brute-force nested loops
- **Approach B (twoSumHashMap)**: Single pass hash map lookup
- **Time Complexity**: O(n²) for array approach, O(n) for hash map approach
- **Space Complexity**: O(1) for array approach, O(n) for hash map approach

## 6. Interfaces

### Function Signature
```cpp
vector<int> twoSumArray(vector<int>& nums, int target);
vector<int> twoSumHashMap(vector<int>& nums, int target);
```

## 7. Testing
- Unit tests for various input cases
- Edge cases (empty array, no solution, duplicates)
