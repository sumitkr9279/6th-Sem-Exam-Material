#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int V, E;
vector<vector<int>> edgelist(E);

void display(vector<int> &dist, vector<int> &pred)
{
    cout << "Vert: ";
    for (int i = 0; i < V; i++)
        cout << setw(3) << i << " ";
    cout << endl;
    cout << "Dist: ";

    for (int i = 0; i < V; i++)
        cout << setw(3) << dist[i] << " ";
    cout << endl;
    cout << "Pred: ";

    for (int i = 0; i < V; i++)
        cout << setw(3) << pred[i] << " ";
    cout << endl;
}

bool bellmanFord(vector<int> &dist, vector<int> &pred, int src)
{
    dist[src] = 0;
    int icount = 1;
    while (icount < V)
    {
        for (int i = 0; i < E; i++)
        {
            int u = edgelist[i][0];
            int v = edgelist[i][1];
            int wt = edgelist[i][2];
            if (dist[u] != INT_MAX && (dist[u] + wt < dist[v]))
            {
                dist[v] = dist[u] + wt;
                pred[v] = u;
            }
        }
        icount++;
    }

    for (int i = 0; i < E; i++)
    {
        int u = edgelist[i][0];
        int v = edgelist[i][1];
        int wt = edgelist[i][2];
        if (dist[u] != INT_MAX && (dist[u] + wt < dist[v]))
            return true;        
    }
    return false;
}

int main()
{
    cout << "Enter no. of nodes and edges: " << endl;
    cin >> V >> E;
    cout << "Enter edge and its cost" << endl;
    vector<int> edges(3);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[0] >> edges[1] >> edges[2];
        edgelist.push_back(edges);
    }
    vector<int> dist(V, INT_MAX), pred(V, -1);
    int src, dest;
    bool report = false;
    cout << "Enter source node:\n";
    cin >> src;

    auto start = clock();
    report = bellmanFord(dist, pred, src);

    display(dist, pred);

    if (report)
        cout << "The graph has a negative cycle" << endl;
    else
        cout << "The graph has no negative cycle" << endl;
    
    float duration = clock() - start;
  duration = (duration) / CLOCKS_PER_SEC;
  cout << "Time taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;

    return 0;
}

// 0 1 6
// 0 2 7
// 1 2 8
// 1 3 5
// 1 4 -4 
// 2 3 -3
// 2 4 9
// 3 1 -2
// 4 0 2
// 4 3 7