// https://leetcode.com/problems/palindrome-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(N)
    bool isPalindrome(int x)
    {
        if (x < 0)
            return 0;
        string s = "";
        while (x)
        {
            s += x % 10 + '0';
            x /= 10;
        }

        int l = 0, r = s.size() - 1;
        while (l < r)
            if (s[l++] != s[r--])
                return 0;
        return 1;
    }
};