#include <iostream>
#include <list>

void test_assign();         // The list::assign() is a built-in function in C++ STL which is used to assign values to a list.

void test_back();           // The list::back() is a built-in function in C++ STL which is used to return a reference to the last element of the list container.
void test_front();          // The list::front() is a built-in function in C++ STL which is used to return a reference to the first element of the list container.

void test_begin_end();      // The list::begin() is a built-in function in C++ STL which is used to return an iterator pointing to the first element of the list container.
                            // The list::end() is a built-in function in C++ STL which is used to return an iterator pointing to the theoretical last element which follows the last element.
void test_cbegin_end();     // The list::cbegin() is a built-in function in C++ STL which is used to return a constant iterator pointing to the first element of the list container.
                            // The list::cend() is a built-in function in C++ STL which is used to return a constant iterator pointing to the theoretical last element which follows the last element.
void test_rbegin_end();     // The list::rbegin() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the last element of the list.
                            // The list::rend() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the theoretical element preceding the first element.
void test_crbegin_end();    // The list::crbegin() is a built-in function in C++ STL which is used to return a constant reverse iterator which points to the last element of the list.
                            // The list::crend() is a built-in function in C++ STL which is used to return a constant reverse iterator which points to the position before the beginning of the list.

void test_empty();          // The list::empty() is a built-in function in C++ STL which is used to check whether the list container is empty or not.
void test_max_size();       // The list::max_size() is a built-in function in C++ STL which is used to find the maximum number of elements that can be stored in the list container.

void test_clear();          // The list::clear() is a built-in function in C++ STL which is used to remove all the elements of the list container, thus making it size 0.
void test_emplace();        // The list::emplace() is a built-in function in C++ STL which is used to insert a new element into the list container, the new element is added before the element at the specified position.
void test_emplace_back();   // The list::emplace_back() is a built-in function in C++ STL which is used to insert a new element into the list container, the new element is added at the end of the list.
void test_earse();          // The list::erase() is a built-in function in C++ STL which is used to remove elements from a list container.
void test_insert();         // The list::insert() is a built-in function in C++ STL which is used to insert new elements in the list container before the element at a specified position.
void test_pop_back();       // The list::pop_back() is a built-in function in C++ STL which is used to pop or remove elements from a list from the back.
void test_pop_front();      // The list::pop_front() is a built-in function in C++ STL which is used to pop or remove elements from a list from the front.
void test_push_back();      // The list::push_back() is a built-in function in C++ STL which is used to insert elements into a list from the back.
void test_push_front();     // The list::push_front() is a built-in function in C++ STL which is used to insert elements into a list from the front.

void test_merge();          // The list::merge() is a built-in function in C++ STL which is used to merge two sorted lists into one.
void test_remove();         // The list::remove() is a built-in function in C++ STL which is used to remove all the elements from the list container, which are equal to given element.

#define print_list(l) for (auto i : l) std::cout << i << " "; std::cout << std::endl;

int main()
{
//    test_assign();

//    test_back();
//    test_front();

//    test_begin_end();
//    test_cbegin_end();
//    test_rbegin_end();
//    test_crbegin_end();

//    test_empty();
//    test_max_size();

//    test_clear();
//    test_emplace();
//    test_emplace_back();
//    test_earse();
//    test_pop_back();
//    test_pop_front();
//    test_push_back();
//    test_push_front();

//    test_merge();
    test_remove();

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

void test_front(){
// Description
// - The list::front() is a built-in function in C++ STL which is used to return a reference to the first element of the list container.
// Complexity
// - Constant.
// Parameters
// - The function does not accept any parameters.

    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
  
    // get the first element using front() 
    int ele = demoList.front(); 
  
    // Print the first element 
    std::cout << ele; 
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

void test_rbegin_end(){
// Description
// - The list::rbegin() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the last element of the list.
// Complexity
// - Constant.
    // declaration of list container 
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    // using rbegin() to print list 
    for (auto it = mylist.rbegin(); it != mylist.rend(); ++it) 
        std::cout << ' ' << *it; 
}

void test_crbegin_end(){
// Desription
// - The list::crbegin() is a built-in function in C++ STL which is used to return a constant reverse iterator which points to the last element of the list.
// Complexity
// - Constant.
    // declaration of the list 
    std::list<int> lis = { 109, 207, 305, 403, 501 }; 
  
    // prints the last element 
    std::cout << "The last element is: " << *lis.crbegin(); 
    std::cout << "\nList: "; 
  
    for (auto it = lis.crbegin(); it != lis.crend(); ++it) 
        std::cout << *it << " "; 
}

void test_empty(){
// Description
// - The list::empty() is a built-in function in C++ STL which is used to check whether the list container is empty or not.
// Complexity
// - Constant.
    std::list<int> mylist1{ 1, 2, 3, 4, 5 }; 
    std::list<int> mylist2; 
  
    //! analyze following code 
    mylist1.empty()? 
        std::cout << "True\n" : 
        std::cout << "False\n"; 
  
    mylist2.empty()? 
        std::cout << "True\n" : 
        std::cout << "False\n";
}

void test_max_size(){
// Description
// - The list::max_size() is a built-in function in C++ STL which is used to find the maximum number of elements that can be stored in the list container.
// Complexity
// - Constant.
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    std::cout << mylist.max_size() << std::endl; 
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

void test_emplace(){
// Description
// - The list::emplace() is a built-in function in C++ STL which is used to insert a new element into the list container, the new element is added before the element at the specified position.
// - This function is used to extend list by inserting new element at a given position.
// Complexity
// - Constant.

    // declaration of list 
    std::list< std::pair<int,char> > mylist;
    
    // using emplace() function to
    // insert new element at the
    // beginning of the list
    mylist.emplace ( mylist.begin(), 100, 'x' );
    mylist.emplace ( mylist.begin(), 200, 'y' );
    mylist.emplace ( mylist.end(), 200, 'y' );
    
    // printing the list
    // after inserting the value
    // at the beginning
    std::cout << "mylist contains:";
    for (auto& x: mylist)
       std::cout << " (" << x.first << "," << x.second << ")";

    std::cout << '\n';
}

void test_emplace_back(){
// Description
// - The list::emplace_back() is a built-in function in C++ STL which is used to insert a new element into the list container, the new element is added at the end of the list.
// Complexity
// - Constant.
    std::list<int> mylist;

    mylist.emplace_back(1);
    mylist.emplace_back(2);
    mylist.emplace_back(3);

    std::cout << "mylist contains: ";
    for (auto& x: mylist)
        std::cout << x << " ";
}

void test_earse(){
// Description
// - The list::erase() is a built-in function in C++ STL which is used to remove elements from a list container.
// - The list::erase() is a built-in function in C++ STL which is used to delete elements from a list container. This function can be used to remove a single element or a range of elements from the specified list container.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts two parameters which are specified below:
// - position: This parameter specifies the position of the element to be removed.
    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
    demoList.push_back(50); 
  
    // Printing elements of list before deleting 
    // first element 
    std::cout << "List before deleting first element: " << std::endl; 
    for (auto value : demoList) {
        std::cout << ' ' << value << std::endl;  
    }
  
    // Creating iterator to point to first 
    // element in the list 
    std::list<int>::iterator itr = demoList.begin(); 
  
    // deleting the first element 
    demoList.erase(itr); 
  
    // Printing elements of list after deleting 
    print_list(demoList);
}

void test_insert(){
// Description
// - The list::insert() is a built-in function in C++ STL which is used to insert new elements in the list container before the element at a specified position.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts two parameters which are specified below:
// - position: This parameter specifies the position where the element is to be inserted.
// - val: This parameter specifies the value to be inserted.
    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
    demoList.push_back(50); 
  
    // declaring list 
    std::list<int> list1; 
  
    // using assign() to insert multiple numbers 
    // creates 3 occurrences of "2" 
    list1.assign(3, 2); 
  
    // initializing list iterator to beginning 
    std::list<int>::iterator it = list1.begin(); 
  
    // iterator to point to 3rd position 
    advance(it, 2); 
  
    // using insert to insert 1 element at the 3rd position 
    // inserts 5 at 3rd position 
    list1.insert(it, 5); 
  
    // Printing the new list 
    print_list(list1);
}

void test_pop_back(){
// Description
// - The list::pop_back() is a built-in function in C++ STL which is used to pop or remove elements from a list from the back.
// Complexity
// - Constant.
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    mylist.pop_back(); 
  
    print_list(mylist);
}

void test_pop_front(){
// Description
// - The list::pop_front() is a built-in function in C++ STL which is used to pop or remove elements from a list from the front.
// Complexity
// - Constant.
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    mylist.pop_front(); 
  
    print_list(mylist);
}

void test_push_back(){
// Description
// - The list::push_back() is a built-in function in C++ STL which is used to insert elements into a list from the back.
// Complexity
// - Constant.
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    mylist.push_back(6); 
  
    print_list(mylist);
}

void test_push_front(){
// Description
// - The list::push_front() is a built-in function in C++ STL which is used to insert elements into a list from the front.
// Complexity
// - Constant.
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    mylist.push_front(0); 
  
    print_list(mylist);
}

void test_merge(){
// Description
// - The list::merge() is a built-in function in C++ STL which is used to merge two sorted lists into one.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts two parameters which are specified below:
// - list: This parameter specifies the list to be merged with.
       // declaring the lists 
    // initially sorted 
    std::list<int> list1 = { 10, 20, 30 }; 
    std::list<int> list2 = { 40, 50, 60 }; 
  
    // merge operation 
    list2.merge(list1); 
  
    std::cout << "List:  "; 
    print_list(list2);
}

void tet_remove(){
// Description
// - The list::remove() is a built-in function in C++ STL which is used to remove all the elements from the list container, which are equal to given element.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts one parameter which is specified below:
// - val: This parameter specifies the value to be removed.
    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
  
    // List before removing elements 
    std::cout << "List before removing elements: "; 
    for (auto value : demoList) {
        std::cout << value << " "; 
    }
  
    // delete all elements with value 20 
    demoList.remove(20); 

    // List after removing elements 
    std::cout << "\nList after removing elements: "; 
    for (auto value : demoList) {
        std::cout << value << " "; 
    }
}