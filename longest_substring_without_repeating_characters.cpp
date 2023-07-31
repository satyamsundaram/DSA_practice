// problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 30.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // super naive: run 2 loops and for each [i,j] combination, check if all the chars in the range [i,j] are unique
    // TC: O(n^3)
    // SC: O(1)

    // bool isNonRepeating(int l, int r, string &s) {
    //     vector<int> chars(128);

    //     for(int i=l; i<=r; i++) {
    //         char c = s[i];
    //         if(chars[c]) return 0;
    //         chars[c]=1;
    //     }
    //     return 1;
    // }

    // int lengthOfLongestSubstring(string s) {
    //     int res = 0, n = s.size();
    //     if(!n) return res;
    //     res++;

    //     for(int i=0; i<n; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             if(isNonRepeating(i, j, s))
    //                 res = max(res, j-i+1);
    //         }
    //     }

    //     return res;
    // }

    //------------------------------------------------------------//

    // naive method: store idx->char as well as char->idx mapping
    // if we encounter a repeating char, we delete all the mappings from the previous index of the repeating char till an idx->char mapping exists going backwards and update count at the end
    // TC: O(n^2) > 10^9
    // SC: O(n)
    
    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char, int> um;
    //     unordered_map<int, char> um2;
    //     int mx = 0, cnt = 0;

    //     for(int i=0; i<s.size(); i++) {
    //         if(um.find(s[i]) == um.end()) {
    //             um[s[i]]=i;
    //             um2[i]=s[i];
    //             cnt++;
    //             mx = max(mx, cnt);
    //         } else {
    //             int idx = um[s[i]];
    //             for(int j=idx; j>=0; j--) {
    //                 if(um2.find(j) == um2.end()) break;
    //                 um.erase(um2[j]);
    //                 um2.erase(j);
    //             }
    //             um2[i]=s[i];
    //             um[s[i]]=i;
    //             cnt=i-idx;
    //         }
    //     }

    //     return mx;
    // }

    //---------------------------------------------------------------//
    
    // optimized: doing the same thing as above but much more optimally using only a sliding window; 
    // we increase the right pointer till we encounter unique chars; 
    // if we encounter a repeating char, we move the left pointer till the repeating char is no longer present in our window
    // TC: O(n)
    // SC: O(n)
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l=0, r=0, mx=0;
        while(r<s.size()) {
            if(charSet.find(s[r]) == charSet.end()) {
                charSet.insert(s[r]);
                mx = max(mx, r-l+1);
                r++;
            } else {
                charSet.erase(s[l]);
                l++;
            }
        }

        return mx;
    }
};