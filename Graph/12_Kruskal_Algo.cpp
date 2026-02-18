#include <bits/stdc++.h>
using namespace std;

class Disjoint_set {
private:
    vector<int> parent, size;

public:
    Disjoint_set(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findparent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }

    void unionbysize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {

        sort(edges.begin(), edges.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[2] < b[2];
             });

        Disjoint_set dsu(V);

        int sum = 0;
        int cnt = 0;

        for(auto &e : edges) {

            int u  = e[0];
            int v  = e[1];
            int wt = e[2];

            if(dsu.findparent(u) != dsu.findparent(v)) {
                dsu.unionbysize(u, v);
                sum += wt;
                cnt++;

                if(cnt == V - 1) break;   // MST completed  (for MST, if V vertices then there must be V-1 edges for being  a MST)
            }
        }

        return sum;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    Solution obj;
    cout << obj.kruskalsMST(V, edges) << endl;

    return 0;
}
