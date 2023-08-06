// problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// 6.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: reverse sort and return kth ele
    // TC: O(nlogn)
    // SC: O(1)
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end(), greater<int>());
    //     return nums[k-1];
    // }
    
    //----------------------------------------------------------//

    // optimized: using min-heap store smallest k elements but if size of heap > k, pop the top element so that we're only left with the largest k elements
    // TC: O(nlogk)
    // SC: O(k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n:nums) {
            pq.push(n);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};