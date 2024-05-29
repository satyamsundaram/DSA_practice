// problem link: https://leetcode.com/problems/powx-n
// 28.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: easily evident from code
    // TC: O(n) => TLE
    // SC: O(1)
    // double myPow(double x, long n) {
    //     if(x == 0 || x == 1) return x;
    //     bool neg = 0;
    //     if(n<0) {
    //         neg = 1;
    //         n *= -1;
    //     }
        
    //     double res = 1.0;
    //     for(long i=1; i<=n; i++)
    //         res *= x;
    //     return neg ? 1/res : res;
    // }

    //-----------------------------------------//

    // optimal: When we need to calculate x raised to a power n, we can take advantage of certain properties of exponentiation to optimize the computation.
    // One such property is: x^n = x^n/2 * x^n/2.
    // This property suggests that if we know the result of x^n/2, we can easily calculate x^n without performing additional multiplications to find its value twice such as in a loop from 1 to n.
    // We can exploit this property to reduce the number of multiplications and make the calculation more efficient.

    // TC: O(logn)
    // SC: O(1)
    double myPow(double x, long n) {
        if(n==0) return 1;
        if(n==1) return x;
        bool neg = 0;
        if(n<0) {
            neg = 1;
            n *= -1;
        }  

        double res = 1, p = pow(x,n/2);
        res*=p*p;
        if(n&1) res*=x;

        return neg ? 1/res : res;
    }
};