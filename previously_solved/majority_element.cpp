// problem link: https://leetcode.com/problems/majority-element/
// 29.7.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: store count of each element in an unordered-map,
    // if any count > n/2, that's our answer
    // TC: O(n)
    // SC: O(n)
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> um;
    //     int maj = nums.size()/2;
    //     for(auto &n:nums) {
    //         um[n]++;
    //         if(um[n]>maj) return n;
    //     }
    //     return 0;
    // }

    // optimized: majority element's count will always be greater than the rest of the elements count, hence we can use just one variable to check count
    // TC: O(n)
    // SC: O(1)
    int majorityElement(vector<int>& nums) {
        int maj=nums[0], cnt=1;
        for(int i=1; i<nums.size(); i++) {
            if(!cnt) {
                maj=nums[i];
                cnt++;
            } else if(maj==nums[i]) cnt++;
            else cnt--;
        }
        return maj;
    }
};