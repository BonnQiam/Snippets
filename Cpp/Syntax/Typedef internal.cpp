// uising typedef inside class and function
#include <iostream>

using namespace std;

class A
{
public:
    typedef int INT;
    void test()
    {
        INT i=0;
        cout<<"i:"<<i<<endl;
    }
};

void test()
{
    typedef int INT;
    INT i=0;
    cout<<"i:"<<i<<endl;
}

int main()
{
    A a;
    a.test();

    test();

    return 0;
}