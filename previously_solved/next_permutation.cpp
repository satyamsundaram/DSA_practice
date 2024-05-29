// problem link: https://leetcode.com/problems/next-permutation/
// 18.6.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: generate all the permutations in sorted order and find the next permutation after our given permutation 
    // TC: O(n!*n)
    // SC: O(n!*n)

    // or using next_permutation(nums.begin(), nums.end()) from C++ STL

    // optimal: Start from the right end of the array and find the first pair of adjacent elements nums[i] and nums[i+1] such that nums[i] < nums[i+1].
    // If no such pair is found, it means the array is in descending order, and it represents the last possible permutation. In this case, reverse the entire array to get the lowest possible order.
    // If a pair is found in step 1, find the smallest element in the subarray nums[i+1:] that is greater than nums[i]. Let's call this element nums[j].
    // Swap nums[i] with nums[j].
    // Reverse the subarray nums[i+1:] to get the next lexicographically greater permutation.
    // TC: O(n)
    // SC: O(1)
    void nextPermutation(vector<int>& nums) {
        int ind = -1, n = nums.size();
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                ind = i;
                break;
            }
        }

        if(ind==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>ind; i--) {
            if(nums[i]>nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin()+ind+1, nums.end());
    }
};
