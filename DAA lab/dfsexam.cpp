#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void dfs(vector<int> &component, unordered_map<int,bool> &visited, int node, unordered_map<int, set<int>> &adj)
{
    component.push_back(node);
    visited[node]=1;
    for(auto x:adj[node])
    {
        if(!visited[x])
            dfs(component, visited, x, adj);
    }
}

int main()
{
    int V,E;
    cout << "Enter the no. of vertices and edges\n";
    cin >> V >> E;
    unordered_map<int, set<int>> adj;
    vector<pair<int, int>> edges;  

    cout << "Enter the edges:\n";
    for (int i = 0; i < E; i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        edges.push_back(make_pair(temp1,temp2));
    }

    auto start = clock();
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(component, visited,i, adj);
            ans.push_back(component);
        }
    }
    cout<<"Size of connected components:\n"<< ans.size();

    cout<<"\nDFS Traversal\n";
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    float duration = clock() - start;
  duration = (duration) / CLOCKS_PER_SEC;
  cout << "\nTime taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;
    return 0;
}

