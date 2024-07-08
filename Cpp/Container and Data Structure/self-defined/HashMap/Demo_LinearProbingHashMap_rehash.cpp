#include <iostream>
#include <vector>

using namespace std;

// 用线性探查法解决哈希冲突的简化实现（rehash版）
class Node {
    public:
        int key;
        int val;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
};

class ExampleLinearProbingHashMap1 {
    private:
        // 哈希表的底层数组，每个索引存储一个键值对
        vector<Node*> table;

    public:
        ExampleLinearProbingHashMap1(int cap) {
            this->table.resize(cap);
        }

        // 增/改
        void put(int key, int value) {
            int index = findKeyIndex(key);
            table[index] = new Node(key, value);
        }

        // 查，找不到就返回 -1
        int get(int key) {
            int index = findKeyIndex(key);
            return table[index] == NULL ? -1 : table[index]->val;
        }

        // 删
        void remove(int key) {
            int index = findKeyIndex(key);
            if (table[index] == NULL) {
                return;
            }
            table[index] = NULL;
            // 保持元素连续性，搬移数据（这个过程称为 rehash）
            index = (index + 1) % table.size();
            while (table[index] != NULL) {
                Node* entry = table[index];
                table[index] = NULL;
                // 这个操作是关键，利用 put 方法，将键值对重新插入
                // 这样就能把它们移动到正确的 table 索引位置
                //! 即 put 方法决定了 rehash 后数据位置，其中有些数据的位置与之前相同，有些则不同，即发生了搬移
                put(entry->key, entry->val);
                index = (index + 1) % table.size();
            }
        }

        // 线性探测法查找 key 在 table 中的索引
        // 如果找不到，返回的就是下一个为 null 的索引，可用于插入
        int findKeyIndex(int key) {
            int index = hash(key);

            while (table[index] != NULL) {
                if (table[index]->key == key) {
                    return index;
                }
                // 注意环形数组特性
                index = (index + 1) % table.size();
            }

            return index;
        }

        int hash(int key) {
            return key % table.size();
        }
};

int main() {
    ExampleLinearProbingHashMap1 map(10);
    map.put(1, 1);
    map.put(2, 2);
    map.put(10, 10);
    map.put(20, 20);
    map.put(30, 30);
    map.put(3, 3);
    cout << map.get(1) << endl;
    cout << map.get(2) << endl;
    cout << map.get(20) << endl;

    map.put(1, 100);
    cout << map.get(1) << endl;

    map.remove(20);
    cout << map.get(20) << endl;
    cout << map.get(30) << endl;

    return 0;
}