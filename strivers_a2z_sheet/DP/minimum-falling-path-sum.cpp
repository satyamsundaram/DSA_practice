// https://leetcode.com/problems/minimum-falling-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // same as minimum sum in triangle only we have 3 possible moves at max
    // // TC: O(3^n)
    // // SC: O(n)
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size(), res = 1e5;
    //     for(int i=0; i<n; i++)
    //         res = min(res, minFallingPathSumHelper(matrix, n-1, i));
    //     return res;
    // }

    // int minFallingPathSumHelper(vector<vector<int>>& matrix, int row, int col) {
    //     if(!row) return matrix[row][col];
    //     else if(!col) return matrix[row][col] + min(minFallingPathSumHelper(matrix, row-1, col), minFallingPathSumHelper(matrix, row-1, col+1));
    //     else if(col==matrix.size()-1) return matrix[row][col] + min(minFallingPathSumHelper(matrix, row-1, col-1), minFallingPathSumHelper(matrix, row-1, col));
    //     else return matrix[row][col] + min(min(minFallingPathSumHelper(matrix, row-1, col-1), minFallingPathSumHelper(matrix, row-1, col)), minFallingPathSumHelper(matrix, row-1, col+1));
    // }

    // -----------------  //

    // // DP with memo
    // // TC: O(n^2)
    // // SC: O(n^2)
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size(), res = 1e5;
    //     vector<vector<int>> dp(n, vector<int>(n, 1e5));
    //     for(int i=0; i<n; i++)
    //         res = min(res, minFallingPathSumHelper(matrix, n-1, i, dp));
    //     return res;
    // }

    // int minFallingPathSumHelper(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
    //     if(dp[row][col] != 1e5) return dp[row][col];
    //     if(!row) dp[row][col] = matrix[row][col];
    //     else if(!col) dp[row][col] = matrix[row][col] + min(minFallingPathSumHelper(matrix, row-1, col, dp), minFallingPathSumHelper(matrix, row-1, col+1, dp));
    //     else if(col==matrix.size()-1) dp[row][col] = matrix[row][col] + min(minFallingPathSumHelper(matrix, row-1, col-1, dp), minFallingPathSumHelper(matrix, row-1, col, dp));
    //     else dp[row][col] = matrix[row][col] + min(min(minFallingPathSumHelper(matrix, row-1, col-1, dp), minFallingPathSumHelper(matrix, row-1, col, dp)), minFallingPathSumHelper(matrix, row-1, col+1, dp));

    //     return dp[row][col];
    // }

    // -----------------  //

    // // DP with tab
    // // TC: O(n^2)
    // // SC: O(n^2)
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size(), res = 1e5;
    //     vector<vector<int>> dp(n, vector<int>(n));
    //     for(int row=0; row<n; row++) {
    //         for(int col=0; col<n; col++) {
    //             if(!row) dp[row][col] = matrix[row][col];
    //             else if(!col) dp[row][col] = matrix[row][col] + min(dp[row-1][col], dp[row-1][col+1]);
    //             else if(col==n-1) dp[row][col] = matrix[row][col] + min(dp[row-1][col-1], dp[row-1][col]);
    //             else dp[row][col] = matrix[row][col] + min(min(dp[row-1][col-1], dp[row-1][col]), dp[row-1][col+1]);

    //             if(row==n-1) res = min(res, dp[row][col]);
    //         }
    //     }

    //     return res;
    // }

    // -----------------  //

    // DP with space optimization
    // TC: O(n^2)
    // SC: O(n)
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> dp(matrix[0].begin(), matrix[0].end());

        for (int row = 1; row < n; row++)
        {
            vector<int> current(n, 0);
            for (int col = 0; col < n; col++)
            {
                int minPrev = dp[col];
                if (col > 0)
                    minPrev = min(minPrev, dp[col - 1]);
                if (col < n - 1)
                    minPrev = min(minPrev, dp[col + 1]);

                current[col] = matrix[row][col] + minPrev;
            }

            dp = current;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
