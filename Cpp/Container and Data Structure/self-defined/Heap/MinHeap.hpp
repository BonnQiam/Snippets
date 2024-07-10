#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional> // for std::less (default comparator)

template<typename T, typename Comparator = std::less<T>>
class Heap {
private:
    std::vector<T> heap;
    int size;
    Comparator comparator;

    // Private helper functions for index calculations
    int parent(int node) {
        return node / 2;
    }

    int left(int node) {
        return node * 2;
    }

    int right(int node) {
        return node * 2 + 1;
    }

    void swap(int i, int j) {
        T temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void swim(int k) {
        while (k > 1 && comparator(heap[parent(k)], heap[k])) {
            swap(parent(k), k);
            k = parent(k);
        }
    }

    void sink(int k) {
        while (left(k) <= size) {
            int j = left(k);
            if (j < size && comparator(heap[j + 1], heap[j])) j++;
            if (!comparator(heap[j], heap[k])) break;
            swap(k, j);
            k = j;
        }
    }

    void resize(int capacity) {
        if (capacity <= size) return;
        heap.resize(capacity);
    }

public:
    Heap(int capacity, Comparator comp = Comparator()) 
        : heap(capacity + 1), size(0), comparator(comp) {}

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void push(const T& x) {
        if (size == heap.size() - 1) {
            resize(2 * heap.size());
        }
        heap[++size] = x;
        swim(size);
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Priority queue underflow");
        }
        T res = heap[1];
        swap(1, size--);
        sink(1);
        heap[size + 1] = T(); // clear the last element
        if (size > 0 && size == (heap.size() - 1) / 4) {
            resize(heap.size() / 2);
        }
        return res;
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Priority queue underflow");
        }
        return heap[1];
    }
};

#if 0
int main() {
    Heap<int, std::less<int>> pq(3);

    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(9);

    while (!pq.isEmpty()) {
        std::cout << pq.pop() << std::endl;
    }

    return 0;
}
#endif
