#include<bits/stdc++.h>
using namespace std;

class Disjoint_set{
    private:
    vector<int> size, parent;
    public:
    Disjoint_set(int n){
        size.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }


    int find_parent(int node){
        if(node == parent[node]) return node;
        return parent[node] = find_parent(node);
    }

    void unionbysize(int u, int v) {
        int pu = find_parent(u);
        int pv = find_parent(v);

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