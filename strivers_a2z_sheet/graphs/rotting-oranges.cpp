// https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int isRemaining(vector<vector<int>> &grid, int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return 1;
            }
        }

        return 0;
    }

public:
    // iterative BFS solution
    // TC: O(m*n*mins)
    // SC: O(1)
    // int orangesRotting(vector<vector<int>>& grid) {
    //     int m=grid.size(), n=grid[0].size();

    //     int num=2, f=1, mins=0;
    //     while(f) {
    //         f=0;
    //         for(int i=0; i<m; i++) {
    //             for(int j=0; j<n; j++) {
    //                 if(grid[i][j]==num) {
    //                     int drow[] = {-1, 0, 1, 0};
    //                     int dcol[] = {0, 1, 0, -1};

    //                     for(int a=0; a<4; a++) {
    //                         int nrow = i+drow[a];
    //                         int ncol = j+dcol[a];

    //                         if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
    //                             grid[nrow][ncol]=num+1;
    //                             f=1;
    //                         }
    //                     }
    //                 }
    //             }
    //         }

    //         if(f) {
    //             mins++;
    //             num++;
    //         }
    //     }

    //     if(isRemaining(grid, m, n)) return -1;

    //     return mins;
    // }

    // ----------------------------------------------- //

    // recursive
    // TC: O(m*n)
    // SC: O(m*n)
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), min = 0;
        queue<pair<pair<int, int>, int>> q; // index, mins
        vector<vector<int>> gridCpy = grid;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (gridCpy[i][j] == 2)
                    q.push({{i, j}, min});
            }
        }

        // BFS
        while (!(q.empty()))
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int i = p.first.first, j = p.first.second;
            min = p.second;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int a = 0; a < 4; a++)
            {
                int nrow = i + drow[a];
                int ncol = j + dcol[a];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && gridCpy[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, min + 1});
                    gridCpy[nrow][ncol] = 2;
                }
            }
        }

        if(isRemaining(gridCpy, m, n)) return -1;

        return min;
    }
};