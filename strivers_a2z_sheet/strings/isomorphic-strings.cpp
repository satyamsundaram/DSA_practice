// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // use an unordered_map to store character mappings; if a mapping is already present, don't overwrite it, after getting all mappings; convert s to t; check if they are equal
    // TC: O(n) to get mappings or convert s to t or to check if they are equal
    // SC: O(n) to store mappings
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> um, um2;
        int len1 = s.size();

        for (int i = 0; i < len1; i++)
        {
            if (um.find(s[i]) == um.end())
                um[s[i]] = t[i];
            else if (um[s[i]] != t[i])
                return false;

            if (um2.find(t[i]) == um.end())
                um2[t[i]] = s[i];
            else if (um2[t[i]] != s[i])
                return false;
        }

        return true;
    }
};
