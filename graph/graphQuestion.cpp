#include<bits/stdc++.h>
using namespace std;
#include<queue>
typedef pair<int,int> ipair;
class graph{
private:
  int vertices;
  list<pair<int,int>> *adj;
public:
  graph(int v){
    adj = new list<ipair>[v];
    vertices = v;
  }
  void addEdge(int u,int v,int w ){
    adj[u].push_back(v,w);
    adj[v].push_back(u,w);
  }


//prims minimum spanning tree
  void prims(){
    priority_queue<ipair> pq;

    vector<int>parent(vertices,-1);
    vector<bool>checked(vertics,false);
    vector<int>dist(vertices,INT_MAX);
    int source = 0;
    pq.push(make_pair(0,source));
    dist[src] =0;
    while(!pq.empty()){
      int u = pq.top().second;
      //int weight = pq.top().first;
      checked[u] = true;
      parent
      pq.pop();
      list<ipair>:: iterator iter;
      for(iter = adj[u].begin();iter != adj[u].end();++iter){
        int v = iter->first;
        int weight = iter->second;
        if(weight < dist[v]){
          dist[v] = weight;
          pq.push(make_pair(weight,v));
          parent[v] = u;
        }

      }
    }
    for(int i = 0;i<vertices;i++){
      cout<<i<<"-"<<parent[i]<<endl;
    }

  }
// dfs helper finction
void dfsHelper(int v,vector<bool> &visited){
  list<ipair>:: iterator i;
  visited[v] = true;
  cout<<v<<endl;
  for(i = adj[v].begin();i != adj[v].end();i++){
    if(visited[i->first] == false){
    dfsHelper(i->first,visited);
    }
  }
}


//dfs for traversal
  void dfs(int s){
    vector<bool> visited(vertices,false);
    visited[s] = true;
    cout<<s<<endl;
    iterator<ipair>:: iterator itr;
    for(itr = adj[s].begin();itr != adj[s].end();i++){
      if(visited[itr->first] == false){
        dfsHelper(itr->first,visited);
      }
    }
  }

  //bfs
  void bfs(int s){
    vector<bool> visited(vertices,false);
  //  cout<<s<<" ";
    queue<int> q;


    q.push(s);
    while(!q.empty()){
      int u= q.front();
      cout<<s<<endl;
        visited[s] = true;
      q.pop();
      list<ipair>:: iterator i;
      for(i = adj[u].begin();i != adj[u].end();++i ){

      }
    }
  }
};
