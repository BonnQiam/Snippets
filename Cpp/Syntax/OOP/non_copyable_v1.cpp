#include <iostream>

// before C++11, we can use the following code to prevent copy constructor and copy assignment operator
struct noncopyable
{
  noncopyable() {};

private:
  noncopyable(const noncopyable&);
  noncopyable& operator=(const noncopyable&);
};

int main()
{
  noncopyable nc1;
  // noncopyable nc2(nc1); // error: 'noncopyable::noncopyable(const noncopyable&)' is private
  // nc1 = nc2; // error: 'noncopyable& noncopyable::operator=(const noncopyable&)' is private
  
  return 0;
}