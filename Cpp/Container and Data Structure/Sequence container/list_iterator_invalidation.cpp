// example of iterator of list invalidation in g++ compiler

#include<iostream>
#include<list> 

using namespace std;

// It will not invalidate the iterator when adding element to the list
void list_insert_no_iterator_invalidation();

// It will invalidate the iterator when removing element from the list
void list_erase_iterator_invalidation();
void list_erase_solution_1();
void list_erase_solution_2();

int main(){
    //list_insert_no_iterator_invalidation();
    
    //list_erase_iterator_invalidation();
    //list_erase_solution_1();
    list_erase_solution_2();
    
    return 0;
}

void list_insert_no_iterator_invalidation(){
    list<int> l = {1, 2, 3, 4, 5};
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << "the iterator is: " << *it << endl;
        if(*it == 3){
            l.insert(it, 10);
        }
    }
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
}

void list_erase_iterator_invalidation(){
    list<int> l = {1, 2, 3, 4, 5};
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << "the iterator is: " << *it << endl;
        if(*it == 3){
            l.erase(it);
        }
    }
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
}

void list_erase_solution_1(){
    list<int> l = {1, 2, 3, 4, 5};
    
    for (auto iter = l.begin(); iter != l.end();){
        cout << "the iterator is: " << *iter << endl;
        if (*iter == 3)
            l.erase(iter++);
        else
            iter++;
    }
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
}

void list_erase_solution_2(){
    list<int> l = {1, 2, 3, 4, 5};
    
    for (auto iter = l.begin(); iter != l.end();){
        cout << "the iterator is: " << *iter << endl;
        if (*iter == 3)
            iter = l.erase(iter);  //erase删除元素，返回下一个迭代器
        else
            ++iter;
    }
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
}   