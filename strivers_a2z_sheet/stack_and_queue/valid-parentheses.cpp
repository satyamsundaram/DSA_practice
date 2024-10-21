// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // SC & TC: O(n) => using stack, we insert all opening brackets in order, when we encounter a closing bracket, we check top of stack to check if the closing bracket is correct in order, if yes, we pop and move ahead, else return false
    bool isValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (st.empty())
                return false;
            else
            {
                if (s[i] == ')' && st.top() != '(')
                    return false;
                else if (s[i] == '}' && st.top() != '{')
                    return false;
                else if (s[i] == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
