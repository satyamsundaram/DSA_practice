// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n) for loop and search
    // int search(vector<int>& nums, int target) {
    //     for(int i=0; i<nums.size(); i++)
    //         if(nums[i]==target) return i;
    //     return -1;
    // }

    // ------------------------------------ //

    // optimized: take advantage of sorting and find pivot point of rotation to know which half to search in; if at any index if it's not equal to target and if target is b/w index l and m, search in left half; else search in right half.
    // TC: O(logn); SC:O(1)
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, sz = r;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < nums[l])
            { // [l,m] not fully sorted
                if (target >= nums[l] || target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else
            {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }

        return -1;
    }
};
