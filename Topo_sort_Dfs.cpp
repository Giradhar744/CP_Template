#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, stack<int> &st) {

        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }

        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());   // ← you missed ()
            st.pop();
        }

        return ans;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<int> topo = obj.topoSort(V, edges);

    for(int x : topo)
        cout << x << " ";

    return 0;
}
