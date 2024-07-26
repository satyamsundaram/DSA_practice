// https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // naive: if total sum is odd, can't divide it into 2 equal sum (integer) subsets
    // an element can be in a subset or not, we need to check if our subset's sum equals total/2; we can try to solve this by recursion: pick/not-pick. if we pick, we deduct from targetSum, else not.
    // // TC: O(2^n) as for each idx we have 2 possibilities and n = len of vector
    // // SC: O(n) for recursion stack upto n
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if(sum%2) return 0;
    //     sum/=2; // targetSum

    //     return canPartitionHelper(nums, sum, 0);
    // }

    // bool canPartitionHelper(vector<int>& nums, int target, int idx) {
    //     if(!target) return 1;
    //     if(idx == nums.size() || target<0) return 0;

    //     return canPartitionHelper(nums, target-nums[idx], idx+1) || canPartitionHelper(nums, target, idx+1);
    // }

    // // ------------------------ //

    // // DP with memoization: to solve overlapping subproblems only once
    // // TC: O(n*S) as our recursion is a ftn of these 2 where S = targetSum
    // // SC: O(n*S) to store dp values
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if(sum%2) return 0;
    //     sum/=2; // targetSum
    //     vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
    //     return canPartitionHelper(nums, 0, sum, dp);
    // }

    // bool canPartitionHelper(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
    //     if(!target) return 1;
    //     if(idx == nums.size() || target<0) return 0;

    //     if(dp[idx][target]!=-1) return dp[idx][target];

    //     dp[idx][target] = canPartitionHelper(nums, idx+1, target-nums[idx], dp) || canPartitionHelper(nums, idx+1, target, dp);
    //     return dp[idx][target];
    // }

    // // ------------------------ //

    // // DP with tabulation: to solve overlapping subproblems only once
    // // TC: O(n*S)
    // // SC: O(n*S) to store dp values
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    //     if(sum%2) return 0;
    //     sum/=2; // targetSum
    //     vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    //     for(int i=0; i<=n; i++)
    //         dp[i][0] = 1; // can always achieve sum=0 with any number of elements by simply not picking any element

    //     for(int i=1; i<=n; i++) {
    //         for(int j=1; j<=sum; j++) {
    //             // sum-nums[i] of n-1 elements || sum of n-1 elements
    //             if(j>=nums[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
    //             else dp[i][j] = dp[i-1][j];
    //         }
    //     }
    //     return dp[n][sum];
    // }

    // ------------------------ //

    // space-optimized DP
    // TC: O(n*S)
    // SC: O(n*S) to store dp values
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if (sum % 2)
            return 0;
        sum /= 2; // targetSum
        vector<int> dp(sum + 1, 0);

        dp[0] = 1; // can always achieve sum=0 with any number of elements by simply not picking any element

        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= 0; j--)
            {
                // sum-nums[i] of n-1 elements || sum of n-1 elements
                if (j >= nums[i - 1])
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
                else
                    dp[j] = dp[j];
            }
        }
        return dp[sum];
    }
};
