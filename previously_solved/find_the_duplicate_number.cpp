// problem link: https://leetcode.com/problems/find-the-duplicate-number/
// 17.6.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // supernaive: sort and check if any number is same as next number but we can't use this as a/c to question as we can't modify nums and we can't copy it as we need to use constant extra space
    // TC: O(nlogn)
    // SC: O(1)
    
    // naive: use an unordered_map to store count and check if any count>1 but we can't use this as a/c to question we need to use constant extra space
    // TC: O(n)
    // SC: O(n)

    // optimal: using the tortoise and hare algorithm aka slow and fast pointers which is used to detect cycles and the duplicated element will create a cycle when we move in the array using the values as the next indices
    // TC: O(n)
    // SC: O(1)
    int findDuplicate(vector<int>& nums) {
        int tortoise=nums[0], hare=nums[0];

        // find the cycle
        do {
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
        } while(tortoise!=hare);

        // once hare is in the cycle, find the repeated number which is the start of the cycle
        tortoise=nums[0];
        while(tortoise!=hare) {
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return tortoise;
    }
};

/*
examples:
4,1,4,3,2,5
0,1,2,3,4,5

tort->4,2,4,2,4,2,4,
hare->4,4,4
hare->4,

---------------------

4,5,1,2,3,3
0,1,2,3,4,5

tort->4,3,2,1,5,3,2,1,5,3,
hare->4,2,5,2,5
hare->5,3,
*/