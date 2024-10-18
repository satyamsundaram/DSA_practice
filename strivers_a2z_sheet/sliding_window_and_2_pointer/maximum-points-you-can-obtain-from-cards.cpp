// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: try all the combinations eg: if we need to pick k cards, pick 0 from left, k from right, next pick 1 from left, k-1 from right, 2 from left, k-2 from right until k from left, 0 from right
    // // TC: O(n*k) => TLE
    // // SC: O(1)
    // int maxScore(vector<int>& cardPoints, int k) {
    //     int fromLeft = 0, fromRight = k, res = INT_MIN, n = cardPoints.size();
    //     while(fromLeft <= k) {
    //         int sum = 0;
    //         for(int i=0; i<fromLeft; i++)
    //             sum += cardPoints[i];
    //         for(int i=n-1; i>=n-fromRight; i--)
    //             sum += cardPoints[i];
    //         res = max(res, sum);
    //         fromLeft++;
    //         fromRight--;
    //     }

    //     return res;
    // }

    // ---------------------------------------------------------- //

    // optimized: if total_pts is sum of all cards, we need to remove subarray of length n-k with minimum sum and use the sum of the rest of the cards as our answer.
    // TC: O(n)
    // SC: O(n)
    int maxScore(vector<int> &cardPoints, int k)
    {
        int totalPts = 0, n = cardPoints.size();
        for (int point : cardPoints)
            totalPts += point;

        if (n == k)
            return totalPts;

        int left = 0, right = 0, sum = 0, minSum = INT_MAX;
        while (right < n - k)
            sum += cardPoints[right++];
        minSum = min(minSum, sum);

        while (right < n)
        {
            sum += cardPoints[right++];
            sum -= cardPoints[left++];
            minSum = min(minSum, sum);
        }

        return totalPts - minSum;
    }
};
