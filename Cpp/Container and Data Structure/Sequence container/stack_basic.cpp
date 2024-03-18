#include <iostream>
#include <stack>

void test_constructor(); // Constructors are used to initialize the object.
void test_assign(); // Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.

void test_top(); // Returns a reference to the top element in the stack

void test_empty(); // Returns whether the stack is empty: i.e. whether its size is zero.
void test_size(); // Returns the number of elements in the stack.

void test_push(); // Inserts a new element at the top of the stack, above its current top element.
void test_emplace(); // Construct and insert element
void test_pop(); // Removes the element on top of the stack, effectively reducing its size by one.
void test_swap(); // Exchanges the contents of the container adaptor with those of other. Does not invoke any move, copy, or swap operations on individual elements.

#define print_stack(s) \
  while (!s.empty()) { \
    std::cout << s.top() << " "; \
    s.pop(); \
  }

int main() {
//    test_constructor();
//    test_assign();

//    test_top();

//    test_empty();
//    test_size();

//    test_push();
//    test_emplace();
//    test_pop();
    test_swap();

    return 0;
}

void test_constructor(){
    std::stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }

    print_stack(s);

    std::stack<int> s2(s); // copy constructor
    print_stack(s2);

    std::stack<int> s3(std::move(s)); // move constructor
    print_stack(s3);
}

void test_assign(){
    std::stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }

    std::stack<int> s2 = s; // copy constructor
    print_stack(s2);
}

void test_top(){
// Description: Returns a reference to the top element in the stack
// Syntax: stack_name.top()
// Complexity: Constant

    // Empty stack 
    std::stack<int> my_stack; 
    //pushing elements using push()
    my_stack.push(0); 
    my_stack.push(1); 
    my_stack.push(2); 
    
    print_stack(my_stack);

    while (!my_stack.empty()) { 
        //deleting elements using pop()
        std::cout << ' ' << my_stack.top(); 
        my_stack.pop(); 
    } 
}

void test_empty(){
// Description: Returns whether the stack is empty: i.e. whether its size is zero.
// Syntax: stack_name.empty()
// Complexity: Constant

    std::stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }

    std::cout << "s.empty() = " << s.empty() << std::endl;
}

void test_size(){
// Description: Returns the number of elements in the stack.
// Syntax: stack_name.size()
// Complexity: Constant

    std::stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }

    std::cout << "s.size() = " << s.size() << std::endl;
}

void test_push(){
// Description: Inserts a new element at the top of the stack, above its current top element.
// Syntax: stack_name.push(value)
// Complexity: Constant

    std::stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i);
        std::cout << "s.size() = " << s.size() << std::endl;
    }
}

void test_emplace(){
// Description: Construct and insert element
// - The emplace() member inserts an element at the top of the stack and constructs the element in place from the arguments provided. This can be more efficient than push in certain situations and avoid temporaries. emplace() effectively forwards its arguments to a constructor that is placed at the top of the stack.
// Syntax: stack_name.emplace(args)
// Complexity: Constant

    std::stack<std::string> st;
    // Add some strings to the stack
    st.emplace("C++ world");
    st.emplace("Hello");
    std::cout << st.top();
    st.pop();
    std::cout << ", " << st.top() << std::endl;
}

void test_pop(){
// Description: Removes the element on top of the stack, effectively reducing its size by one.
// Syntax: stack_name.pop()
// Complexity: Constant

    std::stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }

    while (!s.empty()) {
        std::cout << "s.size() = " << s.size() << std::endl;
        s.pop();
    }
}

void test_swap(){
// Description: Exchanges the contents of the container adaptor with those of other. Does not invoke any move, copy, or swap operations on individual elements.
// - swap() function is used to swap the contents of one stack with another stack of same type and size
// Syntax: stack_name.swap(other)
// Complexity: Constant

    std::stack<int> s;
    std::stack<int> s2;

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }

    for (int i = 10; i < 20; i++) {
        s2.push(i);
    }

    std::cout << "s.size() = " << s.size() << std::endl;
    std::cout << "s2.size() = " << s2.size() << std::endl;

    s.swap(s2);

    std::cout << "s.size() = " << s.size() << std::endl;
    std::cout << "s2.size() = " << s2.size() << std::endl;
}