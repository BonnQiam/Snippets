#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

template <typename K, typename V>
class MyChainingHashMap {
private:
    // Structure to represent a key-value node in the linked list
    struct KVNode {
        K key;
        V value;

        KVNode(K key, V value) : key(key), value(value) {}
    };

    // Hash table: a vector of linked lists, each linked list contains KVNodes
    std::vector<std::list<KVNode>> table;
    int size; // Number of key-value pairs in the hash map
    static const int INIT_CAP = 4; // Initial capacity of the hash table

    // Hash function to convert the key to a valid index in the table
    int hash(const K& key) const {
        return std::hash<K>{}(key) & 0x7fffffff % table.size();
    }

    // Resize the hash table to a new capacity
    void resize(int newCap) {
        // Create a new hash map with the new capacity
        MyChainingHashMap<K, V> newMap(newCap);
        // Move all key-value pairs to the new hash map
        for (const auto& list : table) {
            for (const auto& node : list) {
                newMap.put(node.key, node.value);
            }
        }
        // Replace the old table with the new table
        this->table = std::move(newMap.table);
        this->size = newMap.size;
    }

public:
    // Default constructor with initial capacity
    MyChainingHashMap() : MyChainingHashMap(INIT_CAP) {}

    // Constructor with custom initial capacity
    MyChainingHashMap(int initCapacity) : table(initCapacity), size(0) {}

    // Add or update a key-value pair
    void put(const K& key, const V& val) {
        if (!key) {
            throw std::invalid_argument("key is null");
        }
        auto& list = table[hash(key)];
        // If key already exists, update the value
        for (auto& node : list) {
            if (node.key == key) {
                node.value = val;
                return;
            }
        }
        // If key does not exist, insert the new key-value pair
        list.emplace_back(key, val);
        ++size;

        // If the number of elements exceeds the load factor, resize the table
        if (size >= table.size() * 0.75) {
            resize(table.size() * 2);
        }
    }

    // Remove a key-value pair
    void remove(const K& key) {
        if (!key) {
            throw std::invalid_argument("key is null");
        }
        auto& list = table[hash(key)];
        // If key exists, remove it and decrease the size
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->key == key) {
                list.erase(it);
                --size;

                // If the number of elements falls below a certain threshold, resize the table
                if (size <= table.size() / 8) {
                    resize(table.size() / 4);
                }
                return;
            }
        }
    }

    // Get the value associated with the key
    V get(const K& key) const {
        if (!key) {
            throw std::invalid_argument("key is null");
        }
        const auto& list = table[hash(key)];
        // If key exists, return the value
        for (const auto& node : list) {
            if (node.key == key) {
                return node.value;
            }
        }
        // If key does not exist, throw an error
        throw std::runtime_error("Key not found");
    }

    // Get all keys in the hash map
    std::vector<K> keys() const {
        std::vector<K> keys;
        for (const auto& list : table) {
            for (const auto& node : list) {
                keys.push_back(node.key);
            }
        }
        return keys;
    }

    // Get the number of key-value pairs in the hash map
    int getSize() const {
        return size;
    }
};

#if 0

int main() {
    MyChainingHashMap<int, int> map;
    map.put(1, 1);
    map.put(2, 2);
    map.put(3, 3);
    std::cout << map.get(1) << std::endl; // 1
    std::cout << map.get(2) << std::endl; // 2

    map.put(1, 100);
    std::cout << map.get(1) << std::endl; // 100

    map.remove(2);
    try {
        std::cout << map.get(2) << std::endl; // Throws runtime_error
    } catch (const std::runtime_error& e) {
        std::cout << "Key not found" << std::endl; // Key not found
    }

    auto keys = map.keys();
    for (const auto& key : keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl; // 1 3 (order may vary)

    return 0;
}

#endif