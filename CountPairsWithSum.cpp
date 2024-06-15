// Question 2 Solution in C++:
// 
// Count the number of pairs in an array with a given sum using a hash map.

// Given an array of integers and a target sum, return the number of pairs of integers in the array that add up to the target sum.
  
#include <iostream>
#include <unordered_map>
#include <vector>

int countPairsWithSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    int count = 0;

    for (int num : nums) {
        int complement = target - num;
        if (numMap[complement] > 0) {
            count += numMap[complement];
        }
        numMap[num]++;
    }
    return count;
}

int main() {
    std::vector<int> nums = {1, 5, 7, -1, 5};
    int target = 6;
    std::cout << "Count of pairs is " << countPairsWithSum(nums, target) << std::endl;
    return 0;
}
