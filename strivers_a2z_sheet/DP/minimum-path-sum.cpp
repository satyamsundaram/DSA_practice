// https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive recursion: we need to explore all paths
    // // TC: O(2^(m+n))
    // // SC: O(m+n)
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size();
    //     return minPathSumHelper(m-1, n-1, grid);
    // }

    // int minPathSumHelper(int i, int j, vector<vector<int>>& grid) {
    //     if(!i && !j) return grid[0][0];
    //     if(!i) return grid[i][j] + minPathSumHelper(i, j-1, grid);
    //     if(!j) return grid[i][j] + minPathSumHelper(i-1, j, grid);
    //     return grid[i][j] + min(minPathSumHelper(i-1, j, grid), minPathSumHelper(i, j-1, grid));
    // }

    // -------------------------- //

    // // DP with memoization: calc min path sum for each block only once
    // // TC: O((m*n) to calc for entire grid
    // // SC: O(m*n) to store values for entire grid
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     dp[0][0] = grid[0][0];
    //     return minPathSumHelper(m-1, n-1, grid, dp);
    // }

    // int minPathSumHelper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(!i) dp[i][j] = grid[i][j] + minPathSumHelper(i, j-1, grid, dp);
    //     else if(!j) dp[i][j] = grid[i][j] + minPathSumHelper(i-1, j, grid, dp);
    //     else dp[i][j] = grid[i][j] + min(minPathSumHelper(i-1, j, grid, dp), minPathSumHelper(i, j-1, grid, dp));

    //     return dp[i][j];
    // }

    // -------------------------- //

    // // DP with tabulation: calc min path sum for each block only once
    // // TC: O((m*n) to calc for entire grid
    // // SC: O(m*n) to store values for entire grid
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));

    //     for(int i=0; i<m; i++) {
    //         for(int j=0; j<n; j++) {
    //             if(!i && !j) dp[i][j] = grid[i][j];
    //             else if(!i) dp[i][j] = grid[i][j] + dp[i][j-1];
    //             else if(!j) dp[i][j] = grid[i][j] + dp[i-1][j];
    //             else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // -------------------------- //

    // space-optimized DP: we only need top row values at a time
    // TC: O((m*n) to calc for entire grid
    // SC: O(n)
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, -1);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!i && !j)
                    dp[j] = grid[i][j];
                else if (!i)
                    dp[j] = grid[i][j] + dp[j - 1];
                else if (!j)
                    dp[0] += grid[i][j];
                else
                    dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        return dp[n - 1];
    }
};
