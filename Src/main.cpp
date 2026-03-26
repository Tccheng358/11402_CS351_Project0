// Main Program to call the Two Sum Functions
#include <iostream>
#include <vector>

using namespace std;

// Forward declarations of the functions located in twosum.cpp
vector<int> twoSumArray(vector<int>& nums, int target);
vector<int> twoSumHashMap(vector<int>& nums, int target);

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call whichever version you want to test from twosum.cpp
    // Let's test the HashMap version:
    vector<int> result = twoSumHashMap(nums, target);

    cout << "Input: nums = [2, 7, 11, 15], target = 9" << endl;
    
    // Safety check to ensure a result was found before printing
    if (!result.empty()) {
        cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
// Do not implement the function here. Leave the implementation in twosum.cpp!