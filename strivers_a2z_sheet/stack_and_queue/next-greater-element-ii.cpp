// https://leetcode.com/problems/next-greater-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: check all possible indices for each index
    // // TC: O(n^2)
    // // SC: O(1)
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> nge(n, -1);

    //     for(int i=n-1; i>=0; i--) {
    //         int f=0;

    //         for(int j=i+1; j<n; j++) {
    //             if(nums[j]>nums[i]) {
    //                 nge[i]=nums[j];
    //                 f=1;
    //                 break;
    //             }
    //         }

    //         if(f) continue;
    //         for(int j=0; j<i; j++) {
    //             if(nums[j]>nums[i]) {
    //                 nge[i]=nums[j];
    //                 break;
    //             }
    //         }
    //     }

    //     return nge;
    // }

    // ---------------------------------------------- //

    // optimized: iterate from backwards, for each index pop all ele <= to it, if st not empty, nge[i]=st.top(), push current ele, repeat this over and over the nums range until st not empty
    // TC: O(n)
    // SC: O(n)
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size(), c = 2;
        vector<int> nge(n, -1);
        stack<int> st;

        while (c--)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && st.top() <= nums[i])
                    st.pop();
                if (!st.empty())
                    nge[i] = st.top();
                st.push(nums[i]);
            }
        }

        return nge;
    }
};
