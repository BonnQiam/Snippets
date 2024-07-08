#include <iostream>
#include <vector>

// 用线性探查法解决哈希冲突的简化实现（特殊占位符版）
// Special placeholder for deleted elements. 
// 用于标记被删元素的占位符
struct KVNode {
    int key;
    int val;
};

class ExampleLinearProbingHashMap2 {
private:
    // 真正存储键值对的数组
    std::vector<KVNode*> table;
    // 里面的值可以随意存储，因为只会使用 == 判断指针相等，不用比较里面的值
    KVNode* DELETED = new KVNode{-2, -2};
    
    // 哈希函数，将键映射到 table 的索引
    int hash(int key) {
        return key % table.size();
    }

    // 线性探测法查找 key 在 table 中的索引，如果找不到，返回 -1
    int findKeyIndex(int key) {
        // 因为删除元素时只是标记为 DELETED，并不是真的删除，所以 table 可能会被填满，导致死循环
        // step 用来记录查找的步数，防止死循环
        for (int i = hash(key), step = 0; table[i] != nullptr; i = (i+1) % table.size()) {
            // 遇到占位符直接跳过
            if (table[i] == DELETED) continue;
            if (table[i]->key == key) return i;
            if (++step == table.size()) return -1;
        }

        return -1;
    }

public:
    // 构造函数，初始化哈希表容量
    explicit ExampleLinearProbingHashMap2(int initCapacity) {
        table.resize(initCapacity, nullptr);
    }

    // 增/改
    void put(int key, int val) {
        int index = findKeyIndex(key);
        // key 已存在，修改对应的 val，如果 key 不存在，新建节点并插入表中
        if (index != -1 && table[index] != nullptr) {
            table[index]->val = val;
            return;
        }

        KVNode* node = new KVNode{key, val};
        index = hash(key);
        while (table[index] != nullptr && table[index] != DELETED) {
            index = (index+1) % table.size();// 环形数组
        }
        table[index] = node;
    }

    // 删
    void remove(int key) {
        int index = findKeyIndex(key);
        // key 不存在，不需要 remove
        if (index == -1) return;
        // 直接用占位符表示删除
        table[index] = DELETED;
    }

    // 查，返回 key 对应的 val，如果 key 不存在，则返回 -1
    int get(int key) {
        int index = findKeyIndex(key);
        return (index != -1) ? table[index]->val : -1;
    }
};

int main() {
    ExampleLinearProbingHashMap2 map(10);
    map.put(1, 1);
    map.put(2, 2);
    map.put(10, 10);
    map.put(20, 20);
    map.put(30, 30);
    map.put(3, 3);
    std::cout << map.get(1) << std::endl;  // Output: 1
    std::cout << map.get(2) << std::endl;  // Output: 2
    std::cout << map.get(20) << std::endl; // Output: 20

    map.put(1, 100);
    std::cout << map.get(1) << std::endl;  // Output: 100

    map.remove(20);
    std::cout << map.get(20) << std::endl; // Output: -1
    std::cout << map.get(30) << std::endl; // Output: 30

    return 0;
}