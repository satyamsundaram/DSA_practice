// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // possible solution: generate all subsequences for both strings and store them in 2 unordered sets; compare 2 unordered sets and find max length of common subsequence
    // // TC & SC: O(2^n + 2^m) to generate all subseq
    // int longestCommonSubsequence(string text1, string text2)
    // {
    //     unordered_set<string> us1, us2;
    //     get_all_subseq(text1, us1, 0, "");
    //     get_all_subseq(text2, us2, 0, "");

    //     int res = 0;
    //     for (auto i = us1.begin(); i != us1.end(); i++)
    //     {
    //         if (us2.find(*i) != us2.end())
    //             res = max(res, (int)i->size());
    //     }

    //     return res;
    // }

    // void get_all_subseq(string text, unordered_set<string> &us, int idx, string s)
    // {
    //     if (idx == text.size() - 1)
    //     {
    //         us.insert(s + text[idx]);
    //         us.insert(s);
    //         return;
    //     }

    //     get_all_subseq(text, us, idx + 1, s + text[idx]);
    //     get_all_subseq(text, us, idx + 1, s);
    // }

    // ------------------------------------------------------ //

    // // recursion and find on the way: match/non-match
    // // TC: O(2^(m+n))
    // // SC: O(m+n) for rec stack
    // int longestCommonSubsequence(string text1, string text2) {
    //     return get_lcs(text1, text2, text1.size()-1, text2.size()-1);
    // }

    // int get_lcs(string &text1, string &text2, int idx1, int idx2) {
    //     if(idx1<0 || idx2<0) return 0;

    //     if(text1[idx1] == text2[idx2])
    //         return 1 + get_lcs(text1, text2, idx1-1, idx2-1);
    //     else
    //         return max(get_lcs(text1, text2, idx1-1, idx2), get_lcs(text1, text2, idx1, idx2-1));
    // }

    // // ----------------------------------------------------- //

    // // dp with memo
    // // TC: O(m*n)
    // // SC: O(m*n) + O(m+n) (recursion stack)
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size(), n = text2.size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return get_lcs(text1, text2, m-1, n-1, dp);
    // }

    // int get_lcs(string &text1, string &text2, int idx1, int idx2, vector<vector<int>> &dp) {
    //     if(idx1<0 || idx2<0) return 0;

    //     if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    //     if(text1[idx1] == text2[idx2])
    //         dp[idx1][idx2] = 1 + get_lcs(text1, text2, idx1-1, idx2-1, dp);
    //     else
    //         dp[idx1][idx2] = max(get_lcs(text1, text2, idx1-1, idx2, dp), get_lcs(text1, text2, idx1, idx2-1, dp));

    //     return dp[idx1][idx2];
    // }

    // // ----------------------------------------------------- //

    // dp with tabu
    // TC: O(m*n)
    // SC: O(m*n)
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size(), n = text2.size();
    //     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    //     for(int j=0; j<=n; j++) dp[0][j] = 0;
    //     for(int i=0; i<=m; i++) dp[i][0] = 0;
        
    //     for(int idx1=1; idx1<=m; idx1++) {
    //         for(int idx2=1; idx2<=n; idx2++) {
    //             if(text1[idx1-1] == text2[idx2-1])
    //                 dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
    //             else
    //                 dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
    //         }
    //     }

    //     return dp[m][n];
    // }

    // ----------------------------------------------------- //

    // dp with space optim
    // TC: O(m*n)
    // SC: O(n)
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int j = 0; j <= n; j++) {
            prev[j] = 0;
            curr[j] = 0;
        }

        for (int idx1 = 1; idx1 <= m; idx1++)
        {
            for (int idx2 = 1; idx2 <= n; idx2++)
            {
                if (text1[idx1 - 1] == text2[idx2 - 1])
                    curr[idx2] = 1 + prev[idx2 - 1];
                else
                    curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
            }
            prev = curr;
        }

        return curr[n];
    }
};
