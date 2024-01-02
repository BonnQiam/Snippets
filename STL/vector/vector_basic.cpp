#include <iostream>
#include <vector>
#include <string>

void test_constructor();  // Constructors are used to initialize the vector object with values that can be accessed by using iterators.
void test_assign();       // assign() is used to assign new values to the vector elements by replacing old ones. It can also be used to empty the container.
void test_at();           // at() is used to return the reference to the element present at the position given as the parameter to the function.
void test_back();         // back() is used to return the reference to the last element of the vector container.

#define print_vector(v) \
    for (auto i : v) \
        std::cout << i << " "; \
        std::cout << std::endl;

int main(void)
{
//    test_constructor();
//    test_assign();
//    test_at();
    test_back();

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