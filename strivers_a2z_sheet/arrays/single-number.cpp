// https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // use xor
    // TC: O(N); SC: O(1)
    int singleNumber(vector<int> &nums)
    {
        int xored = nums[0];
        for (int i = 1; i < nums.size(); i++)
            xored ^= nums[i];

        return xored;
    }
};
