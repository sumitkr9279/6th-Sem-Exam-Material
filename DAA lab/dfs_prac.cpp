#include<bits/stdc++.h>
using namespace std;
  void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&ans){
    ans.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,ans);
        }
    }
  }
int main (){
    int n,e;
    cout<<"Give number of vertices and edges"<<endl;
    cin>>n>>e;
    cout<<" give the graph "<<endl;
    vector<int>adj[n],vis(n,0);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<" dfs traversal is"<<endl;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int>ans;
             dfs(i,vis,adj,ans);
             for(auto it:ans){
                cout<<it<<" ";
             }
             cout<<endl;
        }
    }
    

return 0;
}
 