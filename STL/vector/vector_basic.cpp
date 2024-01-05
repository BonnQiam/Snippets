#include <iostream>
#include <vector>
#include <string>

void test_constructor();  // Constructors are used to initialize the vector object with values that can be accessed by using iterators.
void test_assign();       // assign() is used to assign new values to the vector elements by replacing old ones. It can also be used to empty the container.
void test_get_allocator();//! get_allocator() is used to return the copy of the allocator object associated with the vector.

void test_at();           // at() is used to return the reference to the element present at the position given as the parameter to the function.
void test_back();         // back() is used to return the reference to the last element of the vector container.
void test_front();        // front() is used to return the reference to the first element of the vector.
void test_begin_and();    // begin() is used to return an iterator pointing to the first element of the vector.
                          // end() is used to return an iterator pointing to the theoretical element that follows the last element in the vector.
void test_cbegin_and();    // cbegin() returns a constant iterator pointing to the first element of the vector.
                          // cend() returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
void test_crbegin_and();  // crbegin() returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
                          // crend() returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).

void test_capacity();     // capacity() is used to return the size of the storage space currently allocated to the vector expressed as number of elements.
void test_empty();        // empty() is used to check if the vector container is empty or not.

void test_clear();        // clear() is used to remove all the elements of the vector container, thus making it size 0.
void test_emplace();      // emplace() is used to insert a new element into the vector container, the new element is added to the end of the vector.
void test_emplace_back(); // emplace_back() is used to insert a new element into the vector container, the new element is added to the end of the vector.
void test_erase();        // erase() is used to remove elements from a container from the specified position or range.
void test_insert();       // insert() is used to insert new elements into the vector container, the new elements are added before the element at the specified position.



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
//    test_begin_and();
//    test_cbegin_and();
//    test_crbegin_and();

//    test_capacity();
//    test_empty();

//    test_clear();
//    test_emplace();
//    test_emplace_back();
//    test_erase();
    test_insert();

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

void test_begin_and(){
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

void test_cbegin_and(){
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

void test_crbegin_and(){
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