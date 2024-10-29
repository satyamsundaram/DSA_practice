// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) => for each bar try out in both directions while we encounter bars of >= height to itself
    // int largestRectangleArea(vector<int>& heights) {
    //     int res = 0, n=heights.size();
    //     for(int i=0; i<n; i++) {
    //         if(!heights[i]) continue;
    //         int area = heights[i];

    //         int s = i-1;
    //         while(s>=0 && heights[s]>=heights[i]) {
    //             area += heights[i];
    //             s--;
    //         }

    //         s=i+1;
    //         while(s<n && heights[s]>=heights[i]) {
    //             area += heights[i];
    //             s++;
    //         }

    //         res = max(res, area);
    //     }

    //     return res;
    // }

    // ------------------------------------------ //

    // optimized: for each bar, we need to know the first bar on its left and on its right that is smaller than it; we need to know this in O(n) time. using a monotonic non-decreasing stack, we push indices to it, but if we encounter a bar whose ht is < st.top(), for the st.top() we found first bar on the right smaller than it and we pop top element. the ele below it in stack denotes first ele to its left that was smaller than it. we calc area by height of ele we popped * width where width = curr i - st.top() - 1. if st is empty, it means the ele we popped was the smallest in whole array, so width is entire i.
    // TC & SC: O(n)
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0, n = heights.size();
        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            int h = i == n ? 0 : heights[i];

            while (!st.empty() && h < heights[st.top()])
            {
                int ht = heights[st.top()];
                st.pop();
                int wid = st.empty() ? i : i - st.top() - 1;
                res = max(res, ht * wid);
            }

            st.push(i);
        }

        return res;
    }
};
