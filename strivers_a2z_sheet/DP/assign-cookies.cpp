// https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(NlogN); SC: O(1)
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, m = g.size(), n = s.size(), res = 0;
        while (i < m && j < n)
        {
            if (s[j] < g[i])
                j++;
            else
            {
                i++;
                j++;
                res++;
            }
        }

        return res;
    }
};
