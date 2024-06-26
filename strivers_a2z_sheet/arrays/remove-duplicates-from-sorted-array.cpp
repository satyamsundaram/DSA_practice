// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // keep track of the next spot and update it if the current ele is not the same as last modified
    // TC: O(n)
    // SC: O(1)
    int removeDuplicates(vector<int> &nums)
    {
        int e = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[e])
                nums[++e] = nums[i];
        }

        return e + 1;
    }
};
