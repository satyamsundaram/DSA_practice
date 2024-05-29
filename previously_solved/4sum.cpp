// problem link: https://leetcode.com/problems/4sum/
// 30.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: run 4 nested loops and check if sum of the 3 elements = target 
    // but this approach won't handle duplicate quadruplets
    // TC: O(n^4) ~ 10^9 here
    // SC: O(1)

    // optimized: two-pointer approach with sorting
    // sort the elements first; fix two elements and use 2 pointers to find the rest 2 elements if they add up to target
    // TC: O(n^3) as 3 loops now ~ 106
    // SC: O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3) return res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<=n-4; i++) {
            // skip duplicate quadruplets
            if(i>0 && nums[i]==nums[i-1]) continue;
            if((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if((long long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;

            for(int j=i+1; j<=n-3; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if((long long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if((long long)nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;

                int l=j+1, r=n-1;
                while(l<r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(target == sum) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // skip duplicates
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;

                        l++; r--;
                    } else if(sum > target) r--;
                    else l++;
                }
            }
        }

        return res;
    }
};