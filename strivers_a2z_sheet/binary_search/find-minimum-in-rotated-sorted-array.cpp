// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n) for loop
    // int findMin(vector<int>& nums) {
    //     int mn = INT_MAX;
    //     for(int i=0; i<nums.size(); i++)
    //         mn = min(mn, nums[i]);
    //     return mn;
    // }

    // --------------------------------- //

    // optimized:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mn = INT_MAX;
        while (l < r)
        {
            int m = (l + r) / 2;
            mn = min(mn, nums[m]);
            if (nums[m] < nums[r])
                r = m - 1;
            else
                l = m + 1;
        }

        return min(mn, nums[l]);
    }
};
