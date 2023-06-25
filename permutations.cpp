// problem link: https://leetcode.com/problems/permutations/
// 25.6.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<vector<int>>& res) {
        int n = nums.size();
        if(idx == n-1) {
            res.push_back(nums);
            return;
        }

        for(int i=idx; i<n; i++) {
            swap(nums[i], nums[idx]);
            helper(idx+1, nums, res);
            swap(nums[i], nums[idx]);
        }
    }

    // method: swap and recurse
    // TC: O(n! * n)
    // SC: O(n! * n)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
};