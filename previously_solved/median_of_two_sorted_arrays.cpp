// problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// 15.7.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // super naive: merge, sort and return median O((m+n)*log(m+n)))
    
    // less naive: merge only ((m+n)/2)+1 elements from both the arrays whilst maintaining the sorted order using two indexes, one for each, return (v[n-1]+v[n-2])/2 if m+n is even, else v[n-1] if m+n is odd; TC: O((m+n)/2)
    
    // optimal: apply binary search on the shorter sorted array to partition it and select either 1, 2, 3 ... (n/2)+1 elements from it for the left half and the rest of the first half's elements from the second array such that the left half and right half are sorted
    // TC: O(log(min(m,n)))
    // SC: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0.0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2<n1) return findMedianSortedArrays(nums2, nums1);
 
        int l=0, r=n1, cut1, cut2, l1, l2, r1, r2;
        while(l<=r) {
            cut1 = l+(r-l)/2;
            cut2 = (n1+n2+1)/2-cut1;
            l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            r2 = cut2==n2 ? INT_MAX : nums2[cut2];

            if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else return max(l1,l2);
            }
            else if(l1>r2) r=cut1-1;
            else l=cut1+1;
        }
        return res;
    }
};

