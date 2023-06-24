// problem link: https://leetcode.com/problems/permutation-sequence/
// 24.6.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     void helper(int idx, string &s, vector<string>& v) {
//         int n = s.size();
//         if(idx == n-1) {
//             v.push_back(s);
//             return;
//         }

//         for(int i=idx; i<n; i++) {
//             swap(s[i], s[idx]);  
//             helper(idx+1, s, v);
//             swap(s[i], s[idx]);  
//         }
//     }

//     // naive TLE: generate all perms, sort it and return kth perm
//     // TC: O(n! * n) + O(n! * log(n!))
//     // SC: O(n! * n)
//     string getPermutation(int n, int k) {
//         string s = "";
//         vector<string> v;
//         for(int i=1; i<=n; i++)
//             s += to_string(i);
//         helper(0, s, v);
//         sort(v.begin(), v.end());
//         return v[k-1];
//     }
// };

class Solution {
public:
    // TC: O(n*n)
    // SC: O(n)
    string getPermutation(int n, int k) {
        int fact = 1, d;
        string res = "";
        vector<int> v;

        for(int i=1; i<n; i++) {
            fact *= i;
            v.push_back(i);
        }
        v.push_back(n);

        k--;
        while(1) {
            n--;
            d = k/fact;
            res += to_string(v[d]);
            v.erase(v.begin()+d);
            if(v.empty()) break;
            k %= fact;
            fact /= n;
        }
        return res;
    }
};