#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void prepareAdjlist(unordered_map<int, set<int>> &adjlist, vector<pair<int, int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int,bool> &visited,
            vector<int> &ans, int node)
{    
    Sleep(1);
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto x:adjlist[frontnode])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

int main()
{
    int V,E;
    cout << "Enter the no. vertices and edges\n";
    cin >> V >> E;

    unordered_map<int, set<int>> adjlist;
    vector<pair<int, int>> edges;
    unordered_map<int,bool> visited;

    cout << "Enter the edges:\n";
    for (int i = 0; i < E; i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        edges.push_back(make_pair(temp1,temp2));
    }

    auto start = clock();
    prepareAdjlist(adjlist, edges);

    vector<int> ans;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            bfs(adjlist, visited, ans, i);
    }
    cout<<"BFS Traversal\n";
    for(auto x:ans)
        cout<<x<<" ";

    float duration = clock() - start;
  duration = (duration) / CLOCKS_PER_SEC;
  cout << "\nTime taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;

    return 0;
}

// 4 4
// 0 1
// 0 3
// 1 2
// 2 3