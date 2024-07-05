// https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // naive: rob current house and move to next to next house, else leave current house and move to next house; if nums length surpassed, robbed amount = 0
    // // TC: O(2^n) (for each house, 2 options: rob or not rob, hence exponential as each subproblem is calculated each time)
    // // SC: O(n) (recursive call stack)
    // int rob(vector<int>& nums) {
    //     return rob_recursive(nums, 0);
    // }

    // int rob_recursive(vector<int> &nums, int index) {
    //     if(index >= nums.size()) return 0;
    //     return max(nums[index] + rob_recursive(nums, index+2), rob_recursive(nums, index+1));
    // }

    //-----------------------------------------------------//

    // // DP: memoization
    // // TC: O(n) as each subproblem is only calculated once
    // // SC: O(n) memoization vector and recursion call stack
    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size()+2, -1);
    //     return rob_recursive(nums, 0, dp);
    // }

    // int rob_recursive(vector<int>& nums, int index, vector<int>& dp) {
    //     if(index >= nums.size()) return 0;
    //     if(dp[index] != -1) return dp[index];
    //     dp[index] = max(nums[index] + rob_recursive(nums, index+2, dp), rob_recursive(nums, index+1, dp));
    //     return dp[index];
    // }

    //-----------------------------------------------------//

    // // DP: tabulation
    // // TC: O(n) as we iterate through the loop once
    // // SC: O(n) tabulation vector
    // int rob(vector<int>& nums) {
    //     int len = nums.size();
    //     if(len==1) return nums[0];
    //     if(len==2) return max(nums[0], nums[1]);

    //     vector<int> dp(nums.size(), -1);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);

    //     for(int i=2; i<len; i++)
    //         dp[i] = max(nums[i] + dp[i-2], dp[i-1]);

    //     return dp[len-1];
    // }

    //-----------------------------------------------------//

    // DP: space optimized tabulation as we only need last 2 values at any point in time
    // TC: O(n) as we iterate through the loop once
    // SC: O(1)
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==1) return nums[0];
        if(len==2) return max(nums[0], nums[1]);

        int a = nums[0], b = max(nums[0], nums[1]), c;

        for(int i=2; i<len; i++) {
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }

        return c;
    }
};
