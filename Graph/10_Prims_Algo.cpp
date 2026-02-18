#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<array<int,3>> mstEdges;   // {u, v, w} 

    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(V, 0);

        // (weight, node, parent)
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>> pq;

        pq.push({0, 0, -1});   // start node has no parent

        int sum = 0;

        while(!pq.empty()){

            auto [wt, node, parent] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            // store the chosen edge (except first dummy one)
            if(parent != -1){
                mstEdges.push_back({parent, node, wt});
            }

            for(auto &it : adj[node]){
                int adjnode = it.first;
                int adjwt   = it.second;

                if(!vis[adjnode]){
                    pq.push({adjwt, adjnode, node});
                }
            }
        }

        return sum;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    Solution obj;

    int totalWeight = obj.spanningTree(V, edges);

    cout << "Total MST weight = " << totalWeight << "\n";
    cout << "Edges in MST:\n";

    for(auto &e : obj.mstEdges){
        cout << e[0] << " - " << e[1] << "  weight = " << e[2] << "\n";
    }

    return 0;
}
