// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: it's a classic case of pick/not-pick; we have to try all possible solutions to reach amount=0 by deducting coins*denominations but how to decide how many coins to pick for each denomination? one way i can think of is using a for loop to try all possible numbers from 1 to amount/denominator or until possible, we can take a coin at an index, reduce amount but call function again at same index with new amount
    // TC: O((10^4)^n) -> max cases (exponential)
    // SC: O(amount) (max depth)
    // int coinChange(vector<int>& coins, int amount) {
    //     sort(coins.begin(), coins.end());
    //     int res = coinChangeHelper(coins, coins.size()-1, amount);
    //     return res >= 1e9 ? -1 : res;
    // }

    // int coinChangeHelper(vector<int>& coins, int idx, int amount) {
    //     if(!idx) {
    //         if(!(amount%coins[idx])) return amount/coins[idx];
    //         return 1e9; // don't return -1 as we're finding minimum and -1 will be taken as minimum, hence return a large value, not INT_MAX to prevent overflow
    //     }

    //     int nottake = coinChangeHelper(coins, idx-1, amount);
    //     int take = INT_MAX;
    //     if(coins[idx] <= amount) take = 1 + coinChangeHelper(coins, idx, amount-coins[idx]);

    //     return min(take, nottake);
    // }

    // // ---------------------- //

    // // dp with memo to prevent re-solving overlapping subproblems
    // // TC: O(n*amount)
    // // SC: O(n*amount) + O(amount)
    // int coinChange(vector<int>& coins, int amount) {
    //     sort(coins.begin(), coins.end());
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    //     int res = coinChangeHelper(coins, n-1, amount, dp);
    //     return res >= 1e9 ? -1 : res;
    // }

    // int coinChangeHelper(vector<int>& coins, int idx, int amount, vector<vector<int>> &dp) {
    //     if(!idx) {
    //         if(!(amount%coins[idx])) return amount/coins[idx];
    //         return 1e9; // don't return -1 as we're finding minimum and -1 will be taken as minimum, hence return a large value, not INT_MAX to prevent overflow
    //     }

    //     if(dp[idx][amount] != -1) return dp[idx][amount];

    //     int nottake = coinChangeHelper(coins, idx-1, amount, dp);
    //     int take = INT_MAX;
    //     if(coins[idx] <= amount) take = 1 + coinChangeHelper(coins, idx, amount-coins[idx]);

    //     dp[idx][amount] = min(take, nottake);
    //     return dp[idx][amount];
    // }

    // // ---------------------- //

    // // dp with tabulation to remove auxillary space
    // // TC: O(n*amount)
    // // SC: O(n*amount)
    // int coinChange(vector<int>& coins, int amount) {
    //     sort(coins.begin(), coins.end());
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1, 0));

    //     for(int t=0; t<=amount; t++)
    //         dp[0][t] = t%coins[0] == 0 ? t/coins[0] : 1e9;

    //     for(int i=1; i<n; i++) {
    //         for(int j=0; j<=amount; j++) {
    //             int nottake = dp[i-1][j];
    //             int take = INT_MAX;
    //             if(coins[i] <= j) take = 1 + dp[i][j-coins[i]];
    //             dp[i][j] = min(take, nottake);
    //         }
    //     }

    //     return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
    // }

    // ---------------------- //

    // dp with space optimization
    // TC: O(n*amount)
    // SC: O(amount)
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int t = 0; t <= amount; t++)
            prev[t] = t % coins[0] == 0 ? t / coins[0] : 1e9;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int nottake = prev[j];
                int take = INT_MAX;
                if (coins[i] <= j)
                    take = 1 + curr[j - coins[i]];
                curr[j] = min(take, nottake);
            }
            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};
