#include <iostream>
#include <queue>

void test_constructor();    // Constructor is used to initialize the queue
void test_assign();         // Assign is used to assign new elements to the queue

void test_front();          // Front is used to access the first element of the queue
void test_back();           // Back is used to access the last element of the queue

void test_size();           // Size is used to get the number of elements in the queue
void test_empty();          // Empty is used to check if the queue is empty or not

void test_push();           // Push is used to insert a new element into the queue
void test_emplace();        // Emplace is used to insert a new element into the queue
void test_pop();            // Pop is used to remove the first element from the queue
void test_swap();           // Swap is used to swap the contents of two queues

#define Print_queue(q) for(auto i = q; !i.empty(); i.pop()) std::cout << i.front() << " "; std::cout << std::endl;

int main(){
    //test_constructor();
    //test_assign();

    //test_front();
    //test_back();
    
    //test_size();
    //test_empty();

    test_push();
    //test_emplace();
    //test_pop();
    //test_swap();

    return 0;   
}

void test_constructor(){
    std::queue<int> q1; // Empty queue of integer
    std::queue<int> q2({1, 2, 3, 4, 5}); // Queue of integer with 5 elements
    std::queue<int> q3(q2); // Copy of q2
    
    // Move constructor
    std::queue<int> q4(std::move(q3)); // q3 is now empty
}

void test_assign(){
    std::queue<int> q1({1, 2, 3, 4, 5});
    std::queue<int> q2 = q1; // Copy of q1

    Print_queue(q1);
}

void test_front(){
// Description: front() function is used to reference the first element (ie. the oldest element) of the queue. This function can be used to fetch the first element of a queue.
// Syntax: queue.front()
// Complexity: O(1)

    std::queue<int> q1({1, 2, 3, 4, 5});
    std::cout << q1.front() << std::endl; // 1

    q1.front() = 10;
    std::cout << q1.front() << std::endl; // 10
} 

void test_back(){
// Description: back() function is used to reference the last element (ie. the newest element) of the queue. This function can be used to fetch the last element of a queue.
// Syntax: queue.back()
// Complexity: O(1)

    std::queue<int> q1({1, 2, 3, 4, 5});
    std::cout << q1.back() << std::endl; // 5

    q1.back() = 10;
    std::cout << q1.back() << std::endl; // 10
}

void test_size(){
// Description: size() function is used to get the number of elements in the queue. This function returns the number of elements in the queue.
// Syntax: queue.size()
// Complexity: O(1)

    std::queue<int> q1;
    std::cout << q1.size() << std::endl; // 0

    std::queue<int> q2({1, 2, 3, 4, 5});
    std::cout << q2.size() << std::endl; // 5
}

void test_empty(){
// Description: empty() function is used to check if the queue is empty or not. This function returns true if the queue is empty, otherwise false.
// Syntax: queue.empty()
// Complexity: O(1)

    std::queue<int> q1;
    std::cout << q1.empty() << std::endl; // 1

    std::queue<int> q2({1, 2, 3, 4, 5});
    std::cout << q2.empty() << std::endl; // 0
}

void test_push(){
// Description: push() function is used to insert a new element into the queue. This function adds a new element at the end of the queue.
// Syntax: queue.push(value)
// Complexity: O(1)

    std::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    Print_queue(q1);
}

void test_emplace(){
// Description: emplace() function is used to insert a new element into the queue. This function adds a new element at the end of the queue.
// Syntax: queue.emplace(args)
// Complexity: O(1)

    std::queue<int> q1;
    q1.emplace(1);
    q1.emplace(2);
    q1.emplace(3);
    q1.emplace(4);
    q1.emplace(5);

    Print_queue(q1);
}

void test_pop(){
// Description: pop() function is used to remove the first element from the queue. This function removes the first element from the queue.
// Syntax: queue.pop()
// Complexity: O(1)

    std::queue<int> q1({1, 2, 3, 4, 5});
    q1.pop();
    Print_queue(q1);
}

void test_swap(){
// Description: swap() function is used to swap the contents of two queues. This function swaps the contents of two queues.
// Syntax: queue1.swap(queue2)
// Complexity: O(1)

    std::queue<int> q1({1, 2, 3, 4, 5});
    std::queue<int> q2({6, 7, 8, 9, 10});
    q1.swap(q2);

    Print_queue(q1);
    Print_queue(q2);
}