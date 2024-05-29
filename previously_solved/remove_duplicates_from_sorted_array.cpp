// problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// 5.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: use an unordered_set to check if an element has already been placed correctly or not
    // TC: O(n)
    // SC: O(n)
    // int removeDuplicates(vector<int>& nums) {
    //     unordered_set<int> us;
    //     int i=0;
    //     for(int n:nums) {
    //         if(us.find(n) == us.end()) {
    //             nums[i++]=n;
    //             us.insert(n);
    //         }
    //     }
    //     return us.size();
    // }

    //-------------------------------------------------------//

    // optimized: take advantage of the fact that nums is non-decreasing
    // TC: O(n)
    // SC: O(1)
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==nums[i-1]) continue;
            else nums[idx++]=nums[i];
        }
        return idx;
    }
};