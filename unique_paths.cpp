// problem link: https://leetcode.com/problems/unique-paths/
// 29-07-2023 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: recursion
    // TC: exponential as we explore all possible paths which will have overlapping subproblems
    // SC: O(1)
    // int uniquePaths(int m, int n) {
    //     // only one path to reach any cell in first row or first col
    //     if(m==1 || n==1) return 1;  
    //     // else no. of paths = no. of paths to above cell + no. of paths to left cell
    //     return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    // }

    // // method: dp (memoization)
    // // TC: O(m*n)
    // // SC: O(m*n)
    // int uniquePaths(int m, int n) {
    //     // only one path to reach any cell in first row or first col
    //     vector<vector<int>> dp(m, vector<int> (n, 1));

    //     // else no. of paths = no. of paths to above cell + no. of paths to left cell
    //     for(int i=1; i<m; i++) {
    //         for(int j=1; j<n; j++) {
    //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }

    // method: dp + space optimization since we only need the values from the above row's corresponding cell and the immediate left cell to compute the current cell's value
    // all the other left cells' values have no reason to be remembered, hence we can overwrite the values in the same 1-d vector
    // TC: O(m*n)
    // SC: O(n)
    int uniquePaths(int m, int n) {
        // only one way to reach any cell in the first row
        vector<int> dp(n, 1);

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[j]+=dp[j-1];
            }
        }

        return dp[n-1];
    }
};