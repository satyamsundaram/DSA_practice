// problem link: https://leetcode.com/problems/maximum-subarray/
// 16.7.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: brute force: O(n^2)
    // int maxSubArray(vector<int>& nums) {
    //     int mx = INT_MIN, sum;
    //     for(int i=0; i<nums.size(); i++) {
    //         sum = nums[i];
    //         mx = max(sum, mx);
    //         for(int j=i+1; j<nums.size(); j++) {
    //             sum += nums[j];
    //             mx = max(sum, mx);
    //         }
    //     }
    //     return mx;
    // }

    // method: prev sum will only be added if on adding it to the current element makes the total greater than it, aka prev sum is greater than 0
    // calc max at each step
    // TC: O(n)
    // SC: O(1)
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], sum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            sum = nums[i] + (sum>0 ? sum : 0);
            mx = max(sum, mx);
        }
        return mx;
    }
};