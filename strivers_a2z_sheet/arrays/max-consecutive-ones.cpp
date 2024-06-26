// https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // keep track of max length, reset cnt when zero encountered and update max
    // TC: O(N); SC: O(1)
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int mx = 0, len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                len++;
            else
            {
                mx = max(mx, len);
                len = 0;
            }
        }

        mx = max(mx, len);
        return mx;
    }
};
