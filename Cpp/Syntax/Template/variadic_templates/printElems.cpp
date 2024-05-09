#include <iostream>
#include <vector>

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

template <typename C, typename... Idx>
void printElems(C const& coll, Idx... idx)
{
    print(coll[idx]...); // call print() for all elements with index idx...
}

template <std::size_t... Idx, typename C>
void printIdx(C const& coll)
{
    print(coll[Idx]...);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printElems(arr, 0, 2, 4);
    printIdx<0, 2, 4>(arr);

    std::vector<std::string> coll = {"good", "times", "say", "bye"};
    printElems(coll, 2, 0, 3);
    printIdx<2, 0, 3>(coll);

    return 0;
}