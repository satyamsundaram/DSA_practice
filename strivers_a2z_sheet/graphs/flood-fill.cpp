// https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bfs: visited, queue, imageCopy
    // TC: O(m*n)
    // SC: O(m*n)
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> imageCopy = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!(q.empty()))
        {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            imageCopy[i][j] = color;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int a = 0; a < 4; a++)
            {
                int nrow = i + drow[a];
                int ncol = j + dcol[a];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == image[sr][sc] && !vis[nrow][ncol])
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return imageCopy;
    }
};