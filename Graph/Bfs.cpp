#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> ans;

        queue<int> q;

        // For disconnected graph
        for (int i = 0; i < v; i++) {

            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
            
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    ans.push_back(node);

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> res = obj.bfs(adj);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}
