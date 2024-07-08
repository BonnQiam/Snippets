#include <iostream>
#include <stdexcept>
#include <vector>

template <typename E>
class MyArrayList {
private:
    E* data;
    int size;
    static const int INIT_CAP = 1;

    void resize(int newCap) {
        E* temp = new E[newCap];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    bool isElementIndex(int index) const {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) const {
        return index >= 0 && index <= size;
    }

    void checkElementIndex(int index) const {
        if (!isElementIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    void checkPositionIndex(int index) const {
        if (!isPositionIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

public:
    MyArrayList() : MyArrayList(INIT_CAP) {}

    MyArrayList(int initCapacity) {
        data = new E[initCapacity];
        size = 0;
    }

    ~MyArrayList() {
        delete[] data;
    }

    void addLast(const E& e) {
        int cap = capacity();
        if (size == cap) {
            resize(2 * cap);
        }
        data[size++] = e;
    }// complexity: O(1) amortized

    void add(int index, const E& e) {
        checkPositionIndex(index);
        int cap = capacity();
        if (size == cap) {
            resize(2 * cap);
        }
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }// complexity: O(n)

    void addFirst(const E& e) {
        add(0, e);
    }// complexity: O(n)

    E removeLast() {
        if (size == 0) {
            throw std::out_of_range("No such element");
        }
        int cap = capacity();
        if (size == cap / 4) {
            resize(cap / 2);
        }
        E deletedVal = data[--size];
        data[size] = E(); // Clear the last element to avoid memory leak
        // E() is used to initialize the last element to avoid memory leak, means the destructor of the last element will be called
        //! if don't clear the last element, the destructor will be called for the last element, which may cause memory leak
        return deletedVal;
    }// complexity: O(1) amortized

    E remove(int index) {
        checkElementIndex(index);
        int cap = capacity();
        if (size == cap / 4) {
            resize(cap / 2);
        }
        E deletedVal = data[index];
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        data[--size] = E(); // Clear the last element to avoid memory leak
        return deletedVal;
    }// complexity: O(n)

    E removeFirst() {
        return remove(0);
    }// complexity: O(n)

    E get(int index) const {
        checkElementIndex(index);
        return data[index];
    }// complexity: O(1)

    E set(int index, const E& element) {
        checkElementIndex(index);
        E oldVal = data[index];
        data[index] = element;
        return oldVal;
    }// complexity: O(1)

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int capacity() const {
        return size == 0 ? INIT_CAP : 2 * size;
    }

    void display() const {
        std::cout << "size = " << size << " cap = " << capacity() << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

#if 0
int main() {
    MyArrayList<int> arr(3);

    for (int i = 1; i <= 5; i++) {
        arr.addLast(i);
    }

    arr.remove(3);
    arr.add(1, 9);
    arr.addFirst(100);
    int val = arr.removeLast();

    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.get(i) << std::endl;
    }

    return 0;
}
#endif