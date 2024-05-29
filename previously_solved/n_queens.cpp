// problem link: https://leetcode.com/problems/n-queens/
// 25.6.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<string>& v, int row, int col, int n) {
        for(int i=0; i<row; i++) {
            if(v[i][col] == 'Q') return 0;
        }

        for(int j=0; j<col; j++) {
            if(v[row][j] == 'Q') return 0;
        }

        for(int i=row-1, j=col-1; ; i--, j--) {
            if(i<0 || j<0) break;
            if(v[i][j] == 'Q') return 0;
        }

        for(int i=row-1, j=col+1; ; i--, j++) {
            if(i<0 || j==n) break;
            if(v[i][j] == 'Q') return 0;
        }

        return 1;
    }

    void helper(int row, int n, vector<string>& v, vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(v);
            return;
        }

        for(int col=0; col<n; col++) {
            if(isValid(v, row, col, n)) {
                v[row][col] = 'Q';
                helper(row+1, n, v, res);
                v[row][col] = '.';
            }
        }
    }

    // method: at each row, if a queen can be placed at an index, place it and call recursively for the rows below it
    // TC: O(n*n*n*t) where t is the no. of possible placements
    // SC: O(n*n*t)
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> v;
        string s(n, '.');
        for(int i=0; i<n; i++) v.push_back(s);
        helper(0, n, v, res);
        return res;
    }
};