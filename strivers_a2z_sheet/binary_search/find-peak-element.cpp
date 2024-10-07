// https://leetcode.com/problems/find-peak-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n) for loop
    // int findPeakElement(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1 || nums[0] > nums[1]) return 0;
    //     if(nums[n-1] > nums[n-2]) return n-1;

    //     for(int i=1; i<n-1; i++)
    //         if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;

    //     return -1;
    // }

    // -------------------------------------- //

    // optimized: go towards the direction of a possible peak
    // TC: O(logn)
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] > nums[m + 1])
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};
