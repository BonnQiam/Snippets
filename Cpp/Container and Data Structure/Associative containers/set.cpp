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