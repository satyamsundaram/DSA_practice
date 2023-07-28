// problem link: https://leetcode.com/problems/merge-intervals/
// 28.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

// method: sort the intervals in ascending order, then if an intervals overlaps with the previous, merge it, else add it as new
// TC: O(nlogn + n)
// SC: O(n)
class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0]<v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        int c = 0;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= res[c][1] || intervals[i][1] <= res[c][1])
                res[c][1] = max(res[c][1], intervals[i][1]);
            else {
                res.push_back(intervals[i]);
                c++;
            }
        }

        return res;
    }
};
