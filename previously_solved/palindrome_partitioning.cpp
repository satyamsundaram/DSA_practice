// problem link: https://leetcode.com/problems/palindrome-partitioning/
// 24.6.2023 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while(l<r) {
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }

    void helper(int idx, string s, vector<string> &v, vector<vector<string>> &res) {
        int n = s.size();
        if(idx==n) {
            res.push_back(v);
            return;
        }

        for(int i=idx; i<n; i++) {
            if(isPalindrome(s, idx, i)) {
                v.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, v, res);
                v.pop_back();
            }
        }
    }

    // method: using a for loop, we go level by level but at each level, we go to the depth using recursion. At each level, before partitioning, we check if the current partition produces a palindrome in the string before the partition. If yes, then we call recursion to do the same with the string after the palindrome. If no, then the for loop proceeds further.
    // TC: O(n*t) where t is the no. of partitions possible
    // SC: O(t*x) where x is the avg length of a partition vector
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        helper(0, s, v, res);
        return res;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string &s) {
//         int l = 0, r = s.size()-1;
//         while(l<r) {
//             if(s[l++] != s[r--])
//                 return 0;
//         }
//         return 1;
//     }

//     // backtrack: take / not take
//     // TC: O(2^n * n) [2^n to get all substrings and n to check palindrome]
//     // SC: O(2^n to store all substrings)
//     void helper(int i, string &s, string str, vector<string> &v, vector<vector<string>> &res) {
//         int n = s.size();

//         if(i==n) {
//             res.push_back(v);
//             return;
//         }

//         str += s[i];

//         // partition here
//         if(isPalindrome(str)) {
//             v.push_back(str);
//             helper(i+1, s, "", v, res);
//             v.pop_back();
//         }

//         // don't partition here
//         if(i != n-1)
//             helper(i+1, s, str, v, res);
        
//     }

//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         string str = "";
//         vector<string> v;
//         helper(0, s, str, v, res);
//         return res;
//     }
// };