// problem link: https://leetcode.com/problems/trapping-rain-water/
// 5.8.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: for each index, find the max heights to its left and right and then calc amount of water trapped on it
    // TC: O(n^2)
    // SC: O(1)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if(n<3) return 0;
        
    //     int total = 0;
    //     for(int i=1; i<n-1; i++) {
    //         int mxleft = 0, mxright=0;
            
    //         for(int j=0; j<i; j++) {
    //             mxleft = max(mxleft, height[j]);
    //         }

    //         for(int j=i+1; j<n; j++) {
    //             mxright = max(mxright, height[j]);
    //         }

    //         total += max(0, min(mxleft, mxright) - height[i]);
    //     }

    //     return total;
    // }

    //--------------------------------------------------------//

    // optimized: instead of finding the max heights to the left and right, repeatedly for each index, do it once for all
    // TC: O(n)
    // SC: O(n)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if(n<3) return 0;

    //     vector<int> mxleft(n), mxright(n);
    //     mxleft[0] = height[0];
    //     for(int i=1; i<n; i++)
    //         mxleft[i] = max(mxleft[i-1], height[i]);
        
    //     mxright[n-1] = height[n-1];
    //     for(int i=n-2; i>=0; i--)
    //         mxright[i] = max(mxright[i+1], height[i]);

    //     int total = 0;
    //     for(int i=1; i<n-1; i++) {
    //         total += max(0, min(mxleft[i], mxright[i]) - height[i]);
    //     }

    //     return total;
    // }

    //-------------------------------------------------------------------//

    // space optimized: using two pointers, for the minimum of the two heights, either update the mxleft or mxright height, or calc the water trapped there
    // TC: O(n)
    // SC: O(1)

    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;

        int left=0, right=n-1, mxleft=0, mxright=0, total=0;
        while(left < right) {
            if(height[left]<height[right]) {
                if(height[left]>mxleft) mxleft = height[left];
                else total += mxleft - height[left];
                left++;
            } else {
                if(height[right]>mxright) mxright = height[right];
                else total += mxright - height[right];
                right--;
            }
        }

        return total;
    }
};