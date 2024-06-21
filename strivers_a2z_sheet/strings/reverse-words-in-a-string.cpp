// https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // iterate from back, use pointers to keep track of start and end of words, ignore all spaces but one
    // TC: O(N) to iterate thru entire string backwards
    // SC: O(N) to store res
    string reverseWords(string s)
    {
        string res = "";
        int len = s.size(), end = len - 1, start;

        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && i && s[i - 1] != ' ')
                end = i - 1;
            else if (s[i] != ' ' && i && s[i - 1] == ' ')
            {
                start = i;
                res += s.substr(start, end - start + 1);
                res += " ";
            }
        }

        if (s[0] != ' ')
        {
            res += s.substr(0, end + 1);
            return res;
        }
        return res.substr(0, res.size() - 1);
    }
};
