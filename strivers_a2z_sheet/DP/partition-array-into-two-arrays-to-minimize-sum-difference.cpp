// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: either an element will go to subset1 or not go to it; our goal is that subset1 length reaches n/2 and diff b/w subset1 sum & initial array - subset1 sum should be minimum
    // // TC: O(2^(2*n)) can either pick/not-pick
    // // SC: O(2*n) recursion depth
    // int minimumDifference(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    //     return minimumDifferenceHelper(nums, 0, 0, 0, sum);
    // }

    // int minimumDifferenceHelper(vector<int>& nums, int idx, int cnt, int sum, int fullSum) {
    //     if(cnt == nums.size()/2) return abs(sum*2-fullSum);
    //     if(idx == nums.size()) return INT_MAX;

    //     return min(minimumDifferenceHelper(nums, idx+1, cnt, sum, fullSum), minimumDifferenceHelper(nums, idx+1, cnt+1, sum+nums[idx], fullSum));
    // }

    // can't optimized with dp due to -ve indexes, so we can use meet in the middle
    // even if we use unordered_map and store it all as strings, still time complexity will (n*n*sum) (huge >> 10^9)

    // meet in the middle:
    // partition into 2 arrays of equal length (n/2 -> left & right)
    // pre-compute all subarray lengths -> subarray possible sums on either N/2 sides (2^n * n)
    // for each i length left array sum find the corresponding subset sum on the right such that | total_sum - 2 * subset_sum | is minimum
    // for this we'll sort right subarray sums for binary search (2^n * log(2^n))
    // find the minimum
    // TC: O(2^n * log(2^n))
    // SC: O(2^n)
    int minimumDifference(vector<int> &nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        auto left = findAllSubsetsSum(nums, 0, n / 2 - 1);
        auto right = findAllSubsetsSum(nums, n / 2, n - 1);
        int target = totalSum / 2, ans = INT_MAX;

        // take 0 to n/2 length numbers from left
        for (int i = 0; i <= n / 2; i++)
        {
            // take n/2-i length numbers from right, sort it for binary search using lower_bound
            auto r = right[n / 2 - i];
            sort(r.begin(), r.end());

            for (int curLeftSum : left[i])
            {
                int requiredRightSum = target - curLeftSum;
                auto it = lower_bound(r.begin(), r.end(), requiredRightSum);
                if (it != r.end())
                    ans = min(ans, abs(totalSum - 2 * (curLeftSum + *it)));
            }
        }
        return ans;
    }

    // 1<<len: Each bitmask of length len can be interpreted as a binary number where each bit position indicates whether to include the corresponding element in the subset.
    // if (i & (1 << j)): This condition checks if the j-th bit of i is set. If it is, include nums[l + j] in the current subset.
    vector<vector<int>> findAllSubsetsSum(vector<int> &nums, int l, int r)
    {
        int len = r - l + 1;
        vector<vector<int>> res(len + 1);
        for (int i = 0; i < (1 << len); i++)
        {
            int sum = 0, cnt = 0;
            for (int j = 0; j < len; j++)
            {
                if (i & (1 << j))
                {
                    sum += nums[l + j];
                    cnt++;
                }
            }
            res[cnt].push_back(sum);
        }
        return res;
    }
};
