#include <cstddef>
#include <deque>
#include <iostream>
#include <new>

void test_assign();         // The deque::assign() is a built-in function in C++ STL which is used to assign new elements to a deque container by replacing old ones and resizing the container.

void test_at();             // The deque::at() is a built-in function in C++ STL which is used to access an element at a particular position in the deque container.
void test_front();          // The deque::front() is a built-in function in C++ STL which is used to reference the first element of the deque container.
void test_back();           // The deque::back() is a built-in function in C++ STL which is used to reference the last element of the deque container.

void test_begin_end();      // The deque::begin() is a built-in function in C++ STL which is used to return an iterator pointing to the first element of the deque container.
                            // The deque::end() is a built-in function in C++ STL which is used to return an iterator pointing to the theoretical element that follows last element in the deque container.
void test_rbegin_rend();    // The deque::rbegin() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the last element of the deque container (i.e., its reverse beginning).
                            // The deque::rend() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the theoretical element preceding the first element in the deque container (which is considered its reverse end).
void test_crbegin_crend();  // The deque::crbegin() is a built-in function in C++ STL which is used to return a constant reverse iterator pointing to the last element in the deque container (i.e., its reverse beginning).
                            // The deque::crend() is a built-in function in C++ STL which is used to return a constant reverse iterator pointing to the theoretical element preceding the first element in the deque container (which is considered its reverse end).

void test_empty();          // The deque::empty() is a built-in function in C++ STL which is used to check whether the deque container is empty or not.
void test_size();           // The deque::size() is a built-in function in C++ STL which is used to return the number of elements in the deque container.
void test_max_size();       // The deque::max_size() is a built-in function in C++ STL which is used to return the maximum number of elements that can be stored in the deque container.
void test_shrink_to_fit();  // The deque::shrink_to_fit() is a built-in function in C++ STL which is used to reduce the capacity of the container to fit its size and destroys all elements beyond the capacity. //! Wait for analyze

void test_clear();          // The deque::clear() is a built-in function in C++ STL which is used to remove all the elements from the deque container, thus leaving it with a size of 0.
void test_insert();         // The deque::insert() is a built-in function in C++ STL which is used to insert new elements into the deque container.
void test_emplace();        // The deque::emplace() is a built-in function in C++ STL which is used to insert a new element into the deque container, the new element is added to the end of the deque.
void test_erase();          // The deque::erase() is a built-in function in C++ STL which is used to remove elements from a container from the specified position or range.
void test_push_back();      // The deque::push_back() is a built-in function in C++ STL which is used to push elements into a deque from the back.
void test_emplace_back();   // The deque::emplace_back() is a built-in function in C++ STL which is used to insert a new element into the deque container, the new element is added to the end of the deque.
void test_pop_back();       // The deque::pop_back() is a built-in function in C++ STL which is used to pop or remove elements from a deque from the back.
void test_push_front();     // The deque::push_front() is a built-in function in C++ STL which is used to push elements into a deque from the front.
void test_emplace_front();  // The deque::emplace_front() is a built-in function in C++ STL which is used to insert a new element into the deque container, the new element is added to the beginning of the deque.
void test_pop_front();      // The deque::pop_front() is a built-in function in C++ STL which is used to pop or remove elements from a deque from the front.
void test_resize();         // The deque::resize() is a built-in function in C++ STL which is used to resize a deque container so that it contains n elements.
void test_swap();           // The deque::swap() is a built-in function in C++ STL which is used to swap the contents of one deque with another deque of same type and size.

#define print_deque(deq) \
    for (auto i : deq)   \
        std::cout << i << " "; \
    std::cout << std::endl;

int main(){
//    test_assign();

//    test_at();
//    test_front();
//    test_back();
//    test_begin_end();
//    test_rbegin_rend();
//    test_crbegin_crend();

//    test_empty();
//    test_size();
//    test_max_size();
//    test_shrink_to_fit();

//    test_clear();
//    test_insert();
//    test_emplace();
//    test_erase();
//    test_push_back();
//    test_emplace_back();
//    test_pop_back();
//    test_push_front();
//    test_emplace_front();
//    test_pop_front();
//    test_resize();
    test_swap();

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

void test_begin_end(){
// Description:
// - The deque::begin() is a built-in function in C++ STL which is used to return an iterator pointing to the first element of the deque container.
// - The deque::end() is a built-in function in C++ STL which is used to return an iterator pointing to the theoretical element that follows last element in the deque container.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    for (auto i = data.begin(); i != data.end(); ++i)
        std::cout << *i << " ";
}

void test_rbegin_rend(){
// Description:
// - The deque::rbegin() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the last element of the deque container (i.e., its reverse beginning).
// - The deque::rend() is a built-in function in C++ STL which is used to return a reverse iterator pointing to the theoretical element preceding the first element in the deque container (which is considered its reverse end).
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    for (auto i = data.rbegin(); i != data.rend(); ++i)
        std::cout << *i << " ";
}

void test_crbegin_crend(){
// Description:
// - The deque::crbegin() is a built-in function in C++ STL which is used to return a constant reverse iterator pointing to the last element in the deque container (i.e., its reverse beginning).
// - The deque::crend() is a built-in function in C++ STL which is used to return a constant reverse iterator pointing to the theoretical element preceding the first element in the deque container (which is considered its reverse end).
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    for (auto i = data.crbegin(); i != data.crend(); ++i)
        std::cout << *i << " ";
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

void test_clear(){
// Description:
// - The deque::clear() is a built-in function in C++ STL which is used to remove all the elements from the deque container, thus leaving it with a size of 0.
// Complexity:
// - Linear in the number of elements in the container, plus linear in the number of elements to be destroyed (if any).
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque size is: " << data.size() << '\n';
    data.clear();
    std::cout << "The deque size is: " << data.size() << '\n';
}

void test_insert(){
// Description:
// - The deque::insert() is a built-in function in C++ STL which is used to insert new elements into the deque container.
// Complexity:
// - Linear in the number of elements inserted plus the distance to the end of the deque.
// Parameters:
//  - pos: Position in the deque where the new elements are inserted.
//  - val: Value to be copied (or moved) to the inserted elements.
//  - n: Number of elements to insert. Each element is initialized to a copy of val.
//  - first, last: Iterators specifying a range of elements. Copies of the elements in the range [first,last) are inserted at pos (in the same order).
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.insert(data.begin(), 88);
    std::cout << "The deque is: ";
    print_deque(data);

    data.insert(data.begin(), 3, 88);
    std::cout << "The deque is: ";
    print_deque(data);

    std::deque<int> data2 = {1, 2, 4, 5, 5, 6};
    data.insert(data.begin(), data2.begin(), data2.end());
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_emplace(){
// Description:
// - The deque::emplace() is a built-in function in C++ STL which is used to insert a new element into the deque container, the new element is added to the end of the deque.
// Complexity:
// - Constant.
// Parameters:
//  - args: Arguments to forward to the constructor of the element.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.emplace(data.begin(), 88);
    std::cout << "The deque is: ";
    print_deque(data);

    data.emplace(data.end(), 88);
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_erase(){
// Description:
// - The deque::erase() is a built-in function in C++ STL which is used to remove elements from a container from the specified position or range.
// Complexity:
// - Linear in the number of elements erased plus the number of elements between pos and the end of the container.
// Parameters:
//  - pos: Iterator pointing to a single element to be removed from the deque.
//  - first, last: Iterators specifying a range of elements to be removed from the deque. i.e., [first,last). 
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.erase(data.begin());
    std::cout << "The deque is: ";
    print_deque(data);

    data.erase(data.begin(), data.begin() + 2);
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_push_back(){
// Description:
// - The deque::push_back() is a built-in function in C++ STL which is used to push elements into a deque from the back.
// Complexity:
// - Constant.
// Parameters:
//  - val: Value to be copied (or moved) to the new element.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.push_back(88);
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_emplace_back(){
// Description:
// - The deque::emplace_back() is a built-in function in C++ STL which is used to insert a new element into the deque container, the new element is added to the end of the deque.
// Complexity:
// - Constant.
// Parameters:
//  - args: Arguments to forward to the constructor of the element.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.emplace_back(88);
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_pop_back(){
// Description:
// - The deque::pop_back() is a built-in function in C++ STL which is used to pop or remove elements from a deque from the back.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.pop_back();
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_push_front(){
// Description:
// - The deque::push_front() is a built-in function in C++ STL which is used to push elements into a deque from the front.
// Complexity:
// - Constant.
// Parameters:
//  - val: Value to be copied (or moved) to the new element.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.push_front(88);
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_emplace_front(){
// Description:
// - The deque::emplace_front() is a built-in function in C++ STL which is used to insert a new element into the deque container, the new element is added to the beginning of the deque.
// Complexity:
// - Constant.
// Parameters:
//  - args: Arguments to forward to the constructor of the element.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.emplace_front(88);
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_pop_front(){
// Description:
// - The deque::pop_front() is a built-in function in C++ STL which is used to pop or remove elements from a deque from the front.
// Complexity:
// - Constant.
// Parameters:
//  - None.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque is: ";
    print_deque(data);

    data.pop_front();
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_resize(){
// Description:
// - The deque::resize() is a built-in function in C++ STL which is used to resize a deque container so that it contains n elements.
// Complexity:
// - Linear in the number of elements inserted/erased (copy/move construction) plus linear in the number of elements between pos and the end of the container (if any).
// Parameters:
//  - n: New container size, expressed in number of elements.
//  - val: Object whose content is copied to the added elements in case that n is greater than the current container size.
    std::deque<int> data = {1, 2, 4, 5, 5, 6};
 
    std::cout << "The deque size is: " << data.size() << '\n';
    data.resize(10);
    std::cout << "The deque size is: " << data.size() << '\n';
    std::cout << "The deque is: ";
    print_deque(data);

    data.resize(5);
    std::cout << "The deque size is: " << data.size() << '\n';
    std::cout << "The deque is: ";
    print_deque(data);

    data.resize(10, 88);
    std::cout << "The deque size is: " << data.size() << '\n';
    std::cout << "The deque is: ";
    print_deque(data);
}

void test_swap(){
// Description:
// - The deque::swap() is a built-in function in C++ STL which is used to swap the contents of one deque with another deque of same type and size.
// Complexity:
// - Constant.
// Parameters:
//  - c: Another deque container of the same type and size as this deque container, whose content is swapped with that of this deque.
    std::deque<int> data1 = {1, 2, 4, 5, 5, 6};
    std::deque<int> data2 = {11, 22, 44, 55, 55, 66};
 
    std::cout << "The deque1 is: ";
    print_deque(data1);
    std::cout << "The deque2 is: ";
    print_deque(data2);

    data1.swap(data2);

    std::cout << "The deque1 is: ";
    print_deque(data1);
    std::cout << "The deque2 is: ";
    print_deque(data2);
}