// problem link: https://leetcode.com/problems/two-sum/
// 17-06-2023 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // TC: O(N^2), SC: O(1)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     for(int i=0; i<n-1; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             if(nums[i] + nums[j] == target)
    //                return {i,j};
    //         }
    //     }
    //     return {-1,-1};
    // }

    // TC: O(N), SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;

        for(int i=0; i<nums.size(); i++) {
            if(um.find(target-nums[i]) == um.end())
                um[nums[i]] = i;
            else return {i, um[target-nums[i]]};
        }
        return {-1,-1};
    }
};