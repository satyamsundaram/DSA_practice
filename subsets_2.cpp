// problem link: https://leetcode.com/problems/subsets-ii/
// 18-06-2023 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, vector<int> &v, vector<int> &nums, vector<vector<int>>& res) {
        res.push_back(v);
        for(int i=idx; i<nums.size(); i++) {
            if(i!=idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(i+1, v, nums, res);
            v.pop_back();
        }
    }

    // method: pick and not pick an element and continue for others recursively
    // but to avoid duplicates, if at any level, if we've picked x, we'll not pick any more x. To enact that, nums will be sorted and if curr_ele is same as prev_ele, don't pick
    // TC: O(NlogN) + O(2^N * N) = O(2^N * N) 
    // SC: O(2^N) + O(K) where K is avg length of a subset
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> v;
        helper(0, v, nums, res);
        return res;
    }
};