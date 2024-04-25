// Example of meta-function to remove reference from a type.
#include<iostream>

template <typename T> struct remove_reference      { using type = T; };     // #1
template <typename T> struct remove_reference<T&>  { using type = T; };     // #2
template <typename T> struct remove_reference<T&&> { using type = T; };     // #3

template <typename T>
void foo(typename remove_reference<T>::type a_copy) { a_copy += 1; }

int main(){
    // case 1:
    int&& i = 0;
    remove_reference<decltype(i)>::type j = i;    
    // decltype() is used to get the type of an expression. In here, it is used to get the type of i, i.e. int&&. So remove_reference<int&&>::type corresponds to #3, which is int.
    // equivalent to: int j = i;

    // check if remove_reference<int&&>::type is not reference type
    static_assert(
            !std::is_reference<remove_reference<decltype(i)>::type>::value, 
            "Error: remove_reference<int&&>::type is a reference type");
    std::cout << "Assertion passed\n" << std::endl;

    // case 2:
    foo<int>(i);    // passed by value
    foo<int&&>(i);  // passed by value

    // check value of i after foo<int>(i) and foo<int&&>(i)
    std::cout << i << std::endl;    // 0, i is not changed

    return 0;
}