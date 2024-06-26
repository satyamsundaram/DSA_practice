// https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // simple: find max number, create vector of max num length + 1, fill all with 0, iterate and convert 0 to 1 if num present; iterate thru vector, if 0 anywhere, return index else return max number + 1
    // // TC: O(N); SC: O(N)
    // int missingNumber(vector<int>& nums) {
    //     int mx = -1;
    //     for(int i=0; i<nums.size(); i++)
    //         mx = max(mx, nums[i]);

    //     vector<int> v(mx+1, 0);

    //     for(int i=0; i<nums.size(); i++)
    //         v[nums[i]]=1;

    //     for(int i=0; i<mx+1; i++)
    //         if(!v[i]) return i;

    //     return mx+1;
    // }

    // space optimized: iterate, find max number, store sum of all nums; if n(n+1)/2 == sum, return max+1, else return n(n+1)/2 - sum
    // TC: O(N); SC: O(1)
    int missingNumber(vector<int> &nums)
    {
        int mx = -1, sum = 0, z = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, nums[i]);
            sum += nums[i];
            if (!nums[i])
                z = 1;
        }

        int expected_sum = (mx * (mx + 1)) / 2;
        if (expected_sum == sum)
        {
            if (!z)
                return 0;
            return mx + 1;
        }

        return expected_sum - sum;
    }
};
