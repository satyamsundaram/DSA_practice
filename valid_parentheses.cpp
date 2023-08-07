// problem link: https://leetcode.com/problems/valid-parentheses/
// 7.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: if it's an opening bracket, push it into the stack; if it's a closing bracket check whether the top element of the stack is its opening
    // TC: O(n)
    // SC: O(n)
    bool isValid(string s) {
        stack<int> st;
        for(char c:s) {
            if(c==')') {
                if(st.size() && st.top()=='(') st.pop();
                else return 0;
            } else if(c=='}') {
                if(st.size() && st.top()=='{') st.pop();
                else return 0;
            } else if(c==']') {
                if(st.size() && st.top()=='[') st.pop();
                else return 0;
            } else st.push(c);
        }

        if(st.size()) return 0;
        return 1;
    }
};