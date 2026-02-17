#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        // build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});   // remove this for directed graph
        }

        vector<int> dist(V, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int wt   = top.first;
            int node = top.second;

            // very important line
            if (wt > dist[node]) continue;   // Because in Dijkstra using a priority queue, the same node can be pushed multiple times with different distances.

            for (auto &it : adj[node]) {

                int adjnode = it.first;
                int adjwt   = it.second;

                if (wt + adjwt < dist[adjnode]) {
                    dist[adjnode] = wt + adjwt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        return dist;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> ans = obj.dijkstra(V, edges, src);

    for (int i = 0; i < V; i++) {
        if (ans[i] == 1e9) cout << "INF ";
        else cout << ans[i] << " ";
    }

    return 0;
}
