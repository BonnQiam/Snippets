#include <iostream>

template <typename... T>
auto foldSum (T... s)
{
    return (... + s); // ((s1 + s2) + s3) + ...
}

int main()
{
    std::cout << foldSum(1, 2, 3, 4, 5) << std::endl;
    return 0;
}