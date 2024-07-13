// https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // recursion as we'll have to explore all paths to find minimum path sum. as we explore, for many indexes, with naive recursion, we'll be calculating values more than once, so we can use DP to optimize that
    // // TC: O(n*2^n) for for loop * 2 choices at each step
    // // SC: O(n) for recursion stack
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int rows = triangle.size(), res = INT_MAX;
    //     for(int i=0; i<triangle[rows-1].size(); i++)
    //         res = min(res, minimumTotalHelper(triangle, rows-1, i));
    //     return res;
    // }

    // int minimumTotalHelper(vector<vector<int>>& triangle, int row, int col) {
    //     if(!row) return triangle[row][col];
    //     else if(!col) return triangle[row][col] + minimumTotalHelper(triangle, row-1, col);
    //     else if(row==col) return triangle[row][col] + minimumTotalHelper(triangle, row-1, col-1);
    //     else return triangle[row][col] + min(minimumTotalHelper(triangle, row-1, col-1), minimumTotalHelper(triangle, row-1, col));
    // }

    // --------------------------- //

    // // DP with memoization
    // // TC: O(n^2) for for loop * recursion stack
    // // SC: O(n^2) for dp (n*(n+1)/2 to be precise)
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int rows = triangle.size(), res = INT_MAX;
    //     vector<vector<int>> dp = triangle;

    //     for(int i=1; i<rows; i++) {
    //         for(int j=0; j<=i; j++)
    //             dp[i][j] = 1e7;
    //     }

    //     for(int i=0; i<triangle[rows-1].size(); i++)
    //         res = min(res, minimumTotalHelper(triangle, rows-1, i, dp));
    //     return res;
    // }

    // int minimumTotalHelper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
    //     if(dp[row][col] != 1e7) return dp[row][col];
    //     else if(!row) dp[row][col] = triangle[row][col];
    //     else if(!col) dp[row][col] = triangle[row][col] + minimumTotalHelper(triangle, row-1, col, dp);
    //     else if(row==col) dp[row][col] = triangle[row][col] + minimumTotalHelper(triangle, row-1, col-1, dp);
    //     else dp[row][col] = triangle[row][col] + min(minimumTotalHelper(triangle, row-1, col-1, dp), minimumTotalHelper(triangle, row-1, col, dp));

    //     return dp[row][col];
    // }

    // --------------------------- //

    // // DP with tabulation
    // // TC: O(n^2) nested for loops
    // // SC: O(n^2) for dp
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int rows = triangle.size(), res = INT_MAX;
    //     vector<vector<int>> dp = triangle;

    //     for(int row=0; row<rows; row++) {
    //         for(int col=0; col<=row; col++) {
    //             if(!row) dp[row][col] = triangle[row][col];
    //             else if(!col) dp[row][col] = triangle[row][col] + dp[row-1][col];
    //             else if(row==col) dp[row][col] = triangle[row][col] + dp[row-1][col-1];
    //             else dp[row][col] = triangle[row][col] + min(dp[row-1][col-1], dp[row-1][col]);

    //             if(row==rows-1) res = min(res, dp[row][col]);
    //         }
    //     }

    //     return res;
    // }

    // --------------------------- //

    // DP with space optimized
    // TC: O(n^2) nested for loops
    // SC: O(n) for dp
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int rows = triangle.size(), res = INT_MAX;
        vector<int> dp(rows, 0);

        for (int row = 0; row < rows; row++)
        {
            for (int col = row; col >= 0; col--)
            {
                if (!row)
                    dp[col] = triangle[row][col];
                else if (!col)
                    dp[col] = triangle[row][col] + dp[col];
                else if (row == col)
                    dp[col] = triangle[row][col] + dp[col - 1];
                else
                    dp[col] = triangle[row][col] + min(dp[col - 1], dp[col]);

                if (row == rows - 1)
                    res = min(res, dp[col]);
            }
        }

        return res;
    }
};
