// https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) => outer loop for nums1 -> inner loop for num2 (match, search)
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> res;
    //     for(int i=0; i<nums1.size(); i++) {
    //         int f=0, grt=-1;
    //         for(int j=0; j<nums2.size(); j++) {
    //             if(nums2[j] == nums1[i]) f=1;
    //             else if(f && nums2[j]>nums1[i]) {
    //                 grt=nums2[j];
    //                 break;
    //             }
    //         }
    //         res.push_back(grt);
    //     }

    //     return res;
    // }

    // --------------------------------------- //

    // optimized: store the next greater ele for each index in nums2 in a temp vector -> we do this by iterating backwards in it; next we store mapping b/w ele and index for nums2 elements to find them in O(1) time when we run a loop for nums1
    // TC: O(n1+n2)
    // SC: O(n2)
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n2 = nums2.size();
        vector<int> res, nge(n2, -1);
        unordered_map<int, int> um;
        stack<int> st;

        // for(int i=0; i<n2; i++) {
        //     um[nums2[i]]=i;
        //     if(i==n2-1) continue;

        //     if(nums2[i+1]>nums2[i]) {
        //         nge[i]=nums2[i+1];
        //         while(!st.empty() && nums2[i+1]>st.top()) {
        //             nge[um[st.top()]]=nums2[i+1];
        //             st.pop();
        //         }
        //     } else st.push(nums2[i]);
        // }

        for (int i = n2 - 1; i >= 0; i--)
        {
            um[nums2[i]] = i;
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (!st.empty())
                nge[i] = st.top();
            st.push(nums2[i]);
        }

        for (auto ele : nums1)
        {
            res.push_back(nge[um[ele]]);
        }

        return res;
    }
};
