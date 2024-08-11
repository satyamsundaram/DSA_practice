// https://leetcode.com/problems/delete-operation-for-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // to minimise no. of steps to make the 2 strings equal, we want to first find the max no. of chars that are same in both so that we can leave them as they are; we need to do this given we can't change the chars order, hence, we need to find the length of lcs; then just remove the rest of chars from each word
    // str1_size-len_lcs + str2_size-len_lcs
    // TC: O(n^2)
    // SC: O(n)
    int minDistance(string word1, string word2)
    {
        int len_lcs = longestCommonSubsequence(word1, word2);
        return word1.size() - len_lcs + word2.size() - len_lcs;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int j = 0; j <= n; j++)
        {
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
