#include <iostream>

// since C++11, we can use the following code to prevent copy constructor and copy assignment operator
struct noncopyable
{
  noncopyable() =default;
  noncopyable(const noncopyable&) =delete;
  noncopyable& operator=(const noncopyable&) =delete;
};

int main()
{
  noncopyable nc1;
  // noncopyable nc2(nc1); // error: use of deleted function 'noncopyable::noncopyable(const noncopyable&)'
  // nc1 = nc2; // error: use of deleted function 'noncopyable& noncopyable::operator=(const noncopyable&)'
  
  return 0;
}