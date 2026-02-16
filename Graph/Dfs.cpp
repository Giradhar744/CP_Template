#include <bits/stdc++.h>
using namespace std;

// Undirected graph
class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans)
    {

        vis[node] = 1;
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, ans);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> ans;
        vector<int> vis(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, ans);
            }
        }

        return ans;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> res = obj.dfs(adj);

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}
