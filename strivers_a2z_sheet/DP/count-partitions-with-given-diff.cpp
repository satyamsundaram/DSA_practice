// 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;
    // // find all possible subsets sum and then count subsets that satisfy our condition
    // // gives TLE
    // // TC: O(2^n * n); SC: O(2^n)
    // int countPartitions(int n, int d, vector<int>& arr) {
    //     // Code here
    //     int total = accumulate(arr.begin(), arr.end(), 0), res = 0, mod = 1000000007;
    //     vector<int> sums = getAllSubsetsSum(arr);

    //     for(int i=0; i<sums.size(); i++) {
    //         int sum2 = total - sums[i];
    //         if(sums[i] >= sum2 && sums[i]-sum2 == d) res++;
    //     }

    //     return res % mod;
    // }

    // // TC: O(2^n * n); SC: O(2^n)
    // vector<int> getAllSubsetsSum(vector<int>& arr) {
    //     vector<int> res;
    //     int n = arr.size();
    //     for(int i=0; i<(1<<n); i++) {
    //         int sum=0;
    //         for(int j=0; j<n; j++) {
    //             if(i & (1<<j)) sum+=arr[j];
    //         }
    //         res.push_back(sum);
    //     }
    //     return res;
    // }

    // // ---------------------------- //

    // // simple recursion: reduce problem set until base case
    // // TC: O(2^n); SC: O(n)
    // int countPartitions(int n, int d, vector<int>& arr) {
    //     int total = accumulate(arr.begin(), arr.end(), 0);
    //     return helper(arr, d, total, n-1, 0);
    // }

    // int helper(vector<int>& arr, int d, int total, int idx, int sum) {
    //     if(idx==-1) {
    //         int sum2 = total - sum;
    //         if(sum >= sum2 && sum-sum2 == d) return 1;
    //         return 0;
    //     }

    //     int nottake = helper(arr, d, total, idx-1, sum) % mod;
    //     int take = helper(arr, d, total, idx-1, sum+arr[idx]) % mod;
    //     return (take + nottake) % mod;
    // }

    // // ---------------------------- //

    // // dp with memoization
    // // TC: O(n*sum(arr)); SC: O(n*sum(arr))
    // int countPartitions(int n, int d, vector<int>& arr) {
    //     int total = accumulate(arr.begin(), arr.end(), 0);
    //     vector<vector<int>> dp(n, vector<int> (total+1, -1));
    //     return helper(arr, d, total, n-1, 0, dp);
    // }

    // int helper(vector<int>& arr, int d, int total, int idx, int sum, vector<vector<int>>& dp) {
    //     if(idx==-1) {
    //         int sum2 = total - sum;
    //         if(sum >= sum2 && sum-sum2 == d) return 1;
    //         return 0;
    //     }

    //     if(dp[idx][sum] != -1) return dp[idx][sum];

    //     int nottake = helper(arr, d, total, idx-1, sum, dp) % mod;
    //     int take = helper(arr, d, total, idx-1, sum+arr[idx], dp) % mod;
    //     dp[idx][sum] = (take + nottake) % mod;
    //     return dp[idx][sum];
    // }

    // // ---------------------------- //

    // // dp with tabulation
    // // TC: O(n*sum(arr)); SC: O(n*sum(arr))
    // int countPartitions(int n, int d, vector<int>& arr) {
    //     int total = accumulate(arr.begin(), arr.end(), 0);
    //     vector<vector<int>> dp(n+1, vector<int> (total+1, 0));
    //     for(int i=0; i<=total; i++) {
    //         int sum2 = total-i;
    //         if(i>=sum2 && i-sum2==d) dp[0][i]=1;
    //     }

    //     for(int i=1; i<=n; i++) {
    //         for(int j=total; j>=0; j--) {
    //             int nottake = dp[i-1][j] % mod;
    //             int take = dp[i-1][j+arr[i-1]] % mod;
    //             dp[i][j] = (take + nottake) % mod;
    //         }
    //     }

    //     return dp[n][0];
    // }

    // ---------------------------- //

    // dp with space optim
    // TC: O(n*sum(arr)); SC: O(sum(arr))
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<int> prev(total + 1, 0), curr(total + 1, 0);
        for (int i = 0; i <= total; i++)
        {
            int sum2 = total - i;
            if (i >= sum2 && i - sum2 == d)
            {
                prev[i] = 1;
                curr[i] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = total; j >= 0; j--)
            {
                int nottake = prev[j] % mod;
                int take = prev[j + arr[i - 1]] % mod;
                curr[j] = (take + nottake) % mod;
            }
            prev = curr;
        }

        return prev[0];
    }

    // ------------------------------------------ //
    /*
    can also be solved like this:
    s1-s2=d
    s1-(total-s1)=d
    2*s1=d+total
    s1=(d+total)/2

    need to find all subsets possible with sum=d+total/2
    just total+d should be even, for total+d/2 to be an int, else such a sum doesn't exist in array,
    hence return 0
    */
};
