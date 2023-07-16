// problem link: https://leetcode.com/problems/set-matrix-zeroes/
// 16.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // super naive: create a new copy of the matrix, loop through the old matrix to find 0's and make modifications in the copied matrix
    // TC: O(mn * (m+n))
    // SC: O(mn)
    
    // naive: store only the rows and cols to be made zero and make modifications in the same matrix after finding all the 0's
    // TC: O(mn)
    // SC: O(m+n)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size(), n = matrix[0].size();
    //     vector<int> rows(m,1), cols(n,1);
        
    //     for(int i=0; i<m; i++) {
    //         for(int j=0; j<n; j++) {
    //             if(matrix[i][j]==0) {
    //                 rows[i]=0;
    //                 cols[j]=0;
    //             }
    //         }
    //     }

    //     for(int i=0; i<m; i++) {
    //         if(rows[i]==0) {
    //             for(int col=0; col<n; col++) 
    //                 matrix[i][col]=0;
    //         }
    //     }

    //     for(int i=0; i<n; i++) {
    //         if(cols[i]==0) {
    //             for(int row=0; row<m; row++) 
    //                 matrix[row][i]=0;
    //         }
    //     }
    // }

    //**************************************************************//

    // optimal: instead of storing rows and cols to be made zero in separate vectors, store them in the first row an col of matrix itself
    // TC: O(mn)
    // SC: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), col0=1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0]=0;
                    if(j==0) col0=0;
                    else matrix[0][j]=0;
                }
            }
        }  

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j]!=0) {
                    if(matrix[i][0]==0 || matrix[0][j]==0) 
                        matrix[i][j]=0;
                }
            }
        } 

        if(matrix[0][0]==0) {
            for(int i=0; i<n; i++)
                matrix[0][i]=0;
        }

        if(col0==0) {
            for(int i=0; i<m; i++)
                matrix[i][0]=0;
        }
    }
};