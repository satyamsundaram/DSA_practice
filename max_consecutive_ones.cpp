// problem link: https://leetcode.com/problems/max-consecutive-ones/
// 5.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: evident
    // TC: O(n)
    // SC: O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, mx = 0;
        for(int n:nums) {
            if(n) mx = max(mx, ++c);
            else c=0;
        }
        return mx;
    }
};