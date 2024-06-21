// https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // s & t should have same length, same letters and same frequency of those letters
    // TC: O(N)
    // SC: O(N)
    // to handle unicode chars in i/p, we'll use umap instead of array[26]
    bool isAnagram(string s, string t)
    {
        int len1 = s.size(), len2 = t.size();
        if (len1 != len2)
            return 0;

        vector<int> freq(26, 0);
        for (int i = 0; i < len1; i++)
        {
            freq[(int)s[i] - 97]++;
            freq[(int)t[i] - 97]--;
        }

        for (int i = 0; i < 26; i++)
            if (freq[i] != 0)
                return false;

        return true;
    }
};
