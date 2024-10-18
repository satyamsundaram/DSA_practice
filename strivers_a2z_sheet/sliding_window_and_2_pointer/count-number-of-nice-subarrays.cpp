// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: for each possible subarray check if it has k odd numbers O(n^2) => TLE
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size(), niceCnt = 0;
    //     for(int i=0; i<n; i++) {
    //         int oddCnt = 0;
    //         for(int j=i; j<n; j++) {
    //             if(nums[j]%2) oddCnt++;
    //             if(oddCnt==k) niceCnt++;
    //         }
    //     }

    //     return niceCnt;
    // }

    // --------------------------------------- //

    // optimized: number of subarrays with at most k odd elements - number of subarrays with at most k-1 odd elements which can be handled with sliding window; if count violated, shrink window from left and update count
    // TC: O(n)
    // SC: O(1)
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int> &nums, int k)
    {
        int n = nums.size(), left = 0, right = 0, cnt = 0, oddCnt = 0;
        while (right < n)
        {
            if (nums[right] % 2)
                oddCnt++;
            while (oddCnt > k)
            {
                if (nums[left] % 2)
                    oddCnt--;
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }

        return cnt;
    }
};
