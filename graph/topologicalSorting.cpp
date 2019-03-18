#include<iostream>
#include<stack>
#include<list>

using namespace std;
class graph{
  int V;//o. of vertices
  list<int>* adj;
public:
  graph(int v){
    this->V = v;
    adj = new list<int>[v];
  }
  void addEdge(int v, int w){
      adj[v].push_back(w);
  }

  void tSortHelp(int v,bool visited[],stack<int> &s){
    visited[v] =true;
    list<int>::iterator i;
    for(i = adj[v].begin();i != adj[v].end();++i){
      if(!visited[*i]){
        tSortHelp(*i,visited,s);
      }
    }
    s.push(v);
  }


  void tSort(){
    stack<int> s;
    bool *visited = new bool[V];
    for(int i =0;i,V;i++){
      visited[i] = false;
    }

    for(int i = 0;i<V;i++){
      if(visited[i] == false){
        tSortHelp(i,visited,s);
      }
    }
    while(s.empty() == false){
      cout<<s.top()<<endl;
      s.pop();
    }

  }

 //strongly coneected components
 /*void scc(){
   stack<int> s;
   bool *visited = new bool[V];
   for(int i =0;i<V;i++){
     visited[i] =false;
   }
   for(int i)
 }*/

};

int main(){
  graph g(6);
  g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
  cout<<"topologically Sorted order"<<endl;
  g.tSort();
  return 0;
}
