#include <stdexcept>
#include <iostream>

template <typename T>
class CycleArray {
private:
    T* arr;
    int start;
    int end;
    int count;
    int size;

    void resize(int newSize) {
        T* newArr = new T[newSize];
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(start + i) % size];// copy elements from start to end
        }
        delete[] arr;
        arr = newArr;
        start = 0;
        end = count;
        size = newSize;
    }

public:
    CycleArray() : CycleArray(1) {}

    CycleArray(int size) : size(size), start(0), end(0), count(0) {
        arr = new T[size];
    }

    ~CycleArray() {
        delete[] arr;
    }

    void addFirst(const T& val) {
        if (isFull()) {
            resize(size * 2);// double the size
        }
        start = (start - 1 + size) % size;// the new start is the previous position of the current start
        arr[start] = val;
        count++;
    }// complexity: O(1) amortized

    void removeFirst() {
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        arr[start] = T();
        start = (start + 1) % size;
        count--;
        if (count > 0 && count == size / 4) {
            resize(size / 2);
        }
    }// complexity: O(1) amortized

    void addLast(const T& val) {
        if (isFull()) {
            resize(size * 2);
        }
        arr[end] = val;
        end = (end + 1) % size;
        count++;
    }// complexity: O(1) amortized

    void removeLast() {
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        end = (end - 1 + size) % size;
        arr[end] = T();
        count--;
        if (count > 0 && count == size / 4) {
            resize(size / 2);
        }
    }// complexity: O(1) amortized

    T getFirst() const {
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        return arr[start];
    }// complexity: O(1)

    T getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        return arr[(end - 1 + size) % size];
    }// complexity: O(1)

    bool isFull() const {
        return count == size;
    }

    int getSize() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }
};