#include <set>
#include <string>
#include <iostream>

void test_set_constructor();    // Test set constructor method
void test_equal_operator();     // Test set equal operator

void test_begin_end();          // The set::begin() returns an iterator to the beginning of the set
                                // The set::end() returns an iterator to the end of the set
void test_cbegin_cend();        // The set::cbegin() returns a constant iterator to the beginning of the set
                                // The set::cend() returns a constant iterator to the end of the set
void test_rbegin_rend();        // The set::rbegin() returns a reverse iterator to the beginning of the set
                                // The set::rend() returns a reverse iterator to the end of the set
void test_crbegin_crend();      // The set::crbegin() returns a constant reverse iterator to the beginning of the set
                                // The set::crend() returns a constant reverse iterator to the end of the set

void test_empty();              // The set::empty() returns whether the set container is empty
void test_size();               // The set::size() returns the number of elements in the set container
void test_max_size();           // The set::max_size() returns the maximum number of elements that the set container can hold

void test_clear();              // The set::clear() removes all elements from the set container
void test_insert();             // The set::insert() inserts new elements in the set
void test_emplace();            // The set::emplace() constructs element in-place
void test_emplace_hint();       // The set::emplace_hint() constructs element in-place using a hint
void test_erase();              // The set::erase() removes elements from the set container
void test_swap();               // The set::swap() swaps the contents of two sets

void test_count();              // The set::count() returns the number of elements matching specific key
void test_find();               // The set::find() returns an iterator to the element, if an element with specified key is found
void test_equal_range();        // The set::equal_range() returns a range containing all elements with a given key in the container
void test_lower_bound();        // The set::lower_bound() returns an iterator to the first element that is not less than the given key
void test_upper_bound();        // The set::upper_bound() returns an iterator to the first element that is greater than the given key
void test_key_comp();           // The set::key_comp() returns a copy of the comparison object used by the container
                                //! Not understand
void test_value_comp();         // The set::value_comp() returns a copy of the comparison object used by the container
                                //! Not understand

#define print_set(x) for (auto i : x) { std::cout << i << " "; } std::cout << std::endl;

int main() {
    
//    test_set_constructor();
//    test_equal_operator();

//    test_begin_end();
//    test_cbegin_cend();
//    test_rbegin_rend();
//    test_crbegin_crend();

//    test_empty();
//    test_size();
//    test_max_size();

//    test_clear();
//    test_insert();

//    test_count();
//    test_find();
//    test_equal_range();
//    test_lower_bound();
//    test_upper_bound();
//    test_key_comp();
    test_value_comp();

    return 0;
}

void test_set_constructor(){
// Description
// - set is a container that store unique elements following a specific order
// - internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object
// - set containers are generally slower than unordered_set containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order
// - sets are typically implemented as binary search trees

    std::set<int> s1;                       // Default constructor
    std::set<int> s2 = {1, 2, 3, 4, 5};     // Initializer list constructor
    std::set<int> s3(s2);                   // Copy constructor
    std::set<int> s4(std::move(s3));        // Move constructor
    std::set<int> s5(s2.begin(), s2.end()); // Range constructor

    std::cout << "s1: "; print_set(s1);
    std::cout << "s2: "; print_set(s2);
    std::cout << "s3: "; print_set(s3);
    std::cout << "s4: "; print_set(s4);
    std::cout << "s5: "; print_set(s5);
}

void test_equal_operator(){
// Description
// - equal operator is used to assign new contents to the container by replacing the existing contents
// Complexity
// - Linear in the size of the container

    std::set<int> s1 = {1, 2, 3, 4, 5};
    std::set<int> s2 = {6, 7, 8, 9, 10};
    std::set<int> s3 = {11, 12, 13, 14, 15};

    std::cout << "s1: "; print_set(s1);
    std::cout << "s2: "; print_set(s2);
    std::cout << "s3: "; print_set(s3);

    s1 = s2;
    std::cout << "s1 = s2: "; print_set(s1);

    s1 = std::move(s3);
    std::cout << "s1 = std::move(s3): "; print_set(s1);
}

void test_begin_end(){
// Description
// - The set::begin() returns an iterator to the beginning of the set
// - The set::end() returns an iterator to the end of the set
// Complexity
// - Constant

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.begin(): " << *s.begin() << std::endl;
    std::cout << "s.end(): " << *s.end() << std::endl;
}

void test_cbegin_cend(){
// Description
// - The set::cbegin() returns a constant iterator to the beginning of the set
// - The set::cend() returns a constant iterator to the end of the set
// Complexity
// - Constant

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.cbegin(): " << *s.cbegin() << std::endl;
    std::cout << "s.cend(): " << *s.cend() << std::endl;
}

void test_rbegin_rend(){
// Description
// - The set::rbegin() returns a reverse iterator to the beginning of the set
// - The set::rend() returns a reverse iterator to the end of the set
// Complexity
// - Constant

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.rbegin(): " << *s.rbegin() << std::endl;
    std::cout << "s.rend(): " << *s.rend() << std::endl;
}

void test_crbegin_crend(){
// Description
// - The set::crbegin() returns a constant reverse iterator to the beginning of the set
// - The set::crend() returns a constant reverse iterator to the end of the set
// Complexity
// - Constant

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.crbegin(): " << *s.crbegin() << std::endl;
    std::cout << "s.crend(): " << *s.crend() << std::endl;
}

void test_empty(){
// Description
// - The set::empty() returns whether the set container is empty
// Complexity
// - Constant

    std::set<int> s1;
    std::set<int> s2 = {1, 2, 3, 4, 5};

    std::cout << "s1.empty(): " << s1.empty() << std::endl;
    std::cout << "s2.empty(): " << s2.empty() << std::endl;
}

void test_size(){
// Description
// - The set::size() returns the number of elements in the set container
// Complexity
// - Constant

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.size(): " << s.size() << std::endl;
}

void test_max_size(){
// Description
// - The set::max_size() returns the maximum number of elements that the set container can hold
// Complexity
// - Constant

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.max_size(): " << s.max_size() << std::endl;
}

void test_clear(){
// Description
// - The set::clear() removes all elements from the set container
// Complexity
// - Linear in the size of the container

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s: "; print_set(s);

    s.clear();
    std::cout << "s.clear(): "; print_set(s);
}

void test_insert(){
// Description
// - The set::insert() inserts new elements in the set
// Complexity
// - Logarithmic in the size of the container

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s: "; print_set(s);

    s.insert(6);
    std::cout << "s.insert(6): "; print_set(s);

    s.insert(7);
    std::cout << "s.insert(7): "; print_set(s);

    s.insert(8);
    std::cout << "s.insert(8): "; print_set(s);

    s.insert(1);
    std::cout << "s.insert(1): "; print_set(s);
}

void test_emplace(){
// Description
// - The set::emplace() is used to insert new elements in set. It returns a pair containing an iterator to the inserted key and the second is a boolean value which gives the information of the operation. true if insertion happened, false is not.
// Complexity
// - Logarithmic in the size of the container

    // Create a set object holding integers
    std::set<int> mySet {1,2,3,4,-5};

    std::pair<std::set<int>::iterator,bool> pr;
    int key = 6;
    bool inserted= false;
    pr = mySet.emplace(key);                                                    //inserting key in set mySet
    std::set<int>::iterator itr = pr.first;
    inserted = pr.second;
    if(inserted){                                                              //checking if inserted in mySet
        std::cout<<" New element: "<<key<<" inserted in set"<<'\n';            //print key inserted in the set.
    }
    else{
        std::cout<<" Element: "<<key<<" already present in the set"<<'\n';     //print key already present.
    }
}

void test_emplace_hint(){
// Description
// - The set::emplace_hint() is used to insert new elements in set. It returns an iterator to the inserted element.
// Complexity
// - Logarithmic in the size of the container

    std::set<std::string> myset;
	auto it = myset.begin();
	it = myset.emplace_hint (it,"red");
	it = myset.emplace_hint (it,"orange");
	it = myset.emplace_hint (it,"yellow");
	  
	std::cout << "myset contains:";
    for (const std::string& mystring: myset)
	  std::cout << ' ' << mystring;
	std::cout << '\n';
}

void test_erase(){
// Description
// - The set::erase() removes elements from the set container
// Complexity
// - Logarithmic in the size of the container

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s: "; print_set(s);

    s.erase(1);
    std::cout << "s.erase(1): "; print_set(s);

    auto itr_1 = s.find(2);
    s.erase(s.begin(), itr_1);
    std::cout << "s.erase(s.begin(), itr_1): "; print_set(s);
}

void test_swap(){
// Description
// - The set::swap() swaps the contents of two sets
// Complexity
// - Constant

    std::set<int> s1 = {1, 2, 3, 4, 5};
    std::set<int> s2 = {6, 7, 8, 9, 10};

    std::cout << "s1: "; print_set(s1);
    std::cout << "s2: "; print_set(s2);

    s1.swap(s2);
    std::cout << "s1.swap(s2): "; print_set(s1);
    std::cout << "s2.swap(s1): "; print_set(s2);
}

void test_count(){
// Description
// - The set::count() returns the number of elements matching specific key
// Complexity
// - Logarithmic in the size of the container

    std::set<int> s = {1, 1, 2, 3, 4, 5};

    print_set(s);

    std::cout << "s.count(1): " << s.count(1) << std::endl;
    std::cout << "s.count(6): " << s.count(6) << std::endl;
}

void test_find(){
// Description
// - The set::find() returns an iterator to the element, if an element with specified key is found
// - This method is used to know if a value already exists in a set. If the value exists in the set, it returns an iterator to it, otherwise it returns an iterator to set::end.
// Complexity
// - Logarithmic in the size of the container

    std::set<int> s = {1, 2, 3, 4, 5};

    std::cout << "s.find(1): " << *s.find(1) << std::endl;
    std::cout << "s.find(6): " << *s.find(6) << std::endl;
}

void test_equal_range(){
// Description
// - The set::equal_range() returns a range containing all elements with a given key in the container
// Complexity
// - Logarithmic in the size of the container

    std::set<float> s = {1.1, 2.1, 3.5, 3.3, 3.4, 4.1, 5.1};

    auto range = s.equal_range(3.5); // range is a pair of iterators, the first pointing to the first element that is not less than key and the second pointing to the first element greater than key
    std::cout << "s.equal_range(3.5): " << *range.first << " " << *range.second << std::endl;

    // Test equal range if key is not found
    range = s.equal_range(3.2);
    std::cout << "s.equal_range(3.2): " << *range.first << " " << *range.second << std::endl;

    // Test equal range if key is greater than the largest element in the set
    range = s.equal_range(6.0);
    std::cout << "s.equal_range(6.0): " << *range.first << " " << *range.second << std::endl;
}

void test_lower_bound(){
// Description
// - The set::lower_bound() returns an iterator to the first element that is not less than the given key
// Complexity
// - Logarithmic in the size of the container

    std::set<float> s = {1.1, 2.1, 3.5, 3.3, 3.4, 4.1, 5.1};

    std::cout << "s.lower_bound(3.5): " << *s.lower_bound(3.6) << std::endl;
    std::cout << "s.lower_bound(3.2): " << *s.lower_bound(3.2) << std::endl;
    std::cout << "s.lower_bound(6.0): " << *s.lower_bound(6.0) << std::endl;
}

void test_upper_bound(){
// Description
// - The set::upper_bound() returns an iterator to the first element that is greater than the given key
// Complexity
// - Logarithmic in the size of the container

    std::set<float> s = {1.1, 2.1, 3.5, 3.3, 3.4, 4.1, 5.1};

    std::cout << "s.upper_bound(3.5): " << *s.upper_bound(3.1) << std::endl;
    std::cout << "s.upper_bound(3.2): " << *s.upper_bound(3.2) << std::endl;
    std::cout << "s.upper_bound(6.0): " << *s.upper_bound(6.0) << std::endl;
}

void test_key_comp(){
// Description
// - The set::key_comp() returns a copy of the comparison object used by the container
// Complexity
// - Constant
// Parameters
// - none

    std::set<int> s = {1, 2, 3, 4, 5};

    auto comp = s.key_comp();

    // comp(a, b) returns true if a is less than b
    std::cout << "s.key_comp()(1, 2): " << comp(1, 2) << std::endl;
    std::cout << "s.key_comp()(2, 1): " << comp(2, 1) << std::endl;
    std::cout << "s.key_comp()(1, 1): " << comp(1, 5) << std::endl;
}

void test_value_comp(){
// Description
// - The set::value_comp() returns a copy of the comparison object used by the container
// Complexity
// - Constant
// Parameters
// - none

    std::set<int> s = {1, 2, 3, 4, 5};

    auto comp = s.value_comp();

    // comp(a, b) returns true if a is less than b
    std::cout << "s.value_comp()(1, 2): " << comp(1, 2) << std::endl;
    std::cout << "s.value_comp()(2, 1): " << comp(2, 1) << std::endl;
    std::cout << "s.value_comp()(1, 1): " << comp(1, 5) << std::endl;
}