#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <list>

// Linear Probing HashMap with dummy placeholders for deleted entries
template<typename K, typename V>
class MyLinearProbingHashMap2 {
private:
    // Structure to represent a key-value node
    struct KVNode {
        K key;
        V val;
        KVNode(K k, V v) : key(k), val(v) {}
    };

    // Dummy node to mark deleted entries
    KVNode* DUMMY = new KVNode(K(), V());

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
        int step = 0;
        for (int i = hash(key); table[i] != nullptr; i = (i + 1) % capacity) {
            KVNode* entry = table[i];
            if (entry == DUMMY) {
                continue;
            }
            if (entry->key == key) {
                return i;
            }
            step++;
            if (step == capacity) {
                // Trigger resize if a full loop has been made
                return -1;
            }
        }
        return -1;
    }

    // Resize the table to a new capacity
    void resize(int newCap) {
        MyLinearProbingHashMap2<K, V> newMap(newCap);
        for (KVNode* entry : table) {
            if (entry != nullptr && entry != DUMMY) {
                newMap.put(entry->key, entry->val);
                delete entry;
            }
        }
        table = std::move(newMap.table);
        capacity = newMap.capacity;
    }

public:
    // Constructor with default initial capacity
    MyLinearProbingHashMap2() : MyLinearProbingHashMap2(INIT_CAP) {}

    // Constructor with specified initial capacity
    MyLinearProbingHashMap2(int initCapacity) : size(0), capacity(initCapacity) {
        table.resize(capacity, nullptr);
    }

    // Destructor to clean up dynamically allocated memory
    ~MyLinearProbingHashMap2() {
        for (KVNode* entry : table) {
            if (entry != nullptr && entry != DUMMY) {
                delete entry;
            }
        }
        delete DUMMY;
    }

    // Add or update a key-value pair
    void put(const K& key, const V& val) {
        if (key == K()) {
            throw std::invalid_argument("key is null");
        }

        // Resize if load factor exceeds 0.75
        if (size >= capacity * 0.75) {
            resize(capacity * 2);
        }

        int index = getKeyIndex(key);
        if (index != -1) {
            // Key already exists, update its value
            table[index]->val = val;
            return;
        }

        // Key does not exist
        KVNode* x = new KVNode(key, val);
        // Find an empty slot or a dummy slot to insert
        index = hash(key);
        while (table[index] != nullptr && table[index] != DUMMY) {
            index = (index + 1) % capacity;
        }
        table[index] = x;
        size++;
    }

    // Remove a key-value pair
    void remove(const K& key) {
        if (key == K()) {
            throw std::invalid_argument("key is null");
        }

        // Resize if load factor drops below 0.125
        if (size < capacity / 8) {
            resize(capacity / 2);
        }

        int index = getKeyIndex(key);
        if (index == -1) {
            // Key does not exist
            return;
        }

        // Remove the entry by marking it with the dummy node
        table[index] = DUMMY;
        size--;
    }

    // Get the value associated with the key
    V get(const K& key) const {
        if (key == K()) {
            throw std::invalid_argument("key is null");
        }

        int index = getKeyIndex(key);
        if (index == -1) {
            return V(); // Key not found, return default value
        }
        return table[index]->val;
    }

    // Get all keys (order not guaranteed)
    std::list<K> keys() const {
        std::list<K> keys;
        for (KVNode* entry : table) {
            if (entry != nullptr && entry != DUMMY) {
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
    MyLinearProbingHashMap2<int, int> map;
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