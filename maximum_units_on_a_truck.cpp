// problem link: https://leetcode.com/problems/maximum-units-on-a-truck/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(const vector<int>& box1, const vector<int>& box2) {
        return box1[1] > box2[1];
    }

    // method: sort the vector a/c to the higher units/box and then pick as many boxes as you can of that type to maximize the no. of total units
    // TC: O(NlogN) + O(N) = O(NlogN)
    // SC: O(1)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);

        int maxUnits = 0;
        for(auto &box:boxTypes) {
            if(truckSize) {
                int n = min(truckSize, box[0]);
                truckSize -= n;
                maxUnits += n*box[1];
            } else break;
        }
        return maxUnits;
    }
};
