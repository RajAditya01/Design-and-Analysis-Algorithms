#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>> &graph)
{
    int n = graph.size();

    // Dynamic Programming table
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Base case
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Recurrence relation
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output results
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    // Initialize graph
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
    }

    // Input edges
    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // Run algorithm
    floyd_warshall(graph);

    return 0;
}