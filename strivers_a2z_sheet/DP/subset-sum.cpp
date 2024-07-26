// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // simple recursion: pick/not pick each ele; if at any point, targetSum == 0, return 1
    // // TC: O(2^n)
    // // SC: O(n)
    // bool isSubsetSum(vector<int>arr, int sum){
    //     return helper(arr, arr.size()-1, sum);
    // }

    // int helper(vector<int>& arr, int idx, int sum) {
    //     if(!sum) return 1;
    //     if(!idx) return sum == arr[idx];
    //     int nottake = helper(arr, idx-1, sum);
    //     int take = 0;
    //     if(arr[idx] <= sum) take = helper(arr, idx-1, sum-arr[idx]);
    //     return take || nottake;
    // }

    // -------------------------------------------------------------------- //

    // // dp with memoization
    // // TC: O(n*sum)
    // // SC: O(n*sum)
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n = arr.size();
    //     vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    //     return helper(arr, n-1, sum, dp);
    // }

    // int helper(vector<int>& arr, int idx, int sum, vector<vector<int>> &dp) {
    //     if(!sum) return 1;
    //     if(!idx) return sum == arr[idx];
    //     if(dp[idx][sum] != -1) return dp[idx][sum];
    //     int nottake = helper(arr, idx-1, sum, dp);
    //     int take = 0;
    //     if(arr[idx] <= sum) take = helper(arr, idx-1, sum-arr[idx], dp);
    //     dp[idx][sum] = take || nottake;
    //     return dp[idx][sum];
    // }

    // // -------------------------------------------------------------------- //

    // // dp with tabulation
    // // TC: O(n*sum)
    // // SC: O(n*sum)
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n = arr.size();
    //     vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
    //     for(int i=0; i<n; i++)
    //         dp[i][0] = 1;
    //     dp[0][arr[0]] = 1;

    //     for(int i=1; i<n; i++) {
    //         for(int j=1; j<=sum; j++) {
    //             int nottake = dp[i-1][j];
    //             int take = 0;
    //             if(arr[i] <= j) take = dp[i-1][j-arr[i]];
    //             dp[i][j] = take || nottake;
    //         }
    //     }
    //     return dp[n-1][sum];
    // }

    // -------------------------------------------------------------------- //

    // dp with space optimization
    // TC: O(n*sum)
    // SC: O(sum)
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
        prev[0] = curr[0] = 1;
        prev[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                int nottake = prev[j];
                int take = 0;
                if (arr[i] <= j)
                    take = prev[j - arr[i]];
                curr[j] = take || nottake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
