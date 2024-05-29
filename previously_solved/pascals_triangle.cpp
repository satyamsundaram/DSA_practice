// problem link: https://leetcode.com/problems/pascals-triangle/
// 16.7.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: edges are always 1, in between add sum of couples sequentially of the previous row
    // TC: O(n^2)
    // SC: O(n^2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> v;
        for(int i=0; i<numRows; i++) {
            v.push_back(1);
            for(int j=0; j<i-1; j++)
                v.push_back(res[i-1][j]+res[i-1][j+1]);
            if(i>0) v.push_back(1);
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};