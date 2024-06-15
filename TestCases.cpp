// Test Cases for C++ Code

#include <cassert>

void testMyHashMap() {
    MyHashMap hashMap;

    // Test put and get
    hashMap.put(1, 1);
    assert(hashMap.get(1) == 1); // Expect 1
    assert(hashMap.get(2) == -1); // Expect -1 (not found)

    // Test update
    hashMap.put(2, 2);
    assert(hashMap.get(2) == 2); // Expect 2
    hashMap.put(2, 1);
    assert(hashMap.get(2) == 1); // Expect 1 (updated value)

    // Test remove
    hashMap.remove(2);
    assert(hashMap.get(2) == -1); // Expect -1 (removed)
}

void testCountPairsWithSum() {
    std::vector<int> nums1 = {1, 5, 7, -1, 5};
    int target1 = 6;
    assert(countPairsWithSum(nums1, target1) == 3); // 1+5, 1+5, 7+(-1)

    std::vector<int> nums2 = {1, 1, 1, 1};
    int target2 = 2;
    assert(countPairsWithSum(nums2, target2) == 6); // 1+1 six times
}

int main() {
    testMyHashMap();
    testCountPairsWithSum();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}
