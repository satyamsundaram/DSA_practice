// https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) => run 2 nested loops and the inner loop should run till we encounter a zero and k == 0
    // int longestOnes(vector<int>& nums, int k) {
    //     int res = 0, n = nums.size();
    //     for(int i=0; i<n; i++) {
    //         int temp = k, cnt = 0;
    //         for(int j=i; j<n; j++) {
    //             if(nums[j]) cnt++;
    //             else if(temp) {
    //                 cnt++;
    //                 temp--;
    //             } else break;

    //             res = max(res, cnt);
    //         }
    //     }

    //     return res;
    // }

    // -------------------------------------------- //

    // optimized: maintain a valid window size where k>=0 using sliding window in order to not compute same values again for max length
    // TC: O(n)
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, right = 0, res = 0, n = nums.size();
        while (right < n)
        {
            if (!nums[right])
            {
                if (k)
                    k--;
                else
                    while (nums[left++])
                        ;
            }

            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
