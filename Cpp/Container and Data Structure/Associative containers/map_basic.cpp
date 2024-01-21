#include <map>
#include <iostream>

void test_map_constructor();        // test map constructor

void test_at();                     // The map::at() is used to access the element with a specified key
void test_operatotr_square_bracket(); // The map::operator[] is used to access the element with a specified key

void test_begin_end();              // The map::begin() is used to return an iterator pointing to the first element in the map container
                                    // The map::end() is used to return an iterator pointing to the theoretical element that follows last element in the map container
void test_cbegin_cend();            // The map::cbegin() is used to return a constant iterator pointing to the first element in the map container
                                    // The map::cend() is used to return a constant iterator pointing to the theoretical element that follows last element in the map container
void test_rbegin_rend();            // The map::rbegin() is used to return a reverse iterator pointing to the last element in the map container
                                    // The map::rend() is used to return a reverse iterator pointing to the theoretical element preceding the first element in the map container
void test_crbegin_crend();          // The map::crbegin() is used to return a constant reverse iterator pointing to the last element in the map container
                                    // The map::crend() is used to return a constant reverse iterator pointing to the theoretical element preceding the first element in the map container

void test_empty();                  // The map::empty() is used to check whether the map container is empty or not
void test_size();                   // The map::size() is used to return the number of elements in the map container
void test_max_size();               // The map::max_size() is used to return the maximum number of elements that the map container can hold

void test_clear();                  // The map::clear() is used to remove all the elements of the map container, thus leaving it with a size of 0
void test_insert();                 // The map::insert() is used to insert elements with a particular key in the map container
void test_emplace();                // The map::emplace() is used to insert a new element into the map container, only if the element to be inserted is unique
void test_emplace_hint();           // The map::emplace_hint() is used to insert a new element into the map container, only if the element to be inserted is unique
void test_erase();                  // The map::erase() is used to remove either a single element or a range of elements from the map container
void test_swap();                   // The map::swap() is used to exchange the contents of two maps but the maps must be of same type, although sizes may differ

void test_find();                   // The map::find() is used to search the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end
void test_count();                  // The map::count() is used to return the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates
void test_equal_range();            //! The map::equal_range() is used to returns an iterator range that contains all the elements with key that compares equivalent to the specified argument
void test_lower_bound();            //! The map::lower_bound() is used to return an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after)
void test_upper_bound();            //! The map::upper_bound() is used to return an iterator pointing to the first element in the container whose key is considered to go after k (i.e., either it is equivalent or goes after)

#define Print_map(x) for(auto i : x) std::cout << "key is " << i.first << ", value is " << i.second << std::endl;


int main()
{
//    test_map_constructor();

//    test_at();
//    test_operatotr_square_bracket();

//    test_begin_end();
//    test_cbegin_cend();
//    test_rbegin_rend();
//    test_crbegin_crend();

//    test_empty();
//    test_size();
//    test_max_size();

//    test_clear();
//    test_insert();
//    test_emplace();
//    test_emplace_hint();
//    test_erase();
//    test_swap();
    
//    test_find();
//    test_count();
//    test_equal_range();
    test_lower_bound();

    return 0;
}

void test_map_constructor(){
// Description :
// - mpa is a associative container that store element in key-value pair
// - map is a sorted container, it will sort the element by key
// - map is implemented by red-black tree
// - map is a unique container, it will not store duplicated key
// - map is a ordered container, it will store element in order
    
    std::map<int, int> map1;                            // default constructor
    std::map<int, int> map2(map1);                      // copy constructor
    std::map<int, int> map3(map1.begin(), map1.end());  // range constructor
    std::map<int, int> map4({{1, 1}, {2, 2}, {3, 3}});  // initializer list constructor
    std::map<int, int> map5 = map1;                     // copy assignment
    std::map<int, int> map6 = {{1, 1}, {2, 2}, {3, 3}}; // initializer list assignment

    // move constructor
    std::map<int, int> map7(std::move(map1));

    std::cout << "map1: "; Print_map(map1);
    std::cout << "map2: "; Print_map(map2);
    std::cout << "map3: "; Print_map(map3);
    std::cout << "map4: "; Print_map(map4);
    std::cout << "map5: "; Print_map(map5);
    std::cout << "map6: "; Print_map(map6);
    std::cout << "map7: "; Print_map(map7);
}

void test_at(){
// Description :
// - The map::at() is used to access the element with a specified key
// - If the element with specified key is not found, it will throw an exception
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << map1.at(1) << std::endl;
    std::cout << map1.at(2) << std::endl;
    std::cout << map1.at(3) << std::endl;
    std::cout << map1.at(4) << std::endl; // throw an exception
}

void test_operatotr_square_bracket(){
// Description :
// - The map::operator[] is used to access the element with a specified key
// - If the element with specified key is not found, it will insert a new element with that key
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << map1[1] << std::endl;
    std::cout << map1[2] << std::endl;
    std::cout << map1[3] << std::endl;
    std::cout << map1[4] << std::endl; 
    
    // insert a new element with key 4
    map1[4] = 4;
    std::cout << map1[4] << std::endl; // return the value of element with key 4
}

void test_begin_end(){
// Description :
// - The map::begin() is used to return an iterator pointing to the first element in the map container
// - The map::end() is used to return an iterator pointing to the theoretical element that follows last element in the map container
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};

    for(auto it = map1.begin(); it != map1.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void test_cbegin_cend(){
// Description :
// - The map::cbegin() is used to return a constant iterator pointing to the first element in the map container
// - The map::cend() is used to return a constant iterator pointing to the theoretical element that follows last element in the map container
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int>::const_iterator it_cbegin = map1.cbegin();
    std::map<int, int>::const_iterator it_cend = map1.cend();
    
    for(auto it = it_cbegin; it != it_cend; it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void test_rbegin_rend(){
// Description :
// - The map::rbegin() is used to return a reverse iterator pointing to the last element in the map container
// - The map::rend() is used to return a reverse iterator pointing to the theoretical element preceding the first element in the map container
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int>::reverse_iterator it_rbegin = map1.rbegin();
    std::map<int, int>::reverse_iterator it_rend = map1.rend();
    
    for(auto it = it_rbegin; it != it_rend; it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void test_crbegin_crend(){
// Description :
// - The map::crbegin() is used to return a constant reverse iterator pointing to the last element in the map container
// - The map::crend() is used to return a constant reverse iterator pointing to the theoretical element preceding the first element in the map container
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int>::const_reverse_iterator it_crbegin = map1.crbegin();
    std::map<int, int>::const_reverse_iterator it_crend = map1.crend();
    
    for(auto it = it_crbegin; it != it_crend; it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void test_empty(){
// Description :
// - The map::empty() is used to check whether the map container is empty or not
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1;
    std::cout << map1.empty() << std::endl;
    map1.insert({1, 1});
    std::cout << map1.empty() << std::endl;
}

void test_size(){
// Description :
// - The map::size() is used to return the number of elements in the map container
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1;
    std::cout << map1.size() << std::endl;
    map1.insert({1, 1});
    std::cout << map1.size() << std::endl;
}

void test_max_size(){
// Description :
// - The map::max_size() is used to return the maximum number of elements that the map container can hold
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1;
    std::cout << map1.max_size() << std::endl;
}

void test_clear(){
// Description :
// - The map::clear() is used to remove all the elements of the map container, thus leaving it with a size of 0
// Complexity :
// - Time complexity : O(n)
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << map1.size() << std::endl;
    map1.clear();
    std::cout << map1.size() << std::endl;
}

void test_insert(){
// Description :
// - The map::insert() is used to insert elements with a particular key in the map container
// - If the element with specified key is already exist, it will not insert the element
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1;
    map1.insert({1, 1});

    Print_map(map1);
}


void test_emplace(){
// Description :
// - The map::emplace() is used to insert a new element into the map container, only if the element to be inserted is unique
// - It inserts the key and its element in the map container and increases the container size by one. If the same key is emplaced more than once, the map stores the first element only as the map is a container which does not store multiple keys of the same value. The function does not return anything and accepts two parameters i.e. key and element.
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1;
    map1.emplace(1, 1);
    map1.emplace(1, 2);
    map1.emplace(2, 1);

    Print_map(map1);
}


void test_emplace_hint(){
// Description :
// - The map::emplace_hint() is used to insert a new element into the map container, only if the element to be inserted is unique
// - It inserts the key and its element in the map container and increases the container size by one. If the same key is emplaced more than once, the map stores the first element only as the map is a container which does not store multiple keys of the same value. The function does not return anything and accepts two parameters i.e. key and element.
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1;
    map1.emplace_hint(map1.begin(), 1, 1);
    map1.emplace_hint(map1.begin(), 1, 2);
    map1.emplace_hint(map1.begin(), 2, 1);

    Print_map(map1);
}

void test_erase(){
// Description :
// - The map::erase() is used to remove either a single element or a range of elements from the map container
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    map1.erase(1);
    Print_map(map1);
}

void test_swap(){
// Description :
// - The map::swap() is used to exchange the contents of two maps but the maps must be of same type, although sizes may differ
// Complexity :
// - Time complexity : O(1)
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int> map2 = {{4, 4}, {5, 5}, {6, 6}};
    map1.swap(map2);
    Print_map(map1);
    Print_map(map2);
}

void test_find(){
// Description :
// - The map::find() is used to search the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    auto it = map1.find(1);
    std::cout << it->first << " " << it->second << std::endl;
}

void test_count(){
// Description :
// - The map::count() is used to return the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << map1.count(1) << std::endl;
    std::cout << map1.count(4) << std::endl;
}

void test_equal_range(){
// Description :
// - The map::equal_range() is used to returns an iterator range that contains all the elements with key that compares equivalent to the specified argument
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    auto it = map1.equal_range(1);
    std::cout << it.first->first << " " << it.first->second << std::endl;
    std::cout << it.second->first << " " << it.second->second << std::endl;
}

void test_lower_bound(){
// Description :
// - The map::lower_bound() is used to return an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after)
// Complexity :
// - Time complexity : O(log(n))
// - Space complexity : O(1)
    
    std::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}};
    auto it = map1.lower_bound(4);
    std::cout << it->first << " " << it->second << std::endl;
}
