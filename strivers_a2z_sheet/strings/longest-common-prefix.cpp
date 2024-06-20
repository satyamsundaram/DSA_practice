// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // check 2 strings at a time; check next string with previous 2 strings common prefix
    // TC: O(n*max(string size))
    // SC: O(n)
    string longestCommonPrefix(vector<string> &strs)
    {
        string common = strs[0];
        int len = strs.size();

        for (int i = 1; i < len && common.size(); i++)
        {
            int j = 0, sz1 = common.size(), sz2 = strs[i].size();
            while (j < sz1 && j < sz2 && strs[i][j] == common[j])
                j++;
            common = common.substr(0, j);
        }

        return common;
    }
};
