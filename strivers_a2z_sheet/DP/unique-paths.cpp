// https://leetcode.com/problems/unique-paths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // recursively move down or right if possible, return 1 if we reach end, 0 if we go out of bounds
    // // TC: O(2^(m+n)) as for each position, we have 2 steps possible
    // // SC: O(m+n) for recursion stack
    // int uniquePaths(int m, int n) {
    //     if(m==1 || n==1) return 1;
    //     return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    // }

    //--------------------------------------------//

    // // // DP with memoization: instead of calculating the same values at any position, save and reuse it
    // // // TC: O(m*n) as we calculate values for all positions once
    // // // SC: O(m*n) for storing values and recursion stack
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    //     return uniquePathsHelper(m, n, dp);
    // }

    // int uniquePathsHelper(int m, int n, vector<vector<int>>& dp) {
    //     if(m==1 || n==1) return 1;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     dp[m][n] = uniquePathsHelper(m-1, n, dp) + uniquePathsHelper(m, n-1, dp);
    //     return dp[m][n];
    // }

    //--------------------------------------------//

    // // DP with tabulation: bottom up
    // // TC: O(m*n) as we calculate values for all positions once
    // // SC: O(m*n) for storing values
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 1));
    //     for(int i=1; i<m; i++) {
    //         for(int j=1; j<n; j++) {
    //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    //--------------------------------------------//

    // space-optimized DP
    // TC: O(m*n) as we calculate values for all positions once
    // SC: O(n) as we only need top row's values; 1st col and 1st row values will all be 1
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
