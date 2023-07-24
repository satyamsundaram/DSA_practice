// problem link: https://leetcode.com/problems/rotate-image/
// 24.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: using another matrix, just place the rows from top into the cols from right but it won't be in-place
    // TC: O(n^2)
    // SC: O(n^2)

    // optimal: to do it in-place, we use two loops to rotate element by element clockwise
    // TC: O(n^2)
    // SC: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size(), n=len-1;
        for(int i=0; i<len/2; i++) {
            for(int j=i; j<n-i; j++) {
                swap(matrix[i][j], matrix[j][n-i]);
                swap(matrix[i][j], matrix[n-i][n-j]);
                swap(matrix[i][j], matrix[n-j][i]);
            }
        }
    }
};

// 0 1 2 3
// 1 
// 2
// 3

// 0,0 -> 0,3 -> 3,3 -> 3,0 -> 0,0
// 0,1 -> 1,3 -> 3,2 -> 2,0 -> 0,1
// 0,2 -> 2,3 -> 3,1 -> 1,0 -> 0,2
// 1,1 -> 1,2 -> 2,2 -> 2,1 -> 1,1