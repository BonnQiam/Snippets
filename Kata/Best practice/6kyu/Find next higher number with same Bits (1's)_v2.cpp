#include <bitset> // bitset is a class template that represents an array of bits
#include <limits> // numeric_limits is a class template that provides a standardized way to query various properties of arithmetic types
using namespace std;

int nextHigher(int value)
{
    std::bitset<std::numeric_limits<int>::digits> first(value);
    // std::numeric_limits<int>::digits is the number of bits in the binary representation of the type int

    while (true)
    {
        value++;
        std::bitset<std::numeric_limits<int>::digits> second(value);
        if (first.count() == second.count())
        {
            return value;
        }
    }
}

/*
在函数内部，首先创建了一个bitset，名为first，它的大小是int类型二进制表示的位数（std::numeric_limits<int>::digits）。这个bitset用传入的value初始化。

然后，进入一个无限循环，目的是逐个检查value之后的每一个整数，直到找到满足条件的数为止：
- 循环内首先将value加1。
- 创建另一个bitset，名为second，用新的value值初始化。
- 使用bitset的count方法来计算first和second中1的数量。count方法返回bitset中设置为1的位的数量。
- 如果first和second中1的数量相同，那么就找到了满足条件的下一个更高的数，函数返回当前的value
*/