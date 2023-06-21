// problem link: https://leetcode.com/problems/combination-sum-ii/
// 21-06-2023 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, int t, vector<int>& candidates, vector<int>& v, vector<vector<int>>& res) {
        int n = candidates.size();
        if(t == 0) {
            res.push_back(v);
            return;
        }
        if(idx == n) return;

        for(int i=idx; i<n; i++) {
            if(candidates[i] > t) return;
            if(i!=idx && candidates[i] == candidates[i-1]) continue;
            v.push_back(candidates[i]);
            helper(i+1, t-candidates[i], candidates, v, res);
            v.pop_back();
        }
    }

    // method: first, we sort the given array; then we build our solution set level by level (in terms of subset lengths) using a for loop but depth-first using recursion; using for loop we don't pick up a similar element at a level twice 
    // TC: O(nlogn) + O(2^n*k) = O(2^n*k), 2^n because all elements are unique as they are picked once, k is the no. of subsets
    // SC: O(k*x), x is the length of a subset
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> res;
        helper(0, target, candidates, v, res);
        return res;
    }
};
