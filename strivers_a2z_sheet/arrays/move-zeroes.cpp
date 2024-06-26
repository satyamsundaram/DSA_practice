// https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // keep track of left most zero and find the 1st non-zero and switch them
    // TC: O(n)
    // SC: O(1)
    void moveZeroes(vector<int> &nums)
    {
        int z = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
            {
                if (i && !nums[i - 1])
                    continue;
                z = i;
            }
            else if (z != -1)
            {
                int temp = nums[i];
                nums[i] = 0;
                nums[z] = temp;
                z++;
            }
        }
    }
};
