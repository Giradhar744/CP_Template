#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int v = graph.size();
        vector<int> color(v, -1);   // -1 = uncolored, 0 and 1 are colors
        queue<int> q;

        for(int start = 0; start < v; start++){

            if(color[start] != -1) continue;

            q.push(start);
            color[start] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto it : graph[node]){

                    if(color[it] == -1){
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else{
                        if(color[it] == color[node])
                            return false;
                    }

                }
            }
        }

        return true;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;

        // undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    Solution obj;

    if(obj.isBipartite(graph))
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}
