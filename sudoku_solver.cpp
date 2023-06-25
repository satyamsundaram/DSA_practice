// problem link: https://leetcode.com/problems/sudoku-solver/
// 25.6.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for(int i=0; i<9; i++) {
            if(board[i][col] == c) return 0;
            if(board[row][i] == c) return 0;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c) return 0;
        }
        return 1;
    }
    
    // method: find empty spot, try to fill a number and call recursively for the rest
    // TC: O(n*n*n*n)
    // SC: O(1)
    bool helper(int row, vector<vector<char>>& board) {
        int n = board.size();
        
        for(int i=row; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') {
                    for(char c='1'; c<='9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if(helper(i, board)) return 1;
                            else board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }

        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(0, board);
    }
};