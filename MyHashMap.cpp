// Question 1 Solution in C++:
//   
// Implement a hash map from scratch that supports the following operations:

// put(key, value): Insert a (key, value) pair into the hash map. If the key already exists, update the value.
// get(key): Retrieve the value associated with the key. If the key does not exist, return -1.
// remove(key): Remove the key and its associated value from the hash map if the key exists.

    
#include <iostream>
#include <vector>
#include <list>
#include <utility>

class MyHashMap {
private:
    std::vector<std::list<std::pair<int, int>>> map;
    const static int size = 1000;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() : map(size) {}

    void put(int key, int value) {
        int h = hash(key);
        for (auto& kvp : map[h]) {
            if (kvp.first == key) {
                kvp.second = value;
                return;
            }
        }
        map[h].emplace_back(key, value);
    }

    int get(int key) {
        int h = hash(key);
        for (const auto& kvp : map[h]) {
            if (kvp.first == key) {
                return kvp.second;
            }
        }
        return -1; // Not found
    }

    void remove(int key) {
        int h = hash(key);
        auto& list = map[h];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    std::cout << hashMap.get(1) << std::endl; // returns 1
    std::cout << hashMap.get(3) << std::endl; // returns -1 (not found)
    hashMap.put(2, 1); // update the existing value
    std::cout << hashMap.get(2) << std::endl; // returns 1
    hashMap.remove(2); // remove the mapping for 2
    std::cout << hashMap.get(2) << std::endl; // returns -1 (not found)
    return 0;
}
