// problem link: https://leetcode.com/problems/majority-element-ii/
// 29.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: store count of all the elements in an unordered_map, if any's count>n/3, push it to an unordered_set first and then to the result vector, so that we have only unique elements in our result vector
    // TC: O(n)
    // SC: O(n)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int limit = nums.size()/3;
    //     vector<int> res;
    //     unordered_map<int, int> um;
    //     unordered_set<int> us;
    //     for(auto &n:nums) {
    //         um[n]++;
    //         if(um[n]>limit && us.find(n) == us.end()) {
    //                 us.insert(n);
    //                 res.push_back(n);
    //         }
    //     }
    //     return res;
    // }

    // optimized: we use Boyer-Moore majority vote algorithm which is an extension of Boyer-Moore algorithm to find the majority element.
    // It works based on the observation that there can be at most 2 elements in an array that appear more than n/3 times, aka max 2 potential candidates
    // 
    // TC: O(n)
    // SC: O(1)
    vector<int> majorityElement(vector<int>& nums) {
        // step 1: find potential candidates
        int candidate1=0, candidate2=0, cnt1=0, cnt2=0;
        for(int num:nums) {
            if(num==candidate1) cnt1++;
            else if(num==candidate2) cnt2++;
            else if(cnt1==0) {
                candidate1=num;
                cnt1++;
            } else if(cnt2==0) {
                candidate2=num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // step 2: count occurrences for potential candidates
        cnt1=cnt2=0;
        for(int num:nums) {
            if(num==candidate1) cnt1++;
            else if(num==candidate2) cnt2++;
        }

        // step 3: check if count of occurrences > n/3
        int n=nums.size()/3;
        vector<int> res;
        if(cnt1>n) res.push_back(candidate1);
        if(cnt2>n) res.push_back(candidate2);
        return res;
    }
};
