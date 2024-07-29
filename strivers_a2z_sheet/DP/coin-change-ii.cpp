// https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // as long as we can take a coin, we can stay at the same index
    // // or not take it (or if we can't), move an index behind
    // // of course, TC will be exponential
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     return helper(coins, n-1, amount);
    // }

    // int helper(vector<int>& coins, int idx, int amt) {
    //     if(amt==0) return 1;
    //     if(!idx) {
    //         if(!(amt%coins[idx])) return 1;
    //         return 0;
    //     }

    //     int nottake = helper(coins, idx-1, amt);
    //     int take = 0;
    //     if(coins[idx]<=amt) take = helper(coins, idx, amt-coins[idx]);
    //     return take + nottake;
    // }

    // // ---------------------------- //

    // // dp with memo
    // // TC: >>O(n*amt)
    // // SC: O(n*amt)
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    //     return helper(coins, n-1, amount, dp);
    // }

    // int helper(vector<int>& coins, int idx, int amt, vector<vector<int>> &dp) {
    //     if(amt==0) return 1;
    //     if(!idx) {
    //         if(!(amt%coins[idx])) return 1;
    //         return 0;
    //     }

    //     if(dp[idx][amt] != -1) return dp[idx][amt];

    //     int nottake = helper(coins, idx-1, amt, dp);
    //     int take = 0;
    //     if(coins[idx]<=amt) take = helper(coins, idx, amt-coins[idx], dp);
    //     dp[idx][amt] = take + nottake;
    //     return dp[idx][amt];
    // }

    // // ---------------------------- //

    // // dp with tabu
    // // TC: O(n*amt)
    // // SC: O(n*amt)
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1, 0));

    //     for(int i=0; i<n; i++) dp[i][0]=1;
    //     for(int i=0; i<=amount; i++)
    //         if(!(i%coins[0])) dp[0][i]=1;

    //     for(int i=1; i<n; i++) {
    //         for(int j=1; j<=amount; j++) {
    //             int nottake = dp[i-1][j];
    //             int take = 0;
    //             if(coins[i]<=j) take = dp[i][j-coins[i]];
    //             dp[i][j] = take + nottake;
    //         }
    //     }
    //     return dp[n-1][amount];
    // }

    // ---------------------------- //

    // dp with space optim
    // TC: O(n*amt)
    // SC: O(amt)
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prev[0] = 1;
            curr[0] = 1;
        }

        for (int i = 0; i <= amount; i++)
        {
            if (!(i % coins[0]))
            {
                prev[i] = 1;
                curr[i] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int nottake = prev[j];
                int take = 0;
                if (coins[i] <= j)
                    take = curr[j - coins[i]];
                curr[j] = take + nottake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};
