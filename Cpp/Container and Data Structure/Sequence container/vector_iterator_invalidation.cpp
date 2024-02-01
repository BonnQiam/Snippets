// example of iterator invalidation in g++ compiler

#include<iostream>
#include<vector>

using namespace std;

/****************** iterator invalidation if remove element  ****
 * Every iterator and reference after the point of erasing is invalidated. 
*/

void vector_erase_iterator_invalidation();
void vector_erase_solution();

//? if you use pop_back() to remove the element, the iterator will not be invalidated
void vector_pop_back_iterator_invalidation();


/****************** iterator invalidation if add element  ****
 * All iterators which point to an element before the point of insertion are unaffected but all others are invalidated. But, in case if due to insertion the size of the vector becomes more than the previous capacity then all iterators get invalidated
*/

void vector_insert_iterator_invalidation(); 
void vector_insert_solution();

void vector_emplace_iterator_invalidation();
void vector_emplace_solution();

void vector_push_back_iterator_invalidation(); 
void vector_push_back_solution();

void vector_emplace_back_iterator_invalidation();
void vector_emplace_back_solution();

/************************************************************/
void Special_case();
void Special_case_solution();

int main() {

//    Special_case();
    Special_case_solution();

//    vector_erase_iterator_invalidation();
//    vector_erase_solution();

//    vector_pop_back_iterator_invalidation();

//    vector_insert_iterator_invalidation();
//    vector_insert_solution();

//    vector_emplace_iterator_invalidation();
//    vector_emplace_solution();

//    vector_push_back_iterator_invalidation();
//    vector_push_back_solution();

//    vector_emplace_back_iterator_invalidation();
//    vector_emplace_back_solution();

    return 0;
}

void vector_erase_iterator_invalidation(){
    vector<int> q{ 1,2,3,4,5,6 };
	// We want delete all elements which are greater than 2
	for (auto it = q.begin(); it != q.end(); it++) {
        std::cout << "the iterator is: " << *it << std::endl;
		if (*it > 2)
			q.erase(it); // iterator invalidation happens here
	}
	// show the result
	for (auto it = q.begin(); it != q.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void vector_erase_solution(){
    vector<int> q{ 1,2,3,4,5,6 };
    // We want delete all elements which are greater than 2
    for (auto it = q.begin(); it != q.end(); ) {
        std::cout << "the iterator is: " << *it << std::endl;
        if (*it > 2)
            it = q.erase(it); // erase() returns the next iterator
        else
            it++;
    }
    // show the result
    for (auto it = q.begin(); it != q.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void vector_pop_back_iterator_invalidation(){
    // Creating a sample vector
    vector<int> v = { 1, 5, 5, 10, 15, 20 };
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++){
        std::cout << "the iterator is: " << *it << std::endl;
        if ((*it) == 5)
            v.pop_back();
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";

}

void vector_insert_iterator_invalidation(){
     // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++){
        std::cout << "the iterator is: " << *it << std::endl;
        if ((*it) == 5)
            v.push_back(-1); // Iterator invalidation happens here
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
}

void vector_insert_solution() {
    // Creating a sample vector
    std::vector<int> v = {1, 5, 5, 10, 15, 20};

    // Changing vector while iterating over it
    // (Avoid iterator invalidation)
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << "the iterator is: " << *it << std::endl;
        if (*it == 5) {
            it = v.insert(it, -1) + 1; // updates the iterator it to point to the element after the newly inserted -1. This ensures that the iterator remains valid after the insertion.
        }
    }

    for (const auto &element : v) {
        std::cout << element << " ";
    }
}

void vector_emplace_iterator_invalidation(){
    // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++){
        std::cout << "the iterator is: " << *it << std::endl;
        if ((*it) == 5)
            v.emplace(it, -1); // Iterator invalidation happens here
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
}

void vector_emplace_solution(){
    // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++){
        std::cout << "the iterator is: " << *it << std::endl;
        if ((*it) == 5){
            it = v.emplace(it, -1) + 1; // updates the iterator it to point to the element after the newly inserted -1. This ensures that the iterator remains valid after the insertion.
        }
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
}


void vector_push_back_iterator_invalidation(){
    // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++){
        std::cout << "the iterator is: " << *it << std::endl;
        if ((*it) == 5)
            v.push_back(-1); // Iterator invalidation happens here
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
}

void vector_push_back_solution(){
    // Creating a sample vector
    std::vector<int> v = {1, 5, 5, 10, 15, 20};

    // Reserve enough space to avoid reallocation
    v.reserve(v.size() + 1);  // Assuming one additional element will be added
    v.reserve(v.size() + 5);  // Assuming one additional element will be added

    // Changing vector while iterating over it
    // (Avoid iterator invalidation)
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << "the iterator is: " << *it << std::endl;
        if (*it == 5) {
            v.push_back(-1);
        }
    }

    for (const auto &element : v) {
        std::cout << element << " ";
    }
}

void vector_emplace_back_iterator_invalidation(){
    // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };
 
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++){
        std::cout << "the iterator is: " << *it << std::endl;
        if ((*it) == 5)
            v.emplace_back(-1); // Iterator invalidation happens here
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
}

void vector_emplace_back_solution(){
    // Creating a sample vector
    std::vector<int> v = {1, 5, 5, 10, 15, 20};

    // Reserve enough space to avoid reallocation
    v.reserve(v.size() + 5);  // Assuming one additional element will be added

    // Changing vector while iterating over it
    // (Avoid iterator invalidation)
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << "the iterator is: " << *it << std::endl;
        if (*it == 5) {
            v.emplace_back(-1);
        }
    }

    for (const auto &element : v) {
        std::cout << element << " ";
    }
}

void Special_case(){
    std::vector<int> v      = {1, 5, 5, 10, 15, 20};
    std::vector<int> v_bak  = {1, 5, 5, 10, 15, 20};

    auto itr = v_bak.begin();
    for(auto it = v.begin(); it != v.end(); it++){
        std::cout << "the it  iterator is: " << *it << std::endl;
        std::cout << "the itr iterator is: " << *itr << std::endl;
        if(*it == 5){
            v_bak.erase(itr);
//            continue;
        }
        ++itr;
    }

    // print v_bak
    for(auto it = v_bak.begin(); it != v_bak.end(); it++){
        std::cout << *it << " ";
    }
}

void Special_case_solution(){
    std::vector<int> v = {1, 5, 5, 10, 15, 20};
    std::vector<int> v_bak = {1, 5, 5, 10, 15, 20};

    auto it = v.begin();
    auto it_bak = v_bak.begin();

    while (it != v.end() && it_bak != v_bak.end()) {
        std::cout << "the iterator is: " << *it << std::endl;
        std::cout << "the iterator_bak is: " << *it_bak << std::endl;

        if (*it == 5) {
            // Erase the corresponding element in v_bak and update the iterator
            it_bak = v_bak.erase(it_bak);
            it++;
        } else {
            it++;
            it_bak++;
        }
    }

    // print v_bak
    for(auto it = v_bak.begin(); it != v_bak.end(); it++){
        std::cout << *it << " ";
    }
}