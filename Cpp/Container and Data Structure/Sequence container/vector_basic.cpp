#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
! Q1: What's the difference between insert() and emplace() ?
! A1: insert() is used to insert new elements into the vector container, the new elements are added before the element at the specified position.
!     emplace() is used to insert a new element into the vector container, the new element is added to the end of the vector.

! Q1: What's the difference between push_back(), emplace_back() ?
! A1: push_back() is used to push or add elements at the back of a vector.
!     emplace_back() is used to insert a new element into the vector container, the new element is added to the end of the vector.

*/

void test_constructor();  // Constructors are used to initialize the vector object with values that can be accessed by using iterators.
void test_assign();       // assign() is used to assign new values to the vector elements by replacing old ones. It can also be used to empty the container.
void test_get_allocator();//! get_allocator() is used to return the copy of the allocator object associated with the vector.

void test_at();           // at() is used to return the reference to the element present at the position given as the parameter to the function.
void test_back();         // back() is used to return the reference to the last element of the vector container.
void test_front();        // front() is used to return the reference to the first element of the vector.
void test_begin_end();    // begin() is used to return an iterator pointing to the first element of the vector.
                          // end() is used to return an iterator pointing to the theoretical element that follows the last element in the vector.
void test_rbegin_end();   // rbegin() returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
                          // rend() returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
void test_cbegin_end();   // cbegin() returns a constant iterator pointing to the first element of the vector.
                          // cend() returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
void test_crbegin_end();  // crbegin() returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
                          // crend() returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).


void test_capacity();     // capacity() is used to return the size of the storage space currently allocated to the vector expressed as number of elements.
void test_empty();        // empty() is used to check if the vector container is empty or not.
void test_max_size();     // max_size() is used to return the maximum number of elements that can be present in a vector container.
void test_reserve();      // reserve() is used to request that the vector capacity be at least enough to contain n elements.
void test_shrink_to_fit();// shrink_to_fit() is used to reduce the capacity of the container to fit its size and destroys all elements beyond the capacity.
void test_size();         // size() is used to return the number of elements present in the vector.

void test_clear();        // clear() is used to remove all the elements of the vector container, thus making it size 0.
void test_emplace();      // emplace() is used to insert a new element into the vector container, the new element is added to the end of the vector.
void test_emplace_back(); // emplace_back() is used to insert a new element into the vector container, the new element is added to the end of the vector.
void test_erase();        // erase() is used to remove elements from a container from the specified position or range.
void test_insert();       // insert() is used to insert new elements into the vector container, the new elements are added before the element at the specified position.
void test_pop_back();     // pop_back() is used to pop or remove elements from a vector from the back.
void test_push_back();    // push_back() is used to push or add elements at the back of a vector.
void test_resize();       // resize() is used to resize a vector to a specified number of elements.
void test_swap();         // swap() is used to swap the contents of one vector with another vector of same type. Sizes may differ.

void test_sort();         // sort() is used to sort the elements of a vector in ascending order.

#define print_vector(v) \
    for (auto i : v) \
        std::cout << i << " "; \
        std::cout << std::endl;

int main(){
//    test_constructor();
//    test_assign();

//    test_at();
//    test_back();
//    test_front();
//    test_begin_end();
//      test_rbegin_end();
//    test_cbegin_end();
//    test_crbegin_end();

//    test_capacity();
//    test_empty();
//    test_max_size();
//    test_reserve();
//    test_shrink_to_fit();
//    test_size();

//    test_clear();
//    test_emplace();
//    test_emplace_back();
//    test_erase();
//    test_insert();
//    test_pop_back();
//    test_push_back();
//    test_resize();
    test_swap();

//    test_sort();

	return 0;
}

void test_constructor(){
    std::vector<int> emptyConstructor;														// Creates an empty vector
    std::vector<int> handConstructor{1, 2, 3, 4, 5};										// Creates a vector with 5 values
	std::vector<int> fillConstructor(5, 10);												// Fills the vector with 5 values of 10
	std::vector<int> iteratedConstructor(fillConstructor.begin(), fillConstructor.end()-2); // Fills the vector with the iterated object values from beginning to end
	std::vector<int> copiedConstructor(iteratedConstructor);								// Creates a duplicate of the iteratedConstructor vector
    
    // emptyConstructor {}
    std::cout << "emptyConstructor ";
    print_vector(emptyConstructor);

    // handConstructor {1, 2, 3, 4, 5}
    std::cout << "handConstructor ";
    print_vector(handConstructor);

    // fillConstructor {10, 10, 10, 10, 10}
    std::cout << "fillConstructor ";
    print_vector(fillConstructor);
    
    // iteratedConstructor {10, 10, 10}
    std::cout << "iteratedConstructor ";
    print_vector(iteratedConstructor);

    // copiedConstructor {10, 10, 10}
    std::cout << "iteratedConstructor ";
    print_vector(copiedConstructor);
}

void test_assign(){
//  Description:
//  - Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

//  Two variations:
//  1. Assigns the vector's contents to `n` copies of a value.
//  2. Assigns the vector to a copy of the elements in a given iterator range.

// Complexity:
//  1. Linear in the new size of the vector.
//  2. Linear in the size of the range and the new size of the vector.

    std::vector<int> example;// example is empty: { }
    // Overwrite to larger vector with 5 copies of 42
    example.assign(5, 42);
    std::cout << "example.assign(5, 42) ";
    print_vector(example);
    // example is now: { 42, 42, 42, 42, 42 }

    // From another vector, assign using the range [ third, end )
    std::vector<int> sequence = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    example.assign(sequence.begin() + 2, sequence.end());
    std::cout << "example.assign(sequence.begin() + 2, sequence.end()) ";
    print_vector(example);
    // example is now: { 3, 4, 5, 6, 7, 8, 9, 10 }

    // From the same vector, assign using the range [ first, third )
    example.assign(example.begin(), example.begin() + 2);
    std::cout << "example.assign(example.begin(), example.begin() + 2) ";
    print_vector(example);
    // example is now: { 3, 4 }

    // Overwrite to smaller vector with 3 copies of 0
    example.assign(3, 0);
    std::cout << "example.assign(3, 0) ";
    print_vector(example);
    // example is now: { 0, 0, 0 }
}

void test_get_allocator(){
//  Description:
//  - Returns a copy of the allocator object associated with the vector.
//  Complexity:
//  - Constant.
    std::vector<int> myvector;
    int * p;
        
    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);
        
    // construct values in-place on the array:
    for(int i = 0; i < 5; ++i){
        myvector.get_allocator().construct(&p[i],i);
    }
        
    print_vector(myvector);
        
    // destroy and deallocate:
    for(int i = 0; i < 5; ++i){
        myvector.get_allocator().destroy(&p[i]);
    }
    myvector.get_allocator().deallocate(p,5);
}

void test_at(){
//   Description : 
//   - Returns a reference to the element at position _n_ in the vector.
//   - If the position is not present in the vector, it throws exception of type _out_of_range_ 
//  Complexity:
//    - Constant.

    // Create a vector of 5 integers  
	std::vector<int> myVector{1, 2, 3, 4, 5};

	// Display the contents of vector using std::vector::at.
	for (int i = 0; i < 5; i++) {
        myVector.at(i) = i + 2;
	    std::cout << myVector.at(i) << " ";
	}
}

void test_back(){
//  Description:
//    - Returns a reference to the last element in the vector
//  Complexity:
//  - Constant.

    // Initialize int vector
    std::vector<int> myVector = {1, 2, 3, 4, 5}; 
    
    // Save reference to the last element
    int& lastEle = myVector.back();
  
    // Last element is 5
    std::cout << myVector.back() << " ";
    
    // Change the last element by changing the reference variable lastEle
    lastEle = 10;
  
    // Last element is 10
    std::cout << myVector.back() << " ";
}

void test_front(){
//  Description:
//  - Returns a reference to the first element in the vector.
//  Complexity:
//  - Constant.
    // Creating a vector 
    std::vector<int> example; 
  
    // Add elements to the List 
    example.push_back(10); 
    example.push_back(20); 
    example.push_back(30); 
    example.push_back(40); 
  
    // get the first element using front() 
    int & ele = example.front(); 
  
    // Print the first element 
    std::cout << ele; 
}

void test_begin_end(){
//  Description:
//    - begin() -- Returns an iterator pointing to the first element in the vector.
//    - end() -- Returns an iterator pointing to the theoretical element that follows the last element in the vector.
//  Complexity:
//    - begin() -- Constant.
//    - end() -- Constant.
    
    // Initialize int vector
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    // Iterate over myVector using iterators
	for (auto it = myVector.begin(); it != myVector.end(); it++) {
	    std::cout << *it << " ";
	}
}

void test_rbegin_end(){
// Descrption:
// - rbegin() -- Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
// - rend() -- Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
// Complexity:
// - rbegin() -- Constant.
// - rend() -- Constant.

    std::vector<int> myvector = {1,2,3,4,5};

    std::cout << "myvector backwards:";
    for (auto rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
        std::cout << ' ' << *rit;
    std::cout << '\n';

}

void test_cbegin_end(){
//  Description:
//      - cbegin() -- Returns a constant iterator pointing to the first element in the vector.
//      - cend() -- Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
//  Complexity:
//      - cbegin() -- Constant.
//      - cend() -- Constant.

//* Iterator cannot modify the contents of the vector if you use cbegin() and cend()

    //declares an empty vector
    std::vector<int> vec;
    
    //inserting elements in vector
    vec.push_back(101);
    vec.push_back(12);
    vec.push_back(999);
    vec.push_back(143);
  
    //Displaying elements of  vector from the end
    std::cout << "Content of the vector \n";
    for (auto it = vec.cend() - 1;  it >= vec.begin(); --it){ 
        std::cout << *it << '\n'; 
    }
}

void test_crbegin_end(){
// Description:
// - crbegin() -- Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
// - crend() -- Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
// Complexity:
// - crbegin() -- Constant.
// - crend() -- Constant.

    std::vector<int> myvector = {1,2,3,4,5};

    std::cout << "myvector backwards:";
    for (auto rit = myvector.crbegin(); rit != myvector.crend(); ++rit)
        std::cout << ' ' << *rit;
    std::cout << '\n';
}

void test_capacity(){
//  Description:
//  - Returns the number of elements that the vector could contain without allocating more storage.
//  Complexity:
//      - Constant.

   //Declare the vector
   std::vector<int> myvector{1,2,3,4,5};

   //when capacity is exhausted, vector automatically expands
   std::cout<<"The maximum capacity of the vector is: "<< myvector.capacity();

// Alternative demo see https://zh.cppreference.com/w/cpp/container/vector/capacity
}

void test_empty(){
// Description:
// - Returns whether the vector is empty (i.e. whether its size is 0).
// Complexity:
// - Constant.

    std::vector<int> myvector;
    int sum (0);

    for (int i=1;i<=10;i++) myvector.push_back(i);

    while (!myvector.empty())
    {
       sum += myvector.back();
       myvector.pop_back();
    }

    std::cout << "total: " << sum << '\n';
}

void test_max_size(){
//  Description:
//  - Returns the maximum number of elements that the vector can hold.
//  Complexity:
//  - Constant.

	//Create two vectors, one empty and one having 6 elements
	std::vector<int> vector1;
	std::vector<int> vector2{10, 30, 30, 40, 50, 60};
	
	//Display the maximum number of elements both can hold
	std::cout << "The maximum size of vector1 is: " << vector1.max_size() << std::endl;
	std::cout << "The maximum size of vector2 is: " << vector2.max_size() << std::endl;
}

void test_reserve(){
// Description:
// - Requests that the vector capacity be at least enough to contain n elements. / Helps specify the minimum size of a vector.
// - If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
// - In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
// - This function has no effect on the vector size and cannot alter its elements.
// - A reallocation invalidates all previously obtained iterators, references and pointers.
// Complexity:
// - Linear in the size of the container, i.e., the number of elements.

    std::vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.reserve(100);   // reserve 100 elements
    std::cout << "The vector capacity is: " << myvector.capacity() << std::endl;

    myvector.resize(5);      // resize to 5 elements
    std::cout << "The vector capacity is: " << myvector.capacity() << std::endl;

    myvector.shrink_to_fit();   // shrink to fit
    std::cout << "The vector capacity is: " << myvector.capacity() << std::endl;

}

void test_shrink_to_fit(){
// Description:
// - Requests the container to reduce its capacity to fit its size.
// - Requests the removal of unused capacity.
// - It is a non-binding request to reduce capacity() to size().
// - It depends on the implementation whether the request is fulfilled.
// - If reallocation occurs, all iterators, including the past-the-end iterator, and all references to the elements are invalidated.
// - If no reallocation takes place, no iterators or references are invalidated.
// Complexity:
// - Linear in the size of the container, i.e., the number of elements.

    //create a vector of 5 elements
    std::vector<int> myvec{10, 20, 30, 40, 50};

    //adding a sixth element, vector's capacity will increase for future insertions
    myvec.push_back(60);

    //output the inital capacity
    std::cout << "Initial capacity is: " << myvec.capacity() << std::endl;

    //output the shrunk capacity
    myvec.shrink_to_fit();

    std::cout << "Shrunk capacity is: " << myvec.capacity();
}

void test_size(){
// Description:
// - Returns the number of elements in the vector.
// Complexity:
// - Constant.

    // Creating a vector
    std::vector<int> example;

    // Adding elements to the vector
    example.push_back(10); 
    example.push_back(20); 
    example.push_back(30); 
    example.push_back(40); 
  
    // getting size of the list 
    int size = example.size(); 
  
    std::cout << "The vector contains " << size << " elements"; 
}

void test_clear(){
//  Description:
//    - Removes all elements from the vector (which are destroyed), leaving the container with a size of 0
//  Complexity:
//    - Linear in the size of the container, i.e., the number of elements.

    std::vector<int> myVector;
    
    // Initialize vector with the values {1,2,3,4,5}
    myVector = {1,2,3,4,5};
    
    // Output: "1 2 3 4 5"
    for (int i : myVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Size of vector is 5
    std::cout << "Vector size: " << myVector.size() << std::endl;
    
    // Clear the vector of all values, myVector now contains no values
    myVector.clear(); 
    
    // Output is blank
    for (int i : myVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Size of vector is 0
    std::cout << "Vector size: " << myVector.size() << std::endl;

//  Alternative demo see https://zh.cppreference.com/w/cpp/container/vector/clear
}

void test_emplace(){
//  Description:
//  - Places an element in the vector at the specified position
// Complexity:
//  - Constant.

    //creating a vector of 5 elements
    std::vector<int> vector1{10, 20, 30, 40, 50};

    //function to add an element at the beginning and the end
    vector1.emplace(vector1.begin(), -10);
    print_vector(vector1);

    vector1.emplace(vector1.end(), 60);
    print_vector(vector1);

    vector1.emplace(vector1.begin() + 2, 15);
    print_vector(vector1);
}

void test_emplace_back(){
// Description:
// - Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in place using args as the arguments for its construction.
// Complexity:
// - Constant.
// Alternative demo see https://zh.cppreference.com/w/cpp/container/vector/emplace_back

    std::vector<std::string> myvector = {"Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};

    myvector.emplace_back("Earth");
    myvector.emplace_back("Venus");

    std::cout << "myvector contains:";
    for (std::string& x : myvector)
        std::cout << ' ' << x;
    std::cout << '\n';
}

void test_erase(){
//  Description:
//  - Removes from the vector either a single element (position) or a range of elements ([first,last)).
//  Complexity:
//  - Linear in the distance between first and last: Compares the number of elements affected (distance) to the total container size (linear).

    std::vector<int> vector1;

    vector1 = {1,2,3,4,5,6,7,8,9};

    // Remove 1st Element
    vector1.erase(vector1.begin());
    print_vector(vector1);

    // Remove range of elements
    vector1.erase(vector1.begin()+2,vector1.begin()+5);
    print_vector(vector1);

    // Bonus Example
    // Remove element with value 'valueToRemove' from vector 'vector1'
    // Using 'algorithm' C++ STL library to remove a specific value
//    int valueToRemove = 7;
//    std::vector<int> vector2 = { 5,6,1,7,12,3,7,9,7,2};
//    vector2.erase( std::remove(vector2.begin(),vector2.end(),valueToRemove),vector2.end());
}

void test_insert(){
// Description:
// - The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
// - This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
// Complexity:
// - Linear in the number of elements inserted plus the distance to the end of the vector.

    // initialising the vector 
	std::vector<int> vec = { 10, 20, 30, 40 }; 

	// inserts 5 at front 
	auto it = vec.insert(vec.begin(), 5);  

	std::cout << "The vector elements are: "; 
	for (auto it = vec.begin(); it != vec.end(); ++it) 
		std::cout << *it << " "; 
	std::cout << std::endl;
}

void test_pop_back(){
// Description:
// - Removes the last element in the vector, effectively reducing the container size by one.
// Complexity:
// - Constant.

    std::vector<int> myvector;
    int sum (0);
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
    while (!myvector.empty())
    {
       sum += myvector.back();
       myvector.pop_back();
    }
    std::cout << "The elements of myvector add up to " << sum << '\n';
}

void test_push_back(){
// Description:
// - Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
// - This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
// Complexity:
// - Constant.

    std::vector<int> myvector;
    for (int i = 1; i <= 5; i++)
        myvector.push_back(i);
    std::cout << "myvector stores " << myvector.size() << " numbers.\n";
}

void test_resize(){
// Description:
// - Resizes the container so that it contains n elements.
// - If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
// - If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
// - The new elements are initialized as 0.
// - If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
// - Notice that this function changes the actual content of the container by inserting or erasing elements from it.
// - In case of reallocation, the iterators (see begin() and end() for more details) and references to elements of the container are invalidated.
// - If the reallocation happens and if the inserted elements are not all at the end of the container, the iterator to pos must be updated to point to the same element in the container after the reallocation.
// Complexity:
// - Linear in the difference between the current size and count.

    // Initialize empty vector
    std::vector<int> myVector; 
    
    // Resize the vector to contain 5 elements with default value, 0
    myVector.resize(5);
    
    // Resize the vector to contain 10 elements, sets additional elements value to 1
    myVector.resize(10,1);

    // Outputs the resized vector with size of 10 elements
    for (int it : myVector){
        std::cout << it << " ";
    }
    
    // Resize the vector to contain 5 elements
    myVector.resize(5);
    
    std::cout << std::endl;
    // Outputs the resized vector with size of 5 elements
    for (int it : myVector){
        std::cout << it << " ";
    }   
}

void test_swap(){
// Description:
// - Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
// - After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this.
// - All iterators, references and pointers remain valid for the swapped objects.
// Complexity:
// - Constant.

    //Intializing the vectors  
    std::vector<int> vector1 = {1,2,3};
    std::vector<int> vector2 = {4,5,6,6};

    std::cout << "The first vector before swapping is: ";
    print_vector(vector1);
    std::cout << "The second vector before swapping is: ";
    print_vector(vector2);

    //Function to swap the vectors
    vector1.swap(vector2);

    std::cout << "The first vector after swapping is: ";
    print_vector(vector1);
}

void test_sort(){
// Description:
// - Sorts the elements in the vector, altering their position within the container.
// - The sorting is performed by applying an algorithm that uses either operator< (in version (1)) or comp (in version (2)) to compare elements.
// - This comparison shall produce a strict weak ordering of the elements (i.e., a consistent transitive comparison, without considering its reflexiveness).
// - The resulting order of equivalent elements is stable: i.e., equivalent elements preserve the relative order they had before the call.
// - The first version (1) uses operator< to compare the elements, the second version (2) uses the given comparison function comp.
// - The third version (3) uses the given comparison object comp.
// - The fourth version (4) uses the given comparison object comp.
// Complexity:
// - Approximately NlogN comparisons on average, where N is the size of the container.

    //Declare the vector  
    std::vector<int> v {-1,0,4,-5,12,2,10,-11,3,5};
    print_vector(v);

    //Function to sort values in increasing order in the vector
    std::sort(v.begin(), v.end());
    print_vector(v);
    
    //Function to sort values in decreasing order in the vector
    std::sort(v.begin(), v.end(), std::greater<int>()); 
    print_vector(v);
}