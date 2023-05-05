#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

static int V;

void printgraph(vector<vector<int>> &graph, vector<vector<int>> &parent)
{
    bool cycle = false;
    for (int i = 0; i < V; i++)
        if (graph[i][i] < 0)
            cycle = true;
    cout << ((cycle) ? "Negative cycle present" : "No negative cycles present");    
}

void floydWarshall(vector<vector<int>> &graph, vector<vector<int>> &parent)
{
    // Sleep(1);
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    cout << "\nCost Matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] < 0)
                cout << graph[i][j] << " ";
            else
                cout << " " << graph[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nPredecessor Matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (parent[i][j] < 0)
                cout << parent[i][j] << " ";
            else
                cout << " " << parent[i][j] << " ";
        }
        cout << endl;
    }

    printgraph(graph, parent);
}

void srcdest(vector<vector<int>> &graph, vector<vector<int>> &parent)
{
    int src, dest;
    cout << "\nEnter source and destination node\n";
    cin >> src >> dest;
    cout << "cost: " << graph[src][dest] << "\npredecessor: " << parent[src][dest] << "\n";
    int i = src, j = dest;
    string route = "";
    while (parent[i][j] != i && parent[i][j] != j)
    {
        route = char(parent[i][j] + '0') + route;
        route = "->" + route;
        j = parent[i][j];
    }
    route = char(src + '0') + route;
    route = route + "->" + char(dest + '0');
    route = "Route: " + route;
    cout << route << "\n";
}

int main()
{
    int E;
    cout << "Enter the no. vertices and edges\n";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 1e8));
    vector<vector<int>> parent(V, vector<int>(V, -1));
    for (int i = 0; i < V; i++)
        graph[i][i] = 0;
    cout << "Enter the edges followed by its weight:\n";
    for (int i = 0; i < E; i++)
    {
        vector<int> edgewt(3);
        for (int j = 0; j < 3; j++)
            cin >> edgewt[j];
        graph[edgewt[0]][edgewt[1]] = edgewt[2];
        parent[edgewt[0]][edgewt[1]] = edgewt[0];
    }

    auto start = clock();

    floydWarshall(graph, parent);

    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    cout << "\nTime taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;  

    srcdest(graph, parent);  
}
// 0 1 3
// 0 4 -4
// 0 2 8
// 1 4 7
// 1 3 1
// 2 1 4
// 3 2 -5
// 3 0 2
// 4 3 6