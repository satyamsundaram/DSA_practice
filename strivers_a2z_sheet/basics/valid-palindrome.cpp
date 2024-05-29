// https://leetcode.com/problems/valid-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     bool isValidAlnum(char c) {
    //         if(c>=48 && c<=57) return 1;
    //         if(c>=65 && c<=90) return 1;
    //         if(c>=97 && c<=122) return 1;
    //         return 0;
    //     }

public:
    // TC: O(N)
    // SC: O(N)
    // bool isPalindrome(string s) {
    //     string cpy = "";
    //     for(int i=0; i<s.size(); i++)
    //         if(isValidAlnum(s[i])) cpy += tolower(s[i]);

    //     int i=0, j=cpy.size()-1;
    //     while(i<j)
    //         if(cpy[i++]!=cpy[j--]) return 0;

    //     return 1;
    // }

    // TC: O(N)
    // SC: O(1)
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            while (!isalnum(s[i]) && i < j)
                i++;
            while (!isalnum(s[j]) && i < j)
                j--;
            if (tolower(s[i]) != tolower(s[j]))
                return 0;
        }
        return 1;
    }
};