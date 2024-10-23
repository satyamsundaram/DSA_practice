// https://leetcode.com/problems/sum-of-subarray-minimums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // naive: two nested loops
    // // TC: O(n^2) => TLE
    // // SC: O(1)
    // int sumSubarrayMins(vector<int>& nums) {
    //     int mod = 1e9+7, res = 0, n = nums.size();
    //     for(int i=0; i<n; i++) {
    //         int mn = nums[i];
    //         for(int j=i; j<n; j++) {
    //             mn = min(mn, nums[j]);
    //             res += mn;
    //             res %= mod;
    //         }
    //     }

    //     return res%mod;
    // }

    // -------------------------------------- //

    // optimized: for each index we need to know how many subarrays it is a part of where it is the minimum, we can find this by counting for each index, how many numbers to its left are >= it (the rightmost ele will be minimum if same numbers are repeated) and how many numbers to its right are > (strictly) it. then each ele's contribution to sum = arr[i] * left[i] * right[i]; we can get this count using stack => why stack? for each ele we need to keep track of all ele's before it which were >= or > than it depending on our use case, so we need it to keep track
    // TC: O(n)
    // SC: O(n)
    int sumSubarrayMins(vector<int>& nums) {
        int mod = 1e9+7, n = nums.size();
        long long res = 0;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1, s2; // {ele, count}

        // left
        for(int i=0; i<n; i++) {
            int cnt = 1;
            while(!s1.empty() && s1.top().first >= nums[i]) {
                cnt += s1.top().second;
                s1.pop();
            }

            left[i]=cnt;
            s1.push({nums[i], cnt});
        }

        // right
        for(int i=n-1; i>=0; i--) {
            int cnt = 1;
            while(!s2.empty() && s2.top().first > nums[i]) {
                cnt += s2.top().second;
                s2.pop();
            }

            right[i]=cnt;
            s2.push({nums[i], cnt});
        }

        for(int i=0; i<n; i++) {
            res = (res + (long long)nums[i]*left[i]*right[i]) % mod;
        }

        return res;
    }
};
