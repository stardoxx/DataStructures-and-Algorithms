#include<iostream>
using namespace std;
#include<list>
#include<vector>
class graph{
  int vertices;
  list<int> *adj;
public:
  graph(int v){
    vertices = v;
    adj = new list<int>[v];
  }
  void addEdge(int a,int b){
    adj[a].push_back(b);
  }
  //traversal
  void dfsUtill(int v, bool visited[]){
    visited[v] = true;
    cout<<v<<" ";

    list<int>:: iterator i;
    for(i = adj[v].begin(); i != adj[v].end();++i){
      if(!visited[*i]){
        dfsUtill(*i,visited);
      }
    }
  }
  //dfs
  void dfs(int v){
    bool *visited = new bool[vertices];
    for(int i= 0;i< vertices;i++){
      visited[i] = false;
    }
    dfsUtill(v,visited);
  }
//------function for shortest path using bfs--///
  bool bfs(int s,int dest,int pred[],int dist[]){
    list<int> queue;
    bool visited[vertices];
    for(int i =0;i<vertices;i++){
      visited[i] = false;
      dist[i] = INT_MAX;
      pred[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
    queue.push_back(s);
    while(!queue.empty()){
      int u = queue.front();
      queue.pop_front();
      for(int i = 0;i<adj.size();i++){
        if(visited[adj[u][i]] == false){
          visited[adj[u][]]
        }
      }
    }

  }

  void shortestPath(int s,int dest){
    int pred[vertices],dist[vertices];
    if(bfs(s,dest,dist,pred) == false){
      cout<<"given source and destination are not connected"<<endl;
      return;
    }
    int crawl = dest;
    vector<int>path;
    path.push_back(crawl);
    while(pred[crawl] != -1){
      path.push_back(pred[crawl]);
      crawl = pred[crawl];
    }
    cout<<"path is "<<endl;
    for(int i = path.size();i>=0;i--){
      cout<<path[i]<<" ";
    }
  }

};

int main(){
  graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);
  g.dfs(2);

  return 0;
}
