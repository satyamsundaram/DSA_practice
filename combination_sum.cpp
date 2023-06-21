// problem link: https://leetcode.com/problems/combination-sum/
// 21-06-2021 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, int t, vector<int>& candidates, vector<int>& v, vector<vector<int>>& res) {
        if(t==0) {
            res.push_back(v);
            return;
        }
        if(i==candidates.size()) return;
        if(t<candidates[i]) return;

        // not take
        helper(i+1, t, candidates, v, res);

        // take
        v.push_back(candidates[i]);
        helper(i, t-candidates[i], candidates, v, res);
        v.pop_back();
    }

    // method: take and not take but after you take, stay on the same index as long as the value there is <= the remains of the target and call for the rest recursively
    // TC: O(nlogn) + O(2^t * k) = O(2^t * k) where 2^t is if we're at the same indes t times and k is to push a subset of length k into res
    // SC: O(t * x) -> very hypothetical as it's hard to estimate the number of subsets; here t is the number of subsets and x is the length of it
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, v, res);
        return res;
    }
};