#include <string>
#include <vector>
#include <algorithm>

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};

int SmallestDivisor(int n)
{
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return -1;// means n is a prime number
}

void Prime_Decomp(int n, std::vector <int> &result)
{
    if (n == 1)
        return;
    int divisor = SmallestDivisor(n);
    if (divisor == -1)
    {
        result.push_back(n);
        return;
    }
    result.push_back(divisor);
    Prime_Decomp(n / divisor, result);
    // Sort the result vector
    std::sort(result.begin(), result.end());
}

std::string PrimeDecomp::factors(int lst)
{
    std::vector <int> result;
    Prime_Decomp(lst, result);

    std::string res;
    int count = 1;

    for (int i = 1; i < result.size(); i++)
    {
        if (result[i] == result[i - 1])
        {
            count++;
        }
        else
        {
            if (count == 1)
                res += "(" + std::to_string(result[i - 1]) + ")";
            else
                res += "(" + std::to_string(result[i - 1]) + "**" + std::to_string(count) + ")";
            count = 1;
        }
    }

    if (count == 1)
        res += "(" + std::to_string(result[result.size() - 1]) + ")";
    else
        res += "(" + std::to_string(result[result.size() - 1]) + "**" + std::to_string(count) + ")";
    
    return res;
}