// problem link: https://leetcode.com/problems/3sum/
// 3.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: sort, run 2 nested loops & find the 3rd num that'll make sum=zero; skip dups by continuing; for some i and j, only one k will exist (w/o duplicates) that'll make up sum as zero, search k using binary search
    // TC: O(nlogn + (n^2)*logn) => TLE
    // SC: O(1)
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int n = nums.size();
    //     vector<vector<int>> res;
        
    //     for(int i=0; i<=n-3; i++) {
    //         if(i && nums[i]==nums[i-1]) continue;

    //         for(int j=i+1; j<=n-2; j++) {
    //             if(j!=i+1 && nums[j]==nums[j-1]) continue;

    //             int find = (nums[i] + nums[j]) * -1;
    //             int l = j+1, r = n-1, m;
                                
    //             while(l<=r) {
    //                 m = l+(r-l)/2;
    //                 if(find == nums[m]) {
    //                     res.push_back({nums[i], nums[j], nums[m]});
    //                     break;
    //                 } else if (find < nums[m]) r--;
    //                 else l++;
    //             }
    //         }
    //     }

    //     return res;
    // }

    //----------------------------------------------------------------//

    // optimized: pick an element and then find all the two elements that sum with it to zero using two pointers
    // TC: O(n^2)
    // SC: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        
        for(int i=0; i<=n-3; i++) {
            if(i && nums[i]==nums[i-1]) continue;
            int target = -nums[i], l = i+1, r = n-1;

            while(l<r) {
                int sum = nums[l]+nums[r];
                if(sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                } else if(sum < target) l++;
                else r--;
            }
        }

        return res;
    }
};

// -4,-1,-1,0,1,2,2,2
//  0, 1, 2,3,4,5,6,7