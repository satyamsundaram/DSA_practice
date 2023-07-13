// problem link: https://leetcode.com/problems/search-in-rotated-sorted-array
// 13.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: We can apply binary search on the problem even if the array is sorted and rotated at a pivot. All we need to take care of is finding which side of the pivot are we currently in.
    // TC: O(log(n))
    // SC: O(1)
    int search(vector<int>& nums, int t) {
        int l=0, r=nums.size()-1, m;
        while(l<=r) {
            m = l+(r-l)/2;
            if(nums[m] == t) return m;
            else if(nums[l]<nums[m] && t>=nums[l] && t<=nums[m]) r=m-1;
            else if(nums[l]>nums[m] && (t>=nums[l] || t<=nums[m])) r=m-1;
            else if(nums[m]<nums[r] && t>=nums[m] && t<=nums[r]) l=m+1;
            else if(nums[m]>nums[r] && (t>=nums[m] || t<=nums[r])) l=m+1;
            else return -1;
        }
        return -1;
    }
};
