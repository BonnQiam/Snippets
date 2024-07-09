#include <unordered_map>

template <typename K>
class MyHashSet {
private:
    // Placeholder value
    static constexpr int PRESENT = 0;
    // Underlying unordered_map
    std::unordered_map<K, int> map;

public:
    // Add a key to the set
    void add(const K& key) {
        map[key] = PRESENT;
    }

    // Remove a key from the set
    void remove(const K& key) {
        map.erase(key);
    }

    // Check if the set contains a key
    bool contains(const K& key) const {
        return map.find(key) != map.end();
    }

    // Get the size of the set
    int size() const {
        return map.size();
    }
};
