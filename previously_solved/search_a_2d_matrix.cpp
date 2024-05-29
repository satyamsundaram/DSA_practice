// problem link: https://leetcode.com/problems/search-a-2d-matrix/
// 28.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive: fill the elements in a new vector of size m*n and apply binary search 
    // TC: O(m*n + log(m*n))
    // SC: O(m*n)

    // optimal: find the row in which the target might be by binary search and then apply binary search in that row
    // TC: O(log(m) + log(n)) = O(log(m*n))
    // SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m-1, mid;
        while(lo<=hi) {
            mid = lo+(hi-lo)/2;
            if(target <= matrix[mid][n-1]) {
                if(mid>0 && target > matrix[mid-1][n-1])
                    break;
                else hi = mid-1;
            } else lo = mid+1;
        }

        lo = 0, hi = n-1;
        int row = mid;
        while(lo<=hi) {
            mid = lo+(hi-lo)/2;
            if(target == matrix[row][mid])
                return 1;
            else if(target < matrix[row][mid])
                hi = mid-1;
            else lo = mid+1;
        }

        return 0;
    }
};

//     n-1
// 0   7
// 1   15
// 2   24
// 3   39
// 4   51
// 5   77
// m-1 93
