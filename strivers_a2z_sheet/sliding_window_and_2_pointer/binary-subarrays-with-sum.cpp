// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) => run a nested for loop and check if sum <= goal, add to count
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int cnt = 0, n=nums.size();
    //     for(int i=0; i<n; i++) {
    //         int sum = 0;
    //         for(int j=i; j<n; j++) {
    //             sum += nums[j];
    //             if(sum==goal) cnt++;
    //             if(sum>goal) break;
    //         }
    //     }

    //     return cnt;
    // }

    // ------------------------------------------- //

    // // optimized: O(n) using prefix sum with hashmap
    // // where in prefix sum, value of index i is the sum of all elements from 0 to i
    // // sum(i,j) = prefix_sum[j] - prefix_sum[i-1]
    // // we want: prefix_sum[j] - prefix_sum[i-1] = goal
    // // or, prefix_sum[j] = prefix_sum[i-1] + goal
    // // if we know the current prefixSum[j], we need to check if there exists a previous prefix sum (prefixSum[i-1]) that satisfies this condition.
    // // If such a previous prefix sum exists, then there is a subarray ending at j whose sum equals goal.
    // int numSubarraysWithSum(vector<int> &nums, int goal)
    // {
    //     unordered_map<int, int> prefixCount; // prefixSum -> freq
    //     int prefixSum = 0, result = 0;

    //     // for valid subarrays that start from beginning
    //     prefixCount[0] = 1;

    //     for (int num : nums)
    //     {
    //         // update running sum
    //         prefixSum += num;

    //         // if (prefixSum-goal) exists, it means there is a subarray ending with current index with sum == goal
    //         if (prefixCount.find(prefixSum - goal) != prefixCount.end())
    //             result += prefixCount[prefixSum - goal];

    //         prefixCount[prefixSum]++;
    //     }

    //     return result;
    // }

    // --------------------------------------------- //

    // optimized: O(n) using sliding window
    // Count subarrays whose sum is at most goal.
    // Count subarrays whose sum is at most goal - 1.
    // The difference between these two will give the subarrays whose sum is exactly goal.
    // For arrays with only 0s and 1s, it's easy to track the window's sum since every time you expand or shrink the window, the sum only changes by 1.
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        auto atMost = [&](int S) -> int
        {
            if (S < 0)
                return 0;
            int cnt = 0, sum = 0, left = 0;
            for (int right = 0; right < nums.size(); right++)
            {
                sum += nums[right];
                while (sum > S)
                    sum -= nums[left++];
                cnt += (right - left + 1);
            }

            return cnt;
        };

        return atMost(goal) - atMost(goal - 1);
    }
};
