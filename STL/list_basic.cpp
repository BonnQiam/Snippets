#include <iostream>
#include <list>

void test_assign();     // The list::assign() is a built-in function in C++ STL which is used to assign values to a list.

void test_back();       // The list::back() is a built-in function in C++ STL which is used to return a reference to the last element of the list container.

void test_begin_end();  // The list::begin() is a built-in function in C++ STL which is used to return an iterator pointing to the first element of the list container.
                        // The list::end() is a built-in function in C++ STL which is used to return an iterator pointing to the theoretical last element which follows the last element.
void test_cbegin_end(); // The list::cbegin() is a built-in function in C++ STL which is used to return a constant iterator pointing to the first element of the list container.
                        // The list::cend() is a built-in function in C++ STL which is used to return a constant iterator pointing to the theoretical last element which follows the last element.


void test_clear();      // The list::clear() is a built-in function in C++ STL which is used to remove all the elements of the list container, thus making it size 0.

#define print_list(l) for (auto i : l) std::cout << i << " "; std::cout << std::endl;

int main()
{
//    test_assign();

//    test_back();

//    test_begin_end();
//    test_cbegin_end();

    test_clear();

    return 0;
}

void test_assign(){
// Description
// - The list::assign() is a built-in function in C++ STL which is used to assign values to a list.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts two parameters which are specified below:
// - val: This parameter specifies the value to be assigned to the list.
// - n: This parameter specifies the number of elements to be inserted.

    // Initialization of list 
    std::list<int> demo_list; 
  
    // Assigning the value 100, 5 times 
    // to the list, list_demo. 
    demo_list.assign(5, 100); 
  
    // Displaying the list 
    for (int itr : demo_list) { 
        std::cout << itr << " "; 
    } 
}

void test_back(){
// Description
// - The list::back() is a built-in function in C++ STL which is used to return a reference to the last element of the list container.
// Complexity
// - Constant.
// Parameters
// - The function does not accept any parameters.
// Return Value
// - The function returns a reference to the last element of the list container.
    std::list<int> l = {1, 2, 3, 4, 5};
    print_list(l);
    std::cout << l.back() << std::endl;
}

void test_begin_end(){
// Description
// - The list::begin() is a built-in function in C++ STL which is used to return an iterator pointing to the first element of the list container.
// Complexity
// - Constant.
    // declaration of list container 
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    // using begin() to print list 
    for (auto it = mylist.begin(); it != mylist.end(); ++it) 
        std::cout << ' ' << *it; 
}

void test_cbegin_end(){
// Descriptin
// - The list::cbegin() is a built-in function in C++ STL which is used to return a constant iterator pointing to the first element of the list container.
// Complexity
// - Constant.
    // declaration of list 
    std::list<int> lis = { 15, 26, 37, 48, 59 }; 
  
    // Prints the first element 
    std::cout << "The first element is: " << *lis.cbegin(); 
  
    // printing list elements 
    std::cout << "\nList: "; 
  
    for (auto it = lis.cbegin(); it != lis.end(); ++it) 
        std::cout << *it << " "; 
}

void test_clear(){
// Description
// - The list::clear() is a built-in function in C++ STL which is used to remove all the elements of the list container, thus making it size 0.
// Complexity
// - Linear in the size of the list.

    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    mylist.clear(); 
    // List becomes empty 
  
    print_list(mylist);
}