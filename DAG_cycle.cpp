//  Logic: For Cycle in directed graph, on the same path node has to be visited again.
// This is the Dfs technique, but you can apply kahn's Algo. which is bfs technique (we need indegree array not visited array) to find cycle detection.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {

        vis[node] = 1;   // visiting (in current path)

        for(auto it : adj[node]) {

            if(vis[it] == 0) {
                if(dfs(it, adj, vis))
                    return true;
            }
            else if(vis[it] == 1) {
                // back edge found
                return true;
            }
        }

        vis[node] = 2;   // fully processed
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis))
                    return true;
            }
        }

        return false;
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

    if(obj.isCyclic(V, edges))
        cout << "Cycle exists\n";
    else
        cout << "No cycle\n";

    return 0;
}
