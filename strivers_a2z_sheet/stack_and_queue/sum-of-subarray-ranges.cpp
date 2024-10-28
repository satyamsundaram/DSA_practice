// https://leetcode.com/problems/sum-of-subarray-ranges/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2)
    // long long subArrayRanges(vector<int>& nums) {
    //     long long res = 0;
    //     int n = nums.size();

    //     for(int i=0; i<n; i++) {
    //         int mn = nums[i], mx = nums[i];
    //         for(int j=i; j<n; j++) {
    //             mn = min(mn, nums[j]);
    //             mx = max(mx, nums[j]);
    //             res += (mx-mn);
    //         }
    //     }

    //     return res;
    // }

    // --------------------------------- //

    // optimized: SC & TC: O(n) => count all the subarrays where an index is mininum and maximum; their contribution will be how many times max * nums[i] - how many times min * nums[i]
    long long sumSubarrayMins(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1, s2; // {ele, count}

        // left
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (!s1.empty() && s1.top().first >= nums[i])
            {
                cnt += s1.top().second;
                s1.pop();
            }

            left[i] = cnt;
            s1.push({nums[i], cnt});
        }

        // right
        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 1;
            while (!s2.empty() && s2.top().first > nums[i])
            {
                cnt += s2.top().second;
                s2.pop();
            }

            right[i] = cnt;
            s2.push({nums[i], cnt});
        }

        for (int i = 0; i < n; i++)
        {
            res = (res + (long long)nums[i] * left[i] * right[i]);
        }

        return res;
    }

    long long sumSubarrayMaxs(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1, s2; // {ele, count}

        // left
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (!s1.empty() && s1.top().first <= nums[i])
            {
                cnt += s1.top().second;
                s1.pop();
            }

            left[i] = cnt;
            s1.push({nums[i], cnt});
        }

        // right
        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 1;
            while (!s2.empty() && s2.top().first < nums[i])
            {
                cnt += s2.top().second;
                s2.pop();
            }

            right[i] = cnt;
            s2.push({nums[i], cnt});
        }

        for (int i = 0; i < n; i++)
        {
            res = (res + (long long)nums[i] * left[i] * right[i]);
        }

        return res;
    }

    // optimized:
    long long subArrayRanges(vector<int> &nums)
    {
        long long res = 0;
        res = res + sumSubarrayMaxs(nums) - sumSubarrayMins(nums);

        return res;
    }
};
