// https://leetcode.com/problems/remove-k-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // we can use remove/not remove until k exhausts for each i, and check which combination's string is smallest lexicographically (after removing leading 0s) (to remove we can make the char as 'a' & the rest will form new string)
    // string removeKdigits(string num, int k) {
    //     return helper(num, 0, k);
    // }

    // // TC: O(2^n)
    // // SC: O(1)
    // string helper(string num, int idx, int k) {
    //     if(!k || idx >= num.size()) return num;

    //     // remove
    //     int n = num.size();
    //     char prev = num[idx];
    //     num[idx] = 'a';
    //     string rm = helper(num, idx+1, k-1);
    //     string rmf = getFinalString(rm);

    //     // not remove
    //     num[idx] = prev;
    //     string nrm = helper(num, idx+1, k);
    //     string nrmf = getFinalString(nrm);

    //     return smallerOf(rmf, nrmf);
    // }

    // string getFinalString(string num) {
    //     int n = num.size();

    //     string temp = "";
    //     for(int i=0; i<n; i++)
    //         if(num[i] != 'a') temp += num[i];

    //     int i=0;
    //     while(temp[i] == '0') i++;
    //     temp = temp.substr(i, n-i);
    //     return temp == "" ? "0" : temp;
    // }

    // string smallerOf(string a, string b) {
    //     int n1 = a.size(), n2 = b.size();
    //     if(n1<n2) return a;
    //     else if(n1>n2) return b;
    //     return a < b ? a : b;
    // }

    // // ------------------------------------ //

    // // DP: memoization => giving wrong answer
    // string removeKdigits(string num, int k) {
    //     int n = num.size();
    //     vector<vector<string>> dp(n, vector<string>(k+1, "b"));
    //     return helper(num, 0, k, dp);
    // }

    // // TC: O(n^2)
    // // SC: O(n^2)
    // string helper(string num, int idx, int k, vector<vector<string>> &dp) {
    //     int n = num.size();
    //     if(!k || idx >= num.size()) return num;
    //     if(dp[idx][k] != "b") return dp[idx][k];

    //     // remove
    //     char prev = num[idx];
    //     num[idx] = 'a';
    //     string rm = helper(num, idx+1, k-1, dp);
    //     string rmf = getFinalString(rm);

    //     // not remove
    //     num[idx] = prev;
    //     string nrm = helper(num, idx+1, k, dp);
    //     string nrmf = getFinalString(nrm);

    //     dp[idx][k] = smallerOf(rmf, nrmf);
    //     return dp[idx][k];
    // }

    // string getFinalString(string num) {
    //     int n = num.size();

    //     string temp = "";
    //     for(int i=0; i<n; i++)
    //         if(num[i] != 'a') temp += num[i];

    //     int i=0;
    //     while(temp[i] == '0') i++;
    //     temp = temp.substr(i, n-i);
    //     return temp == "" ? "0" : temp;
    // }

    // string smallerOf(string a, string b) {
    //     int n1 = a.size(), n2 = b.size();
    //     if(n1<n2) return a;
    //     else if(n1>n2) return b;
    //     return a < b ? a : b;
    // }

    // ---------------------------------------- //

    // using stack to store seq of digits and smallest number using greedy approach where we pop the top of stack if it's greater than curr element while iterating from 0 to n-1 in nums
    // TC & SC: O(n)

    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (k == n)
            return "0";

        stack<char> st;

        for (char digit : num)
        {
            while (!st.empty() && st.top() > digit && k > 0)
            {
                st.pop();
                k--;
            }

            st.push(digit);
        }

        // if k>0, pop from back because if front was bigger, we would have popped it already above, eg: 1234
        while (k > 0)
        {
            st.pop();
            k--;
        }

        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = pos == string::npos ? "0" : result.substr(pos);

        return result;
    }
};
