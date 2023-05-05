#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<pair<int,int>> adj[],int src,int n){
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(auto i:adj[u.second]){
            if(i.second+u.first<dist[i.first]){
                dist[i.first]=i.second+u.first;
                pq.push({dist[i.first],i.first});
            }
        }
    } 
    return dist;
}

int main(){
    int n,edges;
    cout<<" give number of vertices and edges"<<endl;
    cin>>n>>edges;
    cout<<" provide the graph"<<endl;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> dist=dijkstra(adj,0,n);
    cout<<"node -> "<<"Distance"<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<" "<<i<<"        "<<dist[i]<<endl;
    }

}