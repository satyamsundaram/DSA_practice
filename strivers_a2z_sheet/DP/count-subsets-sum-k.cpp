// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // 	// an element can be in subset or not, if at any point, remaining sum == 0, return 1
    // 	// TC: O(2^n)
    // 	// SC: O(n)
    // 	int perfectSum(int arr[], int n, int sum)
    // 	{
    // 	    int zeros = 0;
    // 	    vector<int> newarr;
    // 	    for(int i=0; i<n; i++) {
    // 	        if(!arr[i]) zeros++;
    // 	        else newarr.push_back(arr[i]);
    // 	    }

    //         int ways = helper(newarr, newarr.size()-1, sum) * pow(2, zeros);
    //         return ways;
    // 	}

    // 	int helper(vector<int> &arr, int idx, int sum) {
    // 	    if(!sum) return 1;
    // 	    if(!idx) return sum == arr[idx];
    // 	    int nottake = helper(arr, idx-1, sum);
    // 	    int take = 0;
    // 	    if(arr[idx] <= sum) take = helper(arr, idx-1, sum-arr[idx]);
    // 	    return (take + nottake) % 1000000007;
    // 	}

    //     // ------------------------------------------------------------  //
    //     // dp with memo
    // 	// TC: O(n*sum)
    // 	// SC: O(n*sum)
    // 	int perfectSum(int arr[], int n, int sum)
    // 	{
    // 	    int zeros = 0;
    // 	    vector<int> newarr;
    // 	    for(int i=0; i<n; i++) {
    // 	        if(!arr[i]) zeros++;
    // 	        else newarr.push_back(arr[i]);
    // 	    }
    // 	    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    // 	    int ways = helper(newarr, newarr.size()-1, sum, dp) * pow(2, zeros);
    //         return ways;
    // 	}

    // 	int helper(vector<int>& arr, int idx, int sum, vector<vector<int>>& dp) {
    // 	    if(!sum) return 1;
    // 	    if(!idx) return sum == arr[idx];
    // 	    if(dp[idx][sum] != -1) return dp[idx][sum];
    // 	    int nottake = helper(arr, idx-1, sum, dp);
    // 	    int take = 0;
    // 	    if(arr[idx] <= sum) take = helper(arr, idx-1, sum-arr[idx], dp);
    // 	    dp[idx][sum] = (take + nottake) % 1000000007;
    // 	    return dp[idx][sum];
    // 	}

    // // ------------------------------------------------------------  //
    //     // dp with tabu
    // 	// TC: O(n*sum)
    // 	// SC: O(n*sum)
    // 	int perfectSum(int arr[], int n, int sum)
    // 	{
    // 	    int zeros = 0;
    // 	    vector<int> newarr;
    // 	    for(int i=0; i<n; i++) {
    // 	        if(!arr[i]) zeros++;
    // 	        else newarr.push_back(arr[i]);
    // 	    }
    // 	    int len = newarr.size();
    // 	    vector<vector<int>> dp(len, vector<int>(sum+1, 0));
    // 	    for(int i=0; i<len; i++) dp[i][0] = 1;
    // 	    if(newarr[0] <= sum) dp[0][newarr[0]] = 1;
    // 	    for(int i=1; i<len; i++) {
    // 	        for(int j=0; j<=sum; j++) {
    // 	            int nottake =dp[i-1][j];
    //         	    int take = 0;
    //         	    if(newarr[i] <= j) take = dp[i-1][j-newarr[i]];
    //         	    dp[i][j] = (take + nottake) % 1000000007;
    // 	        }
    // 	    }
    // 	    int ways = dp[len-1][sum] * pow(2, zeros);
    //         return ways;
    // 	}

    // ------------------------------------------------------------  //
    // dp with space optim
    // TC: O(n*sum)
    // SC: O(sum)
    int perfectSum(int arr[], int n, int sum)
    {
        int zeros = 0;
        vector<int> newarr;
        for (int i = 0; i < n; i++)
        {
            if (!arr[i])
                zeros++;
            else
                newarr.push_back(arr[i]);
        }
        int len = newarr.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        prev[0] = curr[0] = 1;
        if (newarr[0] <= sum)
            prev[newarr[0]] = 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int nottake = prev[j];
                int take = 0;
                if (newarr[i] <= j)
                    take = prev[j - newarr[i]];
                curr[j] = (take + nottake) % 1000000007;
            }
            prev = curr;
        }
        int ways = prev[sum] * pow(2, zeros);
        return ways;
    }
};
