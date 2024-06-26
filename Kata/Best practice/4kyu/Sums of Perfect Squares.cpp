#include <cmath>
#include <vector>

int sum_of_squares(int n)
{
    // establish a list of perfect squares according to n
    std::vector <int> PerfectSquares;

    int Max_Square = sqrt(n);
    for(int i = 1; i <= Max_Square; i++)
        PerfectSquares.push_back(i * i);
    
    // using dynamic programming to find the minimum number of perfect squares that sum to n
    std::vector <int> dp(n + 1, n);// initialize dp[i] to n for all i
    // dp[i] means the minimum number of perfect squares that sum to i

    dp[0] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = PerfectSquares.size() - 1; j >= 0; j--)
            if(i >= PerfectSquares[j])
                dp[i] = std::min(dp[i], dp[i - PerfectSquares[j]] + 1);

    return dp[n];
}