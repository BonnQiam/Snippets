#include <iostream>
#include <array>
#include <tuple>

template<typename T>
void print (T arg)
{
  std::cout << arg << '\n';  // print passed argument
}

template<typename T, typename... Types>
void print (T firstArg, Types... args)
{
  print(firstArg);           // call print() for the first argument
  print(args...);            // call print() for remaining arguments
}

// type for arbitray number of indices:
template <std::size_t...>
struct Indices{
};
/*
indices<0, 1, 2> is a type that can be used to pass a list of indices to a function.
*/


template<typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>)
{
    print(std::get<Idx>(t)...);
}

int main(){
    std::array<std::string, 5> arr = {"hello", "world", "from", "array", "of strings"};
    printByIdx(arr, Indices<0, 4, 3>());

    auto t = std::make_tuple(12, "monkeys", 2.0);
    printByIdx(t, Indices<0, 1, 2>());

    return 0;
}