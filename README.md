#Two Sum

Jira: DF11402, Space: 11402_CS351

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume each input has exactly one solution, and you cannot use the same element twice.

## Planning & Strategy: Two Sum

### 🎯 Objective
Given an array of integers and a target value, identify the indices of the two numbers that sum up to the target. Constraints guarantee exactly one valid solution and stipulate that the same element cannot be used twice.

### 🧠 Proposed Approaches

We will implement and compare two distinct methods to solve this problem:

#### 1. Brute Force (`TwoSumArray`)
* **Concept:** Use nested loops to check every possible pair in the array to see if they add up to the target.
* **Pros:** Very simple to implement; requires no additional memory allocation.
* **Cons:** Highly inefficient for large datasets.
* **Time Complexity:** $O(n^2)$ because we iterate through the rest of the array for every element.
* **Space Complexity:** $O(1)$ because we only store a few variables for indices.

#### 2. One-Pass Hash Table (`TwoSumHashTable`) - *Optimal*
* **Concept:** Iterate through the array once. For each element, calculate its `complement` (target - current value) and check if we have already seen it using a Hash Map.
* **Pros:** Significantly faster and scales well with large arrays.
* **Cons:** Requires extra memory to store the array elements in the map.
* **Time Complexity:** $O(n)$ because we traverse the array exactly once, and Hash Map lookups take $O(1)$ time on average.
* **Space Complexity:** $O(n)$ because, in the worst-case scenario, we might need to store all $n$ elements in the Hash Map.

---

### ⚙️ Implementation Logic (Optimal Approach)

1.  **Initialize Data Structure:** Create an `unordered_map` (Hash Table) to store the values we traverse as keys, and their array indices as values.
2.  **Iterate:** Loop through the given array `nums` from start to finish.
3.  **Calculate Complement:** For the current element `nums[i]`, compute `complement = target - nums[i]`.
4.  **Verify:** * If `complement` exists in the map, we have found our pair. Return the index stored in the map and the current index `i`.
    * If `complement` does not exist, insert the current element `nums[i]` and its index `i` into the map.
5.  **Edge Case Handling:** Return an empty array fallback if no solution is found (though the problem guarantees one exists).