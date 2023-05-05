#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

static int V;

bool cmp(vector<int> a, vector<int> b)
{
    return (a[2] < b[2]);
}

int findParent(vector<int> parent, int node) 
{
    Sleep(1);
    if(parent[node]==node) 
        return node;

    return (parent[node] = findParent(parent, parent[node]));
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    Sleep(1);
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
void kruskalMST(vector<vector<int>> &edges, vector<vector<int>> &f_edges, int &ans)
{
    Sleep(1);
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(V);
    vector<int> rank(V);
    for(int i=0; i<V ; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }

    int minWeight = 0;

    for(int i=0; i<edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt= edges[i][2];

        if(u != v)
        {
            f_edges.push_back({edges[i][0],edges[i][1],wt});
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    ans=minWeight;
    return;
}

int main()
{
    int E;
    cout << "Enter the no. vertices and edges\n";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter the edges followed by its weight:\n";
    for (int i = 0; i < E; i++)
    {
        vector<int> edgewt(3);
        for (int j = 0; j < 3; j++)
            cin >> edgewt[j];
        edges.push_back(edgewt);
    }

    auto start = clock();
    vector<vector<int>> f_edges;
    int ans;
    kruskalMST(edges, f_edges, ans);
    
    cout << "\nEdge \tWeight\n";
  for (auto x:f_edges)
  {        
        cout << x[0] << "  " << x[1] << " \t"
            << x[2] << " \n";        
    }

    cout<<"Min MST Weight = "<<ans<<endl;

    float duration = clock() - start;
  duration = (duration) / CLOCKS_PER_SEC;
  cout << "Time taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;

    return 0;
}