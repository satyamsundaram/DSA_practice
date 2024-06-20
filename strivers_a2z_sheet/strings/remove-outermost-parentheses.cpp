// https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // find a primitive block using a stack, remove outer () and append to res
    // // TC: O(n^2) -> check for primitive block using stack (push & pop)
    // // SC: O(n) for res
    // string removeOuterParentheses(string s) {
    //     int len = s.size(), i=0, l=-1, r=-1;
    //     stack<char> st;
    //     string res = "";

    //     while(i<len) {
    //         st.push(s[i++]);
    //         l = i;

    //         while(!st.empty()) {
    //             if(s[i] == ')') st.pop();
    //             else st.push(s[i]);
    //             i++;
    //         }
    //         r = i-1;

    //         for(int j=l; j<r; j++)
    //             res += s[j];
    //     }

    //     return res;
    // }

    // find a primitive block without a stack, use substr to append to res
    // TC: O(n) -> check for primitive block with integers only
    // SC: O(n) for res
    string removeOuterParentheses(string s)
    {
        int start = 0, balance = 0, len = s.size();
        string res = "";

        for (int i = 0; i < len; i++)
        {
            if (!balance)
                start = i;

            if (s[i] == '(')
                balance++;
            else
                balance--;

            if (!balance)
                res += s.substr(start + 1, i - start - 1);
        }

        return res;
    }
};
