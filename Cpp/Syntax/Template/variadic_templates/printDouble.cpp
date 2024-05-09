#include <iostream>
#include <complex>

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

template <typename... T>
void printDouble(T const&... args)
{
    print(args + args...);
}

template <typename... T>
void addOne(T const&... args)
{
    //print(args + 1...); // ERROR: 1... is a literal with too many decimal points
    
    print(args + 1 ...); // OK
    //print((args + 1)...); // OK
}

int main()
{
  printDouble(7.5, std::string("hello"), std::complex<float>(4,2));
  addOne(1, 2, 3, 4, 5, 6, 7, 8, 9, 10); // 2 3 4 5 6 7 8 9 10 11

  return 0;
}