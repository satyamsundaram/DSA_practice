// https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int i, vector<vector<int>> &isConnected, vector<int> &vis, int V)
    {
        vis[i] = 1;
        for (int j = 0; j < V; j++)
        {
            if (isConnected[i][j] && !vis[j])
                dfs(j, isConnected, vis, V);
        }
    }

public:
    // find no. of connected components
    // TC: O(V^2)
    // SC: O(V) + O(V) [vector + recursion stack]
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size(), cnt = 0;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, isConnected, vis, V);
            }
        }

        return cnt;
    }
};