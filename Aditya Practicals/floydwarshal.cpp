#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000 // define infinity as a large number
#define N 1000 // maximum number of nodes

int dist[N][N]; // N is the number of nodes in the graph

void floyd_warshall() {
    // initialize the distance matrix with the weights of the edges
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // read in the edges of the graph
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    // run Floyd-Warshall algorithm
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
