// problem link: https://leetcode.com/problems/sort-colors/
// 17.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // super naive: using sorting algo
    // TC: O(nlogn)
    // SC: O(1)

    // naive: count the freq of 0,1,2 and update the array accordingly (2 pass algo)
    // TC: O(n)
    // SC: O(1)
    // void sortColors(vector<int>& nums) {
    //     int r=0, w=0, b=0;
    //     for(auto n:nums) {
    //         if(n==0) r++;
    //         else if(n==1) w++;
    //         else b++;
    //     }
    //     int i=0;
    //     while(r>0) {
    //         nums[i++]=0;
    //         r--;
    //     }
    //     while(w>0) {
    //         nums[i++]=1;
    //         w--;
    //     }
    //     while(b>0) {
    //         nums[i++]=2;
    //         b--;
    //     }
    // }

    // more optimal: using Dutch National Flag algorithm or 3-ay partitioning
    // TC: O(n)
    // SC: O(1)
    void sortColors(vector<int>& nums) {
        int red = 0;          // Pointer for the next position of red
        int blue = nums.size() - 1;   // Pointer for the next position of blue
        int i = 0;            // Current position

        while (i <= blue) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[red]);
                red++;
                i++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[blue]);
                blue--;
            } else {
                i++;
            }
        }
    }
};
