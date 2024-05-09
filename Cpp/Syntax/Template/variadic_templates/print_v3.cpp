#include <iostream>

template <typename T>
class AddSpace
{
  private:
	T const& ref;                  // refer to argument passed in constructor
  public:
    AddSpace(T const& r): ref(r) {}
    friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s) 
    {
      return os << s.ref << ' ';   // output passed argument and a space
    }
};

template <typename... Args>
void print(Args... args) 
{
	//(std::cout << ... << AddSpace(args)) << '\n';// if using C++17, can use class template argument deduction
    (std::cout << ... << AddSpace<Args>(args)) << '\n'; // not using class template argument deduction
}

int main()
{
    print(7.5, "hello", std::string("world"));
    return 0;
}