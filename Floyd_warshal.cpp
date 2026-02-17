#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
public:

    /*
        dist[i][j] = shortest distance from i to j

        Floyd–Warshall idea:
        Try every node k as an intermediate node
        and try to improve all pairs (i, j)

        Transition:
        i ----> k ----> j

        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    */
    void floydWarshall(vector<vector<int>> &dist) {

        int n = dist.size();

        // k = intermediate node
        for(int k = 0; k < n; k++){

            // i = source
            for(int i = 0; i < n; i++){

                // j = destination
                for(int j = 0; j < n; j++){

                    // If path i->k and k->j both exist
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8){

                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }
    }
};

int main() {

    int n;
    cin >> n;

    /*
        Input:
        Adjacency matrix
        Use 100000000 (1e8) for no edge
    */

    vector<vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }

    Solution obj;
    obj.floydWarshall(dist);

    // Output shortest distance matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == 1e8)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
