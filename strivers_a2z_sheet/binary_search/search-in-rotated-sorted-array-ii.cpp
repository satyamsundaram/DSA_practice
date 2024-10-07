// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(N) for loop search
    // bool search(vector<int>& nums, int target) {
    //     for(int i=0; i<nums.size(); i++)
    //         if(nums[i] == target) return 1;
    //     return 0;
    // }

    // --------------------------------------- //

    // optimized: w/o duplicates, we had 2 sorted halves. now because of duplicates, we could have possibly only one half that's sorted. we need to check for target in that sorted half. if nums[m]==nums[l]==nums[r], we won't be able to know which half is sorted, so we decrease search space.
    // TC: O(logn) average case; worst case: O(n) when full of duplicates
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return 1;
            if (nums[m] == nums[l] && nums[m] == nums[r])
            {
                l++;
                r--;
            }
            else if (nums[l] <= nums[m])
            { // if left half is sorted
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else
            { // if right half is sorted
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return 0;
    }
};
