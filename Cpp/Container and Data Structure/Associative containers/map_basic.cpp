#include <map>
#include <iostream>

void test_map_constructor();        // test map constructor


#define Print_map(x) for(auto i : x) std::cout << i.first << " " << i.second << std::endl;


int main()
{
    test_map_constructor();
    
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