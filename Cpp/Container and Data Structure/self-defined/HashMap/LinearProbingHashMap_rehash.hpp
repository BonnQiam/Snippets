#include <iostream>

#include <vector>
#include <stdexcept>
#include <utility>
#include <list>

// Linear Probing HashMap with rehashing
template<typename K, typename V>
class MyLinearProbingHashMap1 {
private:
    // Structure to represent a key-value node
    struct KVNode {
        K key;
        V val;
        KVNode(K k, V v) : key(k), val(v) {}
    };

    std::vector<KVNode*> table; // Vector of pointers to KVNode
    int size;
    int capacity;
    static const int INIT_CAP = 4; // Default initial capacity

    // Hash function to convert the key to a valid index in the table
    int hash(const K& key) const {
        return (std::hash<K>{}(key) & 0x7fffffff) % capacity;
    }

    // Linear probing to find the correct index for a key
    int getKeyIndex(const K& key) const {
        int index;
        for (index = hash(key); table[index] != nullptr; index = (index + 1) % capacity) {
            if (table[index]->key == key)
                return index;
        }
        return index;
    }

    // Resize the table to a new capacity
    void resize(int newCap) {
        MyLinearProbingHashMap1<K, V> newMap(newCap);
        for (KVNode* entry : table) {
            if (entry != nullptr) {
                newMap.put(entry->key, entry->val);
                delete entry;
            }
        }
        table = std::move(newMap.table);
        capacity = newMap.capacity;
    }

public:
    // Constructor with default initial capacity
    MyLinearProbingHashMap1() : MyLinearProbingHashMap1(INIT_CAP) {}

    // Constructor with specified initial capacity
    MyLinearProbingHashMap1(int initCapacity) : size(0), capacity(initCapacity) {
        table.resize(capacity, nullptr);
    }

    // Destructor to clean up dynamically allocated memory
    ~MyLinearProbingHashMap1() {
        for (KVNode* entry : table) {
            delete entry;
        }
    }

    // Add or update a key-value pair
    void put(const K& key, const V& val) {
        if (key == nullptr) {
            throw std::invalid_argument("key is null");
        }

        // Resize if load factor exceeds 0.75
        if (size >= capacity * 0.75) {
            resize(capacity * 2);
        }

        int index = getKeyIndex(key);
        // If key already exists, update its value
        if (table[index] != nullptr) {
            table[index]->val = val;
            return;
        }

        // Key does not exist, insert new entry
        table[index] = new KVNode(key, val);
        size++;
    }

    // Remove a key-value pair
    void remove(const K& key) {
        if (key == nullptr) {
            throw std::invalid_argument("key is null");
        }

        // Resize if load factor drops below 0.125
        if (size <= capacity / 8) {
            resize(capacity / 4);
        }

        int index = getKeyIndex(key);
        if (table[index] == nullptr) {
            // Key does not exist
            return;
        }

        // Remove the entry
        delete table[index];
        table[index] = nullptr;
        size--;

        // Rehash subsequent elements in the cluster
        for (index = (index + 1) % capacity; table[index] != nullptr; index = (index + 1) % capacity) {
            KVNode* entry = table[index];
            table[index] = nullptr;
            size--;
            put(entry->key, entry->val);
            delete entry;
        }
    }

    // Get the value associated with the key
    V get(const K& key) const {
        if (key == nullptr) {
            throw std::invalid_argument("key is null");
        }
        int index = getKeyIndex(key);
        if (table[index] == nullptr) {
            return V(); // Key not found, return default value
        }
        return table[index]->val;
    }

    // Get all keys (order not guaranteed)
    std::list<K> keys() const {
        std::list<K> keys;
        for (KVNode* entry : table) {
            if (entry != nullptr) {
                keys.push_back(entry->key);
            }
        }
        return keys;
    }

    // Get the current size of the hash map
    int getSize() const {
        return size;
    }
};

#if 0

int main() {
    MyLinearProbingHashMap1<int, int> map;
    map.put(1, 1);
    map.put(2, 2);
    map.put(10, 10);
    map.put(20, 20);
    map.put(30, 30);
    map.put(3, 3);
    std::cout << map.get(1) << std::endl; // Output: 1
    std::cout << map.get(2) << std::endl; // Output: 2
    std::cout << map.get(20) << std::endl; // Output: 20

    map.put(1, 100);
    std::cout << map.get(1) << std::endl; // Output: 100

    map.remove(20);
    std::cout << map.get(20) << std::endl; // Output: 0 (default value for int)
    std::cout << map.get(30) << std::endl; // Output: 30

    return 0;
}

#endif