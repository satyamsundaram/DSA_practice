// problem link: https://leetcode.com/problems/single-element-in-a-sorted-array
// 12.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: XOR of all elements O(n)
    // left helf: 1st instance (even index), 2nd instance (odd index)
    // right helf: 1st instance (odd index), 2nd instance (even index)
    // check if we are in left half until high points to the left of the answer and low points at the answer
    // l=0 but r=n-2 to cover the case when the last element is the answer and low needs to point to it
    // TC: O(logn), SC: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-2;
        while(l<=r) {
            int m = l+(r-l)/2;
            if(m%2==0) {
                if(nums[m+1] == nums[m]) l=m+1;
                else r=m-1;
            } else {
                if(nums[m-1] == nums[m]) l=m+1;
                else r=m-1;
            }
        }
        return nums[l];
    }
};