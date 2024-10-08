// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    // TC: O(V) + O(2E)
    // SC: O(E)
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> res;
        queue<int> q;
        int vis[V] = {0};
        vis[0] = 1;
        q.push(0);

        while (!(q.empty()))
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto it : adj[curr])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends