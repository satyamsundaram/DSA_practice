// https://leetcode.com/problems/target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // classic case of pick/notpick, except here it is -/+
    // try all possible cases: for each index, we have 2 options, + or -
    // if at idx == 0, target = +nums[0] or -nums[0], return 1 else 0
    // // TC: O(2^n)
    // // SC: O(n)
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     return helper(nums, n-1, target);
    // }

    // int helper(vector<int>& nums, int i, int t) {
    //     if(!i) {
    //         if(nums[i] == abs(t)) return 1;
    //         return 0;
    //     }

    //     int minus = helper(nums, i-1, t+nums[i]);
    //     int plus = helper(nums, i-1, t-nums[i]);
    //     return minus + plus;
    // }

    // ------------------- //

    // dp with memoization can't be done as target (a changing param) can also be negative and an array index can't be negative

    // ------------------- //

    // we'll solve it in another way: dividing the array into 2 subsets (all +ves or all -ves) such that the diff of the two is equal to target
    // a number will either be in subset1 or subset2, so each number has 2 options; we just need to find one subset, the sum of the other will be known by total sum - subset1 sum
    // this problem becomes the problem of counting subset partitions with diff d
    // TC: O(n*sum)
    // SC: O(n*sum)
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size(), total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));

        for (int i = 0; i <= total; i++)
        {
            int sum2 = total - i;
            if (i - sum2 == target)
                dp[0][i] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = total; j >= 0; j--)
            {
                int nottake = dp[i - 1][j];
                int take = dp[i - 1][j + nums[i - 1]];
                dp[i][j] = take + nottake;
            }
        }

        return dp[n][0];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int res = s.findTargetSumWays(nums, target);
    cout << res;
    return 0;
}