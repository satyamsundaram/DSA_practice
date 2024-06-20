// https://leetcode.com/problems/largest-odd-number-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // find the first odd number from the right, return substr
    // TC: O(n)
    // SC: O(1)
    string largestOddNumber(string num)
    {
        int len = num.size();
        for (int i = len - 1; i >= 0; i--)
        {
            if ((int)num[i] % 2)
                return num.substr(0, i + 1);
        }

        return "";
    }
};
