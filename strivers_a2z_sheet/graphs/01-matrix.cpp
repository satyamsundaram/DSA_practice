// https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BFS: start visiting from 0-nodes
    // TC: O(m*n)
    // SC: O(m*n)
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res = mat;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!mat[i][j])
                    q.push({i, j});
                vis[i][j] = 1;
            }
        }

        while (!(q.empty()))
        {
            pair<int, int> p = q.front();
            q.pop();

            int i = p.first, j = p.second;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int a = 0; a < 4; a++)
            {
                int nrow = i + drow[a];
                int ncol = j + dcol[a];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol])
                {
                    q.push({nrow, ncol});
                    res[nrow][ncol] += res[i][j];
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    Solution s;

    vector<vector<int>> res = s.updateMatrix(mat);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}