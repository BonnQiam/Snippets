#include <cstddef>
#include <deque>
#include <iostream>
#include <new>

void test_assign();         // The deque::assign() is a built-in function in C++ STL which is used to assign new elements to a deque container by replacing old ones and resizing the container.

void test_at();             // The deque::at() is a built-in function in C++ STL which is used to access an element at a particular position in the deque container.
void test_front();          // The deque::front() is a built-in function in C++ STL which is used to reference the first element of the deque container.
void test_back();           // The deque::back() is a built-in function in C++ STL which is used to reference the last element of the deque container.

void test_empty();          // The deque::empty() is a built-in function in C++ STL which is used to check whether the deque container is empty or not.
void test_size();           // The deque::size() is a built-in function in C++ STL which is used to return the number of elements in the deque container.
void test_max_size();       // The deque::max_size() is a built-in function in C++ STL which is used to return the maximum number of elements that can be stored in the deque container.
void test_shrink_to_fit();  // The deque::shrink_to_fit() is a built-in function in C++ STL which is used to reduce the capacity of the container to fit its size and destroys all elements beyond the capacity. //! Wait for analyze


#define print_deque(deq) \
    for (auto i : deq)   \
        std::cout << i << " "; \
    std::cout << std::endl;

int main(){
//    test_assign();

//    test_at();
//    test_front();
//    test_back();

//    test_empty();
//    test_size();
//    test_max_size();
    test_shrink_to_fit();

    return 0;
}

void test_assign(){
// Description: 
// - The deque::assign() is a built-in function in C++ STL which is used to assign new elements to a deque container by replacing old ones and resizing the container.
// Complexity: 
// - Linear in the number of elements inserted/assigned (copy/move construction) plus linear in the number of elements in the container after the operation (destruction).
// Parameters:
//  - first, last: Input iterators to the initial and final positions in a range. The range used is [first,last), which includes all the elements between first and last, including the element pointed by first but not the element pointed by last.
//  - n: New size for the container.
//  - val: Value to fill the container with. Each of the n elements in the container will be initialized to a copy of this value.
    std::deque<char> characters;
 
    characters.assign(5, 'a');
    print_deque(characters);
 
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_deque(characters);
 
    characters.assign({'C', '+', '+', '1', '1'});
    print_deque(characters);
}

void test_at(){
// Description:
// - The deque::at() is a built-in function in C++ STL which is used to access an element at a particular position in the deque container.
// Complexity:
// - Constant.
// Parameters:
//  - pos: Position of an element in the container. Notice that the first element has a position of 0 (not 1).
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The first element is: " << data.at(0) << '\n';
    std::cout << "The third element is: " << data.at(2) << '\n';

    data.at(1) = 88;

    print_deque(data);
}

void test_front(){
// Description:
// - The deque::front() is a built-in function in C++ STL which is used to reference the first element of the deque container.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The first element is: " << data.front() << '\n';

    data.front() = 88;

    std::cout << "The first element is: " << data.front() << '\n';

    print_deque(data);
}

void test_back(){
// Description:
// - The deque::back() is a built-in function in C++ STL which is used to reference the last element of the deque container.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The last element is: " << data.back() << '\n';

    data.back() = 88;

    std::cout << "The last element is: " << data.back() << '\n';

    print_deque(data);
}

void test_empty(){
// Description:
// - The deque::empty() is a built-in function in C++ STL which is used to check whether the deque container is empty or not.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is " << (data.empty() ? "empty.\n" : "not empty.\n"); 
}

void test_size(){
// Description:
// - The deque::size() is a built-in function in C++ STL which is used to return the number of elements in the deque container.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque size is: " << data.size() << '\n';
}

void test_max_size(){
// Description:
// - The deque::max_size() is a built-in function in C++ STL which is used to return the maximum number of elements that can be stored in the deque container.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque max size is: " << data.max_size() << '\n';
}


// Minimal C++11 allocator with debug output.
template<class Tp>
struct NAlloc
{
    typedef Tp value_type;
 
    NAlloc() = default;
 
    template<class T> NAlloc(const NAlloc<T>&) {}
 
    Tp* allocate(std::size_t n)
    {
        n *= sizeof(Tp);
        std::cout << "allocating " << n << " bytes\n";
        return static_cast<Tp*>(::operator new(n));
    }
 
    void deallocate(Tp* p, std::size_t n)
    {
        std::cout << "deallocating " << n*sizeof*p << " bytes\n";
        ::operator delete(p);
    }
};
template<class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) { return true; }
template<class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) { return false; }

void test_shrink_to_fit(){
// Description:
// - The deque::shrink_to_fit() is a built-in function in C++ STL which is used to reduce the capacity of the container to fit its size and destroys all elements beyond the capacity.
// Complexity:
// - Linear in the number of elements in the container.
// Parameters:
//  - None.
    // std::queue has no capacity() function (like std::vector).
    // Because of this, we use a custom allocator to show the
    // working of shrink_to_fit.
 
    std::cout << "Default-construct deque:\n";
    std::deque<int, NAlloc<int>> deq;
 
    std::cout << "\nAdd 300 elements:\n";
    for (int i = 1000; i < 1300; ++i)
        deq.push_back(i);
 
    std::cout << "\nPop 100 elements:\n";
    for (int i = 0; i < 100; ++i)
        deq.pop_front();
 
    std::cout << "\nRun shrink_to_fit:\n";
    deq.shrink_to_fit();
 
    std::cout << "\nDestroy deque as it goes out of scope:\n";
}