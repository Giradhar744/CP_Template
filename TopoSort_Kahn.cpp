#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // compute indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // push all nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // if cycle exists, no valid topo order
        if ((int)ans.size() < V)
            return {};

        return ans;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1]; // u v (u -> v)
    }

    Solution obj;
    vector<int> topo = obj.topoSort(V, edges);

    if (topo.empty()) {
        cout << "Cycle present. Topological sort not possible\n";
    } else {
        for (int x : topo)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
