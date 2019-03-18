#include<iostream>
using namespace std;
#include<vector>
#include<list>

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
  //bfs traversal for graph
  void bfs(int v){
      bool *visited = new bool[vertices];
      for(int i =0;i<vertices;i++){
        visited[i] = false;
      }
      //queue for bfs
      list<int>queue;
      list<int>::iterator i;
      //current element mark as visited and enqueue
      visited[v] = true;
      queue.push_back(v);
      while(!queue.empty()){
        v = queue.front();
        queue.pop_front();
        cout<<v<<" ";
        for(i = adj[v].begin();i != adj[v].end();++i){
          if(!visited[*i]){
          visited[*i] = true;
          queue.push_back(*i);
        }
      }
      }
  }
};

int main(){
   graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);
   g.bfs(1);

  return 0;
}
