#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

static int V;

int minDistance(vector<int> dist, vector<bool> sptSet)
{
    Sleep(1);
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(vector<int> dist)
{
    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t" << dist[i] << endl;
}

void dijkstra(vector<vector<int>> graph)
{
    Sleep(1);
    vector<int> dist(V);
    vector<bool> sptSet(V);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + 
                    graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main()
{
    int E;
    cout << "Enter the no. vertices and edges\n";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the edges followed by its weight:\n";
    for (int i = 0; i < E; i++)
    {
        vector<int> edgewt(3);
        for (int j = 0; j < 3; j++)
            cin >> edgewt[j];
        graph[edgewt[0]][edgewt[1]] = edgewt[2];
    }

    auto start = clock();

    dijkstra(graph);

    float duration = clock() - start;
  duration = (duration) / CLOCKS_PER_SEC;
  cout << "Time taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;

    return 0;
}