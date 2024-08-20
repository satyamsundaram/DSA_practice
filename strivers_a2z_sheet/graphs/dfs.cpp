// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int vis[], vector<int> adj[], int node, vector<int> &res)
    {
        vis[node] = 1;
        res.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(vis, adj, it, res);
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    // TC: O(V + 2E)
    // SC: O(V)
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> res;
        int vis[V] = {0};
        vis[0] = 1;
        dfs(vis, adj, 0, res);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends