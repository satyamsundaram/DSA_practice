// https://leetcode.com/problems/fibonacci-number/description/

class Solution
{
public:
    // // simple recursion
    // // TC: O(2^N)
    // // SC: O(1)
    // int fib(int n) {
    //     if(n<=1) return n;
    //     return fib(n-1) + fib(n-2);
    // }

    // // top down (memoization)
    // // TC: O(N)
    // // SC: O(N)
    // int fib(int n) {
    //     if(n<=1) return n;
    //     vector<int> v(n+1, -1);
    //     if(v[n] == -1) v[n] = fib(n-1) + fib(n-2);
    //     return v[n];
    // }

    // // bottom up (tabulation)
    // // TC: O(N)
    // // SC: O(N)
    // int fib(int n) {
    //     if(n<=1) return n;
    //     vector<int> v(n+1, 0);
    //     v[1] = 1;
    //     for(int i=2; i<=n; i++)
    //         v[i] = v[i-1] + v[i-2];
    //     return v[n];
    // }

    // space optimized bottom up
    // TC: O(N)
    // SC: O(1)
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = b;
            b = a + b;
            a = c;
        }
        return b;
    }
};