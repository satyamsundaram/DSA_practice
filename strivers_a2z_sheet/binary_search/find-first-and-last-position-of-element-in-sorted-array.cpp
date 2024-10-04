// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // TC: O(logn)
    // int binarySearch(char ch, int l, int r, int t, int sz, vector<int> &nums) {
    //     while(l<=r) {
    //         int m = (l+r)/2;
    //         if(nums[m] == t) {
    //             if(ch == 's') {
    //                 if(!m || nums[m-1] != t) return m;
    //                 return binarySearch(ch, l, m-1, t, sz, nums);
    //             } else {
    //                 if(m==sz || nums[m+1] != t) return m;
    //                 return binarySearch(ch, m+1, r, t, sz, nums);
    //             }
    //         }
    //         else if(nums[m] > t) r=m-1;
    //         else l=m+1;
    //     }

    //     return -1;
    // }

    int findFirst(vector<int> &nums, int t)
    {
        int l = 0, r = nums.size() - 1, firstPos = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == t)
            {
                firstPos = m;
                r = m - 1;
            }
            else if (nums[m] > t)
                r = m - 1;
            else
                l = m + 1;
        }

        return firstPos;
    }

    int findLast(vector<int> &nums, int t)
    {
        int l = 0, r = nums.size() - 1, lastPos = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == t)
            {
                lastPos = m;
                l = m + 1;
            }
            else if (nums[m] > t)
                r = m - 1;
            else
                l = m + 1;
        }

        return lastPos;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // int s=-1, e=-1, l=0, r=nums.size()-1;
        // s = binarySearch('s', l, r, target, r, nums);
        // if(s==-1) return {s,e};
        // e = binarySearch('e', l, r, target, r, nums);

        int s = -1, e = -1;
        s = findFirst(nums, target);
        if (s == -1)
            return {s, e};
        e = findLast(nums, target);
        return {s, e};
    }
};
