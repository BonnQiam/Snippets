#include <iostream>
#include <string>
#include <unordered_set>

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

struct CustomerHash 
{
    std::size_t operator() (Customer const& c) const 
    {
      return std::hash<std::string>()(c.getName());
    }
};

// define class that combines operator() for variadic base classes:
template <typename... Bases>
struct Overloader : Bases...
{
    using Bases::operator()...;  // OK since C++17
};

int main()
{
    // combine hasher and equality for customers in one type:
    using CustomerOP = Overloader<CustomerHash,CustomerEq>;

    // Test the hash and equality function
    Customer c1("nico");
    Customer c2("nico");

    CustomerHash hash;
    CustomerEq eq;
    CustomerOP op;

    std::cout << "hash(c1): " << hash(c1) << std::endl; // hash() means hash.operator()
    std::cout << "hash(c2): " << hash(c2) << std::endl;
    std::cout << "eq(c1, c2): " << eq(c1, c2) << std::endl;
    std::cout << "op(c1, c2): " << op(c1, c2) << std::endl;
    std::cout << "Op(c1): " << op(c1) << std::endl;

    
    ///std::unordered_set<Customer,CustomerHash,CustomerEq> coll1;
    // Customer serves as both key and value type:
    // CustomerHash is used for hashing and CustomerEq for equality checking

    ///std::unordered_set<Customer,CustomerOP,CustomerOP> coll2;
    // Customer serves as both key and value type:
    // CustomerOP is used for hashing and equality checking

    return 0;
} 