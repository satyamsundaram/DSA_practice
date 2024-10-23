// https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) => for every bar, find max bar length to its left and right (strictly greater), the min of the two - current bar length is the amount of water stored on top of that bar; sum for all bars will give our answer
    // int trap(vector<int>& bars) {
    //     int n = bars.size(), res = 0;

    //     for(int i=0; i<n; i++) {
    //         int maxl = 0, maxr = 0;

    //         for(int j=0; j<i; j++) {
    //             if(bars[j] > bars[i]) maxl = max(maxl, bars[j]);
    //         }

    //         if(!maxl) continue;

    //         for(int j=i+1; j<n; j++) {
    //             if(bars[j] > bars[i]) maxr = max(maxr, bars[j]);
    //         }

    //         if(!maxr) continue;

    //         res += (min(maxl, maxr) - bars[i]);
    //     }

    //     return res;
    // }

    // // ---------------------------------------------- //

    // // optimized: instead of checking entire left and right array for max height, we pre-compute and store for each index in order to only check once
    // // TC: O(n)
    // // SC: O(n)
    // int trap(vector<int>& bars) {
    //     int n = bars.size(), res = 0;
    //     vector<int> left(n, 0), right(n, 0);

    //     for(int i=1; i<n; i++)
    //         left[i] = max(left[i-1], bars[i-1]);

    //     for(int i=n-2; i>=0; i--)
    //         right[i] = max(right[i+1], bars[i+1]);

    //     for(int i=1; i<n-1; i++) {
    //         int water = min(left[i], right[i]) - bars[i];
    //         if(water > 0) res += water;
    //     }

    //     return res;
    // }

    // ---------------------------------------------- //

    // space-optimized: instead of saving max height on left and right for each ele in 2 arrays, we use 2 pointers to keep track of max height on left and right discovered so far
    // TC: O(n)
    // SC: O(1)
    int trap(vector<int> &bars)
    {
        int n = bars.size(), res = 0, maxl = 0, maxr = 0, l = 0, r = n - 1;
        while (l <= r)
        {
            if (bars[l] < bars[r])
            {
                if (bars[l] >= maxl)
                    maxl = bars[l];
                else
                    res += (maxl - bars[l]);
                l++;
            }
            else
            {
                if (bars[r] >= maxr)
                    maxr = bars[r];
                else
                    res += (maxr - bars[r]);
                r--;
            }
        }

        return res;
    }
};
