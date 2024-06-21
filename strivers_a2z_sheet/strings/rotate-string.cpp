// https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // find 1st char of goal in s, check if it matches till end of s
    // then match start of s till where we'd previously stopped in goal due to s' end
    // TC: O(N)
    // SC: O(1)
    bool rotateString(string s, string goal)
    {
        int len1 = s.size(), len2 = goal.size();
        if (len1 != len2)
            return false;

        int start = 0, i;
        for (i = 0; i < len1; i++)
        {
            if (s[i] == goal[0])
            {
                bool res = isRotation(s, goal, i, start);
                if (res)
                    return res;
            }
        }

        return false;
    }

    bool isRotation(string s, string goal, int i, int start)
    {
        int len1 = s.size(), len2 = goal.size();

        for (i; i < len1; i++, start++)
            if (s[i] != goal[start])
                return false;

        i = 0;
        for (start; start < len2; start++, i++)
            if (s[i] != goal[start])
                return false;

        return true;
    }
};
