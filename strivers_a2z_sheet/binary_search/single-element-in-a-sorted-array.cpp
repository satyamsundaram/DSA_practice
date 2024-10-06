// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: single loop (we can also do XOR of all ele)
    // // TC: O(n)
    // int singleNonDuplicate(vector<int>& nums) {
    //     int i=0;
    //     for(; i<nums.size()-1; i++) {
    //         if(nums[i] == nums[i+1]) i++;
    //         else break;
    //     }

    //     return nums[i];
    // }

    // ----------------------------- //

    // optimized: since every element is repeating twice, except for one element which is present only once; so since it's sorted, first index of repeating ele should be even ideally but after the presence of our singular ele, this would change where the first index of repeating ele becomes odd. and since it's sorted, we can use BS. go to an index, if it doesn't have any match to the left or right, return it; else fidn first index of repeating ele, if it's even, search on right, else on left
    // TC: O(logn)
    // SC: O(1)
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, sz = r;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m && nums[m - 1] == nums[m])
            {
                if ((m - 1) % 2 == 0)
                    l = m + 1;
                else
                    r = m - 2;
            }
            else if (m != sz && nums[m + 1] == nums[m])
            {
                if (m % 2 == 0)
                    l = m + 2;
                else
                    r = m - 1;
            }
            else
                break;
        }

        if (l == r)
            return nums[l];
        return nums[(l + r) / 2];
    }
};
