// https://leetcode.com/problems/climbing-stairs/description/

class Solution
{
public:
    // // simple recursion: gives TLE
    // // TC: O(2^n)
    // // SC: O(1)
    // int climbStairs(int n) {
    //     if(n<=2) return n;
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }

    // // top down (memoization)
    // // TC: O(n)
    // // SC: O(n)
    // int climbStairs(int n) {
    //     vector<int> v(n+1, -1);
    //     return climbStairsHelper(n, v);
    // }

    // int climbStairsHelper(int n, vector<int>&v) {
    //     if(n<=2) return n;
    //     if(v[n] == -1) v[n] = climbStairsHelper(n-1, v) + climbStairsHelper(n-2, v);
    //     return v[n];
    // }

    // // bottom up (tabulation)
    // // TC: O(n)
    // // SC: O(n)
    // int climbStairs(int n) {
    //     if(n<=2) return n;
    //     vector<int> dp(n+1);
    //     dp[1]=1;
    //     dp[2]=2;

    //     for(int i=3; i<=n; i++)
    //         dp[i] = dp[i-1] + dp[i-2];

    //     return dp[n];
    // }

    // space-optimized bottom up (tabulation): we only require i-1 and i-2th values
    // TC: O(n)
    // SC: O(1) 
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int a = 1, b = 2, c;

        for (int i = 3; i <= n; i++)
        {
            c = b;
            b = a + b;
            a = c;
        }

        return b;
    }
};
