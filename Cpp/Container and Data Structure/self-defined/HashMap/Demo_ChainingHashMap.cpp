#include <iostream>

#include <vector>
#include <list>
#include <algorithm>

// 用拉链法解决哈希冲突的简化实现
class ExampleChainingHashMap {

    // 链表节点，存储 key-value 对
    // 注意这里必须存储同时存储 key 和 value
    // 因为要通过 key 找到对应的 value
    struct KVNode {
        int key;
        int value;

        // 为了简化，我这里直接用标准库的 LinkedList 链表
        // 所以这里就不添加 next 指针了
        // 你当然可以给 KVNode 添加 next 指针，自己实现链表操作
        KVNode(int key, int value) : key(key), value(value) {}
    };

    // 底层 table 数组中的每个元素是一个链表
    std::vector<std::list<KVNode>> table;

public:
    ExampleChainingHashMap(int capacity) : table(capacity) {}

    int hash(int key) {
        return key % table.size();
    }

    // 查
    int get(int key) {
        int index = hash(key);

        if (table[index].empty()) {
            // 链表为空，说明 key 不存在
            return -1;
        }

        // 链表不为空，遍历链表查找 key
        for (const auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }

        // 链表中没有目标 key
        return -1;
    }

    // 增/改
    void put(int key, int value) {
        int index = hash(key);

        if (table[index].empty()) {
            // 链表为空，新建一个链表，插入 key-value
            table[index].push_back(KVNode(key, value));
            return;
        }

        // 链表不为空，要遍历一遍看看 key 是否已经存在
        // 如果存在，更新 value
        // 如果不存在，插入新节点
        for (auto& node : table[index]) {
            if (node.key == key) {
                // key 已经存在，更新 value
                node.value = value;
                return;
            }
        }

        // 链表中没有目标 key，添加新节点
        // 这里使用 addFirst 添加到链表头部或者 addLast 添加到链表尾部都可以
        // 因为 Java LinkedList 的底层实现是双链表，头尾操作都是 O(1) 的
        // https://labuladong.online/algo/data-structure-basic/linkedlist-implement/
        table[index].push_back(KVNode(key, value));
    }

    // 删
    void remove(int key) {
        auto& list = table[hash(key)];
        if (list.empty()) {
            return;
        }

        // 如果 key 存在，则删除
        // 这个 removeIf 方法是 Java LinkedList 的方法，可以删除满足条件的元素，时间复杂度 O(N)
        list.remove_if([key](KVNode& node) { return node.key == key; });
    }
};

int main() {
    ExampleChainingHashMap map(10);
    map.put(1, 1);
    map.put(2, 2);
    map.put(3, 3);
    map.put(4, 4);
    map.put(5, 5);

    std::cout << map.get(1) << std::endl;
    std::cout << map.get(2) << std::endl;
    std::cout << map.get(3) << std::endl;
    std::cout << map.get(4) << std::endl;
    std::cout << map.get(5) << std::endl;

    map.remove(1);
    map.remove(2);
    map.remove(3);
    map.remove(4);
    map.remove(5);

    std::cout << map.get(1) << std::endl;
    std::cout << map.get(2) << std::endl;
    std::cout << map.get(3) << std::endl;
    std::cout << map.get(4) << std::endl;
    std::cout << map.get(5) << std::endl;

    return 0;
}