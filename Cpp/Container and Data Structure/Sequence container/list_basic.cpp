#include <iostream>
#include <list>
#include <vector>

void test_list_construct(); // Construct a list

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
void test_size();           // The list::size() is a built-in function in C++ STL which is used to return the number of elements in the list container.

void test_clear();          // The list::clear() is a built-in function in C++ STL which is used to remove all the elements of the list container, thus making it size 0.
void test_emplace();        // The list::emplace() is a built-in function in C++ STL which is used to insert a new element into the list container, the new element is added before the element at the specified position.
void test_emplace_back();   // The list::emplace_back() is a built-in function in C++ STL which is used to insert a new element into the list container, the new element is added at the end of the list.
void test_earse();          // The list::erase() is a built-in function in C++ STL which is used to remove elements from a list container.
void test_insert();         // The list::insert() is a built-in function in C++ STL which is used to insert new elements in the list container before the element at a specified position.
void test_pop_back();       // The list::pop_back() is a built-in function in C++ STL which is used to pop or remove elements from a list from the back.
void test_pop_front();      // The list::pop_front() is a built-in function in C++ STL which is used to pop or remove elements from a list from the front.
void test_push_back();      // The list::push_back() is a built-in function in C++ STL which is used to insert elements into a list from the back.
void test_push_front();     // The list::push_front() is a built-in function in C++ STL which is used to insert elements into a list from the front.
void test_resize();         // The list::resize() is a built-in function in C++ STL which is used to resize a list container.

void test_merge();          // The list::merge() is a built-in function in C++ STL which is used to merge two sorted lists into one.
void test_remove();         // The list::remove() is a built-in function in C++ STL which is used to remove all the elements from the list container, which are equal to given element.
void test_reverse();        // The list::reverse() is a built-in function in C++ STL which is used to reverse a list container.
void test_sort();           // The list::sort() is a built-in function in C++ STL which is used to sort a list container.
void test_slice();          // The list::slice() is a built-in function in C++ STL which is used to slice a list container.
void test_unique();         // The list::unique() is a built-in function in C++ STL which is used to remove all duplicate consecutive elements from the list.

void test_swap();           // The list::swap() is a built-in function in C++ STL which is used to swap the contents of one list with another list of same type and size.

#define print_list(l) for (auto i : l) std::cout << i << " "; std::cout << std::endl;

int main()
{
    test_list_construct();

//    test_assign();

//    test_back();
//    test_front();

//    test_begin_end();
//    test_cbegin_end();
//    test_rbegin_end();
//    test_crbegin_end();

//    test_empty();
//    test_max_size();
//    test_size();

//    test_clear();
//    test_emplace();
//    test_emplace_back();
//    test_earse();
//    test_pop_back();
//    test_pop_front();
//    test_push_back();
//    test_push_front();
//    test_resize();

//    test_merge();
//    test_remove();
//    test_reverse();
//    test_sort();
//    test_slice();
//    test_unique();

//    test_swap();

    return 0;
}

void test_list_construct(){
// Description
// - The list::list() is a built-in function in C++ STL which is used to create a list container.
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
    demoList.push_back(50); 
  
    // Displaying the list 
    for (int itr : demoList) { 
        std::cout << itr << " "; 
    } 

    // Creating a list, using vector iterator
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> l(vec.begin(), vec.end());
    print_list(l);

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

void test_size(){
// Description
// - The list::size() is a built-in function in C++ STL which is used to return the number of elements in the list container.
// Complexity
// - Constant.
    std::list<int> mylist{ 1, 2, 3, 4, 5 }; 
  
    std::cout << mylist.size() << std::endl; 
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

void test_resize(){
// Description
// - The list::resize() is a built-in function in C++ STL which is used to resize a list container.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts two parameters which are specified below:
// - n: This parameter specifies the new size of the list.
// - val: This parameter specifies the value to be assigned to the list.
    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
    demoList.push_back(50); 
  
    // Printing elements of list before resizing 
    std::cout << "List before resizing: " << std::endl; 
    print_list(demoList);
  
    // Resizing list size to 8 
    demoList.resize(8); 
  
    // Printing elements of list after resizing 
    std::cout << "List after 1st resizing: " << std::endl; 
    print_list(demoList);

    // Resizing list size to 8 
    demoList.resize(2); 
  
    // Printing elements of list after resizing 
    std::cout << "List after 2nd resizing: " << std::endl; 
    print_list(demoList);

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

void test_remove(){
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

void test_reverse(){
// Description
// - The list::reverse() is a built-in function in C++ STL which is used to reverse a list container.
// Complexity
// - Linear in the size of the list.
    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
    demoList.push_back(50); 
  
    // List before reversing 
    std::cout << "List before reversing: "; 
    print_list(demoList);

    // Reversing the List 
    demoList.reverse(); 
  
    // List after reversing 
    std::cout << "\nList after reversing: "; 
    print_list(demoList);
}

void test_sort(){
// Description
// - The list::sort() is a built-in function in C++ STL which is used to sort a list container.
// Complexity
// - Linear in the size of the list.
    // Creating a list 
    std::list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(50); 
    demoList.push_back(30); 
    demoList.push_back(20); 
    demoList.push_back(40); 
  
    // List before sorting 
    std::cout << "List before sorting: "; 
    print_list(demoList);

    // Sorting the List 
    demoList.sort(); 
  
    // List after sorting 
    std::cout << "\nList after sorting: "; 
    print_list(demoList);
}

void test_slice(){
// Description
// - The list::slice() is a built-in function in C++ STL which is used to slice a list container.
// Complexity
// - Linear in the size of the list.
// Parameters
// - The function accepts two parameters which are specified below:
// - start_pos: This parameter specifies the starting position of the slice.
// - end_pos: This parameter specifies the ending position of the slice.
    // initializing lists 
    std::list<int> l1 = { 1, 2, 3 }; 
    std::list<int> l2 = { 4, 5 }; 
    std::list<int> l3 = { 6, 7, 8 }; 
  
    // transfer all the elements of l2 
    l1.splice(l1.begin(), l2); 
  
    // at the beginning of l1 
    std::cout << "list l1 after splice operation" << " "; 
    print_list(l1);
  
    // transfer all the elements of l1 
    l3.splice(l3.begin(), l1); 
  
    // at the end of l3 
    std::cout << "\nlist l3 after splice operation" << " "; 
    print_list(l3);
}

void test_unique(){
// Description
// - The list::unique() is a built-in function in C++ STL which is used to remove all duplicate consecutive elements from the list.
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
    demoList.push_back(10);
    demoList.push_back(40); 
  
    // List before removing elements 
    std::cout << "List before removing elements: "; 
    print_list(demoList);
  
    // delete all elements with value 20 
    demoList.unique(); 

    // List after removing elements 
    std::cout << "\nList after removing elements: "; 
    print_list(demoList);
}


void test_swap(){
// Description
// - The list::swap() is a built-in function in C++ STL which is used to swap the contents of one list with another list of same type and size.
// Complexity
// - Constant.
      // list container declaration 
    std::list<int> mylist1{ 1, 2, 3, 4 }; 
    std::list<int> mylist2{ 3, 5, 7, 9 }; 
  
    // using swap() function to  
    //swap elements of lists 
    mylist1.swap(mylist2); 
  
    // printing the first list 
    std::cout << "mylist1 = "; 
    print_list(mylist1);
  
    // printing the second list 
    std::cout << std::endl << "mylist2 = "; 
    print_list(mylist2);
}