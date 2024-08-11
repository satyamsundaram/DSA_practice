// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // use 2 pointers at start and end; if they match, check min steps for [i+1,j-1]
    // else get min([i+1,j], [i,j-1])
    // if they match add 0 to recursion ans; else add 1
    // base case is for 1 len strings
    // // TC: O(2^n)
    // // S : O(n)
    // int minInsertions(string s) {
    //     int n = s.size();
    //     return helper(s, 0, n-1);
    // }

    // int helper(string s, int i, int j) {
    //     if(i==j || i>j) return 0;
    //     if(s[i]==s[j]) return helper(s, i+1, j-1);
    //     else return 1 + min(helper(s, i+1, j), helper(s, i, j-1));
    // }

    // // ---------------------------------------------------- //

    // // dp with memo
    // // TC: O(n^2)
    // // S : O(n^2) + O(n)
    // int minInsertions(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return helper(s, 0, n-1, dp);
    // }

    // int helper(string s, int i, int j, vector<vector<int>> &dp) {
    //     if(i==j || i>j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i]==s[j]) dp[i][j] = helper(s, i+1, j-1, dp);
    //     else dp[i][j] = 1 + min(helper(s, i+1, j, dp), helper(s, i, j-1, dp));
    //     return dp[i][j];
    // }

    // // ---------------------------------------------------- //

    // // dp with tab
    // // TC: O(n^2)
    // // S : O(n^2)
    // int minInsertions(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
    //     for(int i=n-2; i>=0; i--) {
    //         for(int j=1; j<=n-1; j++) {
    //             if(i>j) continue;
    //             if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
    //             else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
    //         }
    //     }
    //     return dp[0][n-1];
    // }

    // ---------------------------------------------------- //

    // dp with space optim
    // TC: O(n^2)
    // S : O(n)
    int minInsertions(string s)
    {
        int n = s.size();
        vector<int> a(n, 0), b(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= n - 1; j++)
            {
                if (i > j)
                    continue;
                if (s[i] == s[j])
                    a[j] = b[j - 1];
                else
                    a[j] = 1 + min(b[j], a[j - 1]);
            }
            b = a;
        }
        return a[n - 1];
    }
};
