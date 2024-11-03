// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n1 * n2)
    int strStr(string hay, string nee)
    {
        int i = 0, n1 = hay.size(), n2 = nee.size(), j = 0;
        while (i < n1)
        {
            int res = -1, t = i;
            while (j < n2 && t < n1 && nee[j] == hay[t])
            {
                if (res == -1)
                    res = t;
                j++;
                t++;
            }
            if (j == n2)
                return res;
            i++;
            j = 0;
        }

        return -1;
    }
};
