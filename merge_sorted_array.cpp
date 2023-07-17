// problem link: https://leetcode.com/problems/merge-sorted-array
// 17.7.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: sort & fill nums1 from backwards using 2 pointers
    // TC: O(m+n)
    // SC: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1, l=m-1, r=n-1;
        while(l>=0 && r>=0) {
            if(nums1[l]>nums2[r])
                nums1[i--]=nums1[l--];
            else
                nums1[i--]=nums2[r--];
        }
        while(l>=0) nums1[i--]=nums1[l--];
        while(r>=0) nums1[i--]=nums2[r--];
    }
};
