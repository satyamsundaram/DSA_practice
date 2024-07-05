// https://leetcode.com/problems/house-robber-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: either can rob from house 0 to n-2; or from 1 to n-1; hence max of 2 house-robber problems
    // // TC: O(2^n)
    // // SC: O(n)
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1) return nums[0];
    //     int x = rob_recursive(nums, 0, n-2);
    //     int y = rob_recursive(nums, 1, n-1);
    //     return max(x, y);
    // }

    // int rob_recursive(vector<int>& nums, int index, int end) {
    //     if(index > end) return 0;
    //     return max(nums[index] + rob_recursive(nums, index+2, end), rob_recursive(nums, index+1, end));
    // }

    //----------------------------------------------//

    // // DP (memoization): save the results for overlapping problems to prevent calculating again
    // // TC: O(n)
    // // SC: O(n)
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1) return nums[0];

    //     vector<int> dp(n+1, -1);
    //     int x = rob_recursive(nums, 0, n-2, dp);

    //     fill(dp.begin(), dp.end(), -1);
    //     int y = rob_recursive(nums, 1, n-1, dp);

    //     return max(x, y);
    // }

    // int rob_recursive(vector<int>& nums, int index, int end, vector<int>& dp) {
    //     if(index > end) return 0;
    //     if(dp[index] != -1) return dp[index];
    //     dp[index] = max(nums[index] + rob_recursive(nums, index+2, end, dp), rob_recursive(nums, index+1, end, dp));
    //     return dp[index];
    // }

    //----------------------------------------------//

    // // DP (tabulation): save the results for overlapping problems to prevent calculating again; from bottom up
    // // TC: O(n)
    // // SC: O(n)
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1) return nums[0];
    //     if(n==2) return max(nums[0], nums[1]);

    //     vector<int> dp(n, 0);
    //     int rob1 = rob_linear(nums, dp, 0, n-2);
    //     int rob2 = rob_linear(nums, dp, 1, n-1);
    //     return max(rob1, rob2);
    // }

    // int rob_linear(vector<int>& nums, vector<int>& dp, int start, int end) {
    //     dp[start] = nums[start];
    //     dp[start+1] = max(nums[start], nums[start+1]);

    //     for(int i=start+2; i<=end; i++)
    //         dp[i] = max(nums[i]+dp[i-2], dp[i-1]);

    //     return dp[end];
    // }

    //------------------------------//

    //     // DP (space-optimized): only need last 2 values
    //     // TC: O(n)
    //     // SC: O(1)
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int rob1 = rob_linear(nums, 0, n - 2);
        int rob2 = rob_linear(nums, 1, n - 1);
        return max(rob1, rob2);
    }

    int rob_linear(vector<int> &nums, int start, int end)
    {
        if (!(end - start))
            return nums[start];

        int a = nums[start], b = max(nums[start], nums[start + 1]), c = 0;
        for (int i = start + 2; i <= end; i++)
        {
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }

        return c ? c : b;
    }
};
