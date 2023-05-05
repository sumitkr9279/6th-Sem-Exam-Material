#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

static int V;

int minKey(vector<int> key, vector<bool> mstSet)
{
 Sleep(1);
 int min = INT_MAX, min_index;

 for (int v = 0; v < V; v++)
  if (mstSet[v] == false && key[v] < min)
   min = key[v], min_index = v;

 return min_index;
}

void printMST(vector<int> parent, vector<vector<int>> graph)
{
 cout << "\nEdge \tWeight\n";
 int sum=0;
 for (int i = 1; i < V; i++){
  cout << parent[i] << " - " << i << " \t"
   << graph[i][parent[i]] << " \n";
   sum +=graph[i][parent[i]];}
   cout<<"Total MST weight: \n"<<sum;
}

void primMST(vector<vector<int>> graph)
{
 Sleep(1);
 vector<int> parent(V);
 vector<int> key(V);
 vector<bool> mstSet(V);

 for (int i = 0; i < V; i++)
  key[i] = INT_MAX, mstSet[i] = false;

 key[0] = 0;
 parent[0] = -1; 

 for (int count = 0; count < V - 1; count++) {
  int u = minKey(key, mstSet);

  mstSet[u] = true;

  for (int v = 0; v < V; v++)

   if (graph[u][v] && mstSet[v] == false
    && graph[u][v] < key[v])
    parent[v] = u, key[v] = graph[u][v];
 }
 printMST(parent, graph);
}

int main()
{ 
 int E;
 cout<<"Enter the no. vertices and edges\n";
 cin>>V>>E;

 vector<vector<int>> graph(V,vector<int> (V,0));
 cout<<"Enter the directed edges followed by weight:\n"; 
 for(int i=0;i<E;i++)
 { 
  vector<int> edgewt(3); 
  for(int j=0;j<3;j++)
   cin>>edgewt[j];
  graph[edgewt[0]][edgewt[1]]=edgewt[2];
  graph[edgewt[1]][edgewt[0]]=edgewt[2]; 
 }
 auto start = clock();

 primMST(graph);
 
 float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
 cout<<"\nTime taken by function: " << setprecision(20) << fixed << duration << " seconds" << endl;
 return 0;
}