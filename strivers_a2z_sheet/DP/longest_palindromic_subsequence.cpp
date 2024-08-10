// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // naive is to get all subseq via recursion of pick/not-pick, check each for palindrome and store max length
    // TC & SC: O(2^n)

    // ---------------------------------------------------- //

    // // a better approach: we basically need to find the lcs b/w the given string and it's reverse
    // // TC: O(n^2)
    // // SC: O(n)
    // int longestPalindromeSubseq(string s) {
    //     string s2 = s;
    //     reverse(s2.begin(), s2.end());
    //     return longestCommonSubsequence(s, s2);
    // }

    // int longestCommonSubsequence(string text1, string text2)
    // {
    //     int m = text1.size(), n = text2.size();
    //     vector<int> prev(n + 1, 0), curr(n + 1, 0);
    //     for (int j = 0; j <= n; j++) {
    //         prev[j] = 0;
    //         curr[j] = 0;
    //     }

    //     for (int idx1 = 1; idx1 <= m; idx1++)
    //     {
    //         for (int idx2 = 1; idx2 <= n; idx2++)
    //         {
    //             if (text1[idx1 - 1] == text2[idx2 - 1])
    //                 curr[idx2] = 1 + prev[idx2 - 1];
    //             else
    //                 curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
    //         }
    //         prev = curr;
    //     }

    //     return curr[n];
    // }

    // --------------------------------------------------- //

    // // a diff approach: 2 pointers -> LCS b/w 2 strings but imagine the 2nd str is reversed and concat to the 1st
    // // TC: O(2^n)
    // // SC: O(n)
    // int longestPalindromeSubseq(string s) {
    //     return helper(s, 0, s.size()-1);
    // }

    // int helper(string s, int i, int j) {
    //     if(i>j) return 0;
    //     if(i==j) return 1;
    //     if(s[i]==s[j]) return 2 + helper(s, i+1, j-1);
    //     else return max(helper(s, i+1, j), helper(s, i, j-1));
    // }

    // // -------------------------------------------------- //

    // // dp with memo
    // // TC: O(n^2)
    // // SC: O(n^2) + O(n)
    // int longestPalindromeSubseq(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n, vector<int> (n, -1));
    //     return helper(s, 0, n-1, dp);
    // }

    // int helper(string s, int i, int j, vector<vector<int>> &dp) {
    //     if(i>j) return 0;
    //     if(i==j) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i]==s[j]) dp[i][j] = 2 + helper(s, i+1, j-1, dp);
    //     else dp[i][j] = max(helper(s, i+1, j, dp), helper(s, i, j-1, dp));
    //     return dp[i][j];
    // }

    // // -------------------------------------------------- //

    // // dp with memo
    // // TC: O(n^2)
    // // SC: O(n^2) + O(n)
    // int longestPalindromeSubseq(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n, vector<int> (n, -1));
    //     return helper(s, 0, n-1, dp);
    // }

    // int helper(string s, int i, int j, vector<vector<int>> &dp) {
    //     if(i>j) return 0;
    //     if(i==j) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i]==s[j]) dp[i][j] = 2 + helper(s, i+1, j-1, dp);
    //     else dp[i][j] = max(helper(s, i+1, j, dp), helper(s, i, j-1, dp));
    //     return dp[i][j];
    // }

    // -------------------------------------------------- //

    // dp with tabu
    // TC: O(n^2)
    // SC: O(n^2)
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; i++)
            dp[i][i] = 1;

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                if (s[i - 1] == s[j - 1])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }
};
