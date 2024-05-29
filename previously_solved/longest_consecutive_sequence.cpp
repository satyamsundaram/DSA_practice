// problem link: https://leetcode.com/problems/longest-consecutive-sequence/
// 30.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: sort it and run a loop to check if an element is consecutive and check max length at each index
    // TC: O(nlogn)
    // SC: O(1)
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(!n) return 0;
    //     sort(nums.begin(), nums.end());
        
    //     int mx = 1, cnt = 1;
        
    //     for(int i=1; i<n; i++) {
    //         if(nums[i] == nums[i-1]) continue;
    //         else if(nums[i]-nums[i-1]==1) {
    //             cnt++;
    //             mx = max(mx, cnt);
    //         } else cnt=1;
    //     }
    //     return mx;
    // }

    // optimized: to find the LCS, we use an unordered_set and check if the current element is the start of a sequence
    // if yes, then we check the length of the sequence and update the max length else we continue
    // TC: O(n)
    // SC: O(n)
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_map<int, int> um;
        for(int num:nums) um[num]=0;
        int mx = 1;

        for(int num:nums) {
            // don't recheck duplicate numbers
            if(um[num]) continue;
            // check if num is the start of a sequence
            if(um.find(num-1) == um.end()) {
                int findNum = num+1, cnt = 1;
                while(um.find(findNum) != um.end()) {
                    cnt++;
                    findNum++;
                }
                mx = max(mx, cnt);
            }
            um[num]=1;
        }

        return mx;
    }
};