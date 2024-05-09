#include <iostream>
#include <string>

class Customer
{
  private:
    std::string name;
  public:
    Customer(std::string const& n) : name(n) { }
    std::string getName() const { return name; }
};

struct CustomerEq 
{
    bool operator() (Customer const& c1, Customer const& c2) const 
    {
      return c1.getName() == c2.getName();
    }
};

int main(){
    Customer c1("John");
    Customer c2("John");
    Customer c3("Doe");

    /*
    在 C++ 中，operator() 是一个特殊的成员函数，被称为函数调用运算符。当你对一个对象使用圆括号 () 时，就会调用这个函数。例如，如果你有一个名为 hash 的对象，那么 hash() 就会调用 hash 对象的 operator() 函数。
    
    所以，当你看到 hash()，它实际上是在调用 hash 对象的 operator() 函数。这就是为什么 hash() 意味着 hash.operator()。
    */

    CustomerEq eq;
    std::cout << "c1 == c2: " << eq(c1, c2) << std::endl;
    std::cout << "c1 == c3: " << eq(c1, c3) << std::endl;

    return 0;
}