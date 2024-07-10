// https://leetcode.com/problems/unique-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: from bottom-right, move up or left till we reach 0,0; if obstacle in way, return 0
    // // TC: O(2^(m+n)) as we have 2 possibilities for each block and we do this for m+n blocks at a time
    // // SC: O(m+n) for recursion stack
    // int uniquePathsWithObstacles(vector<vector<int>>& og) {
    //     return uniquePathsWithObstaclesHelper(og.size()-1, og[0].size()-1, og);
    // }

    // int uniquePathsWithObstaclesHelper(int m, int n, vector<vector<int>>& og) {
    //     if(!m && !n) return 1;
    //     if(m<0 || n<0) return 0;
    //     if(og[m][n]==1) return 0;

    //     return uniquePathsWithObstaclesHelper(m-1, n, og) + uniquePathsWithObstaclesHelper(m, n-1, og);
    // }

    // ------------------------  //

    // // DP with memoization: remember possible values for each block instead of re-calculating
    // // TC: O(m*n) as we calc values for each block once
    // // SC: O(m+n) for recursion stack
    // int uniquePathsWithObstacles(vector<vector<int>> &og)
    // {
    //     int m = og.size();
    //     int n = og[0].size();

    //     if (og[0][0] == 1)
    //         return 0;
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return uniquePathsWithObstaclesHelper(m - 1, n - 1, og, dp);
    // }

    // int uniquePathsWithObstaclesHelper(int m, int n, vector<vector<int>> &og, vector<vector<int>> &dp)
    // {
    //     if (!m && !n)
    //         return 1;
    //     if (m < 0 || n < 0)
    //         return 0;

    //     if (dp[m][n] != -1)
    //         return dp[m][n];

    //     if (og[m][n] == 1)
    //         dp[m][n] = 0;
    //     else
    //         dp[m][n] = uniquePathsWithObstaclesHelper(m - 1, n, og, dp) + uniquePathsWithObstaclesHelper(m, n - 1, og, dp);

    //     return dp[m][n];
    // }

    // ------------------------------------- //

    // // DP with tabulation: bottom up
    // // TC: O(m*n) as we calc values for each block once
    // // SC: O(m*n) for storing values
    // int uniquePathsWithObstacles(vector<vector<int>> &og) {
    //     int m = og.size();
    //     int n = og[0].size();

    //     if (og[0][0] == 1)
    //         return 0;

    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     dp[0][0] = 1;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (og[i][j] == 1)
    //                 dp[i][j] = 0;
    //             else if (i && j)
    //                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //             else if (i)
    //                 dp[i][j] = dp[i - 1][j];
    //             else if (j)
    //                 dp[i][j] = dp[i][j - 1];
    //         }
    //     }

    //     return dp[m - 1][n - 1];
    // }

    // ------------------------------------- //

    // space-optimized DP
    // TC: O(m*n) as we calc values for each block once
    // SC: O(n) as we only require top row values
    int uniquePathsWithObstacles(vector<vector<int>> &og)
    {
        int m = og.size();
        int n = og[0].size();

        if (og[0][0] == 1)
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (og[i][j] == 1)
                    dp[j] = 0;
                else if (j)
                    dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
