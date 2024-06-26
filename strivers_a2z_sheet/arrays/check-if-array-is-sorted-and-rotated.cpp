// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // the array should be completely non-dec or there should be 2 non-dev groups and the 1st ele of 1st group should be >= last ele of 2nd group
    // TC: O(n)
    // SC: O(1)
    bool check(vector<int> &nums)
    {
        int c = 0, len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                c++;
            if (c > 1)
                return 0;
        }

        if (c && nums[0] < nums[len - 1])
            return 0;
        return 1;
    }
};
