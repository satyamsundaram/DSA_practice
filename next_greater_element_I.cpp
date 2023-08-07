// problem link: https://leetcode.com/problems/next-greater-element-i/
// 7.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // naive: use an unordered_map to store the next greater for elements in nums2; use two nested loops to find next greater elements for nums; update nums1 with next greater elements from umap
    // // TC: O(m + n^2)
    // // SC: O(n)
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> nextgt;
    //     for(int i=0; i<nums2.size(); i++) {
    //         nextgt[nums2[i]] = -1;
    //         for(int j=i+1; j<nums2.size(); j++) {
    //             if(nums2[j]>nums2[i]) {
    //                 nextgt[nums2[i]] = nums2[j];
    //                 break;
    //             }
    //         }
    //     }

    //     for(int i=0; i<nums1.size(); i++) nums1[i] = nextgt[nums1[i]];
    //     return nums1;
    // }

    //-----------------------------------------------------------------//

    // optimized: use an unordered_map to store the next greater for elements in nums2; use a stack to find next greater elements for nums in a single loop run; update nums1 with next greater elements from umap
    // TC: O(m + n)
    // SC: O(n)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextgt;
        stack<int> s;
        for(int n:nums2) {
            while(!s.empty() && n>s.top()) {
                nextgt[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }

        vector<int> res;
        for(int n:nums1) res.push_back(nextgt.count(n) ? nextgt[n] : -1);
        return res;
    }
};

// 11,8,4,3,2,7,1,4,0,9