#include<bits/stdc++.h>
using namespace std;
#include<queue>
typedef pair<int,int>ipair;


class person{
  string personName;
  string occupation;
  float salary;
  int experience;
  string specification;
public:
  friend class graph;
  person(string personName,string occupation,float salary,int experience,string specification){
    this->personName = personName;
    this->occupation = occupation;
    this->salary = salary;
    this->experience = experience;
    this->specification = specification;
  }

  person()
  {
    personName = "";
    occupation = "";
    salary = 0;
    experience = 0;
    specification = "";
  }
   void setDetail(string personName,string occupation,float salary,int experience,string specification){
    this->personName = personName;
    this->occupation = occupation;
    this->salary = salary;
    this->experience = experience;
    this->specification = specification;
  }


};

class graph{
  int vertices;
  list<pair<int,int>> *adj;
  person * people;
  map<string,int> indexMap;
  int maxEdge;
  stack < vector <int> > fr;
public:
  friend class person;
  graph(int v){
    maxEdge =0;
    vertices = v;
    adj = new list<ipair> [v];
    people = new person[v];
    for(int i = 0;i < v;i++){
      cout<<"enter person details "<<i<<endl;
      cout<<"enter name, occupation,income,years,specification"<<endl;
      int years;
      string name,occupation;
      float income;
      string speci;
      cin>>name>>occupation>>income>>years>>speci;
      people[i].setDetail(name,occupation,income,years,speci);
      indexMap.insert(make_pair(name,i));
    }
  }

  void addEdge(int u ,int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
    if(w > maxEdge){
      maxEdge = w;
    }
  }

  int indexOfname(string name1){
    map<string,int>::iterator itr;
    itr = indexMap.find(name1);
    int index = itr->second;
    return index;
  }

//functionality for friends of a person
  void directFriends(string name1)
  {

    int index = indexOfname(name1);
    if(index>=0){
      priority_queue<ipair> pq;
      list <ipair>::iterator it;
      for(it = adj[index].begin();it!=adj[index].end();it++)
        {
            int u = it->first;
            int weight = it->second;
            pq.push(make_pair(weight,u));
        }
        while(!pq.empty())
        {
          int v  = pq.top().second;
          cout<<people[v].personName<<" ";
          pq.pop();
        }
        cout<<endl;
    }
    else{
        cout<<"given name not found";
            return;
    }
  }
  void contribution(){
    int maximum = vertices ;
    if(maximum){
    for(int i = 0;i<vertices;i++){
      float conn = 0;
      list<ipair>:: iterator n;
      for(n = adj[i].begin();n != adj[i].end();++n){
        conn  +=1;
      }
      float avg = conn/vertices;
      float percentContribute = avg*100;
      cout<<percentContribute<<endl;
    }
    }
    else{
      cout<<"no data to check for contribution"<<endl;
    }
  }
  //decisionTree for job prediction
  int decisionTree(int index,string mostPaid,float highSalary){
    float sal = people[index].salary;
    float increment = sal/highSalary;
    float percentIncement = sal-(increment*100);
    if(people[index].experience > 15){
      if(percentIncement >= 60.00){
        return 1;
      }
      else if((percentIncement >20.00) &&(percentIncement < 60.00)){
        return 2;
      }
      else{
        return 3;
      }
    }
    else if((people[index].experience >5)&& (people[index].experience < 15) ){
      if(percentIncement > 30.00){
        return 1;
      }
      else if( (percentIncement >15.00) && (percentIncement > 30.00) ){
        return 2;
      }
      else{
        return 3;
      }
    }
    else{
      if(people[index].experience >= 30.00){
        return 1;
      }
      else if((people[index].experience >5.00) && (people[index].experience <30.00)){
        return 2;
      }
      else{
        return 1;
      }
    }
  }
  //method for printing the final output of the predictions
  void prediction(int certainity,int index,string mostPaid){
    if(certainity == 1){
      cout<<people[index].personName<<" very high probability of job change from "<<people[index].specification<<" to "<<mostPaid<<endl;
    }
    if(certainity == 2){
      cout<<people[index].personName<<" moderate probability of job change from "<<people[index].specification<<" to "<<mostPaid<<endl;
      cout<<"         rest depends on situations"<<endl;
    }
    if(certainity == 3){
        cout<<people[index].personName<<" probability of job change is not so likely  "<<endl;
        cout<<"         depends on probability of promotion"<<endl;
    }
  }



//method for checking jobCertainity
  void jobCertainity(string name2){
    int index = indexOfname(name2);
    int highSalary= people[index].salary;
    string mostPaid = people[index].specification;
    list<ipair>:: iterator itr;
    for(itr = adj[index].begin();itr != adj[index].end();++itr){
      int i = itr->first;

      if((people[i].occupation == people[index].occupation) &&(people[i].specification != people[index].specification && (people[i].salary >people[index].salary))){
        highSalary = people[i].salary;
        mostPaid = people[i].specification;
      }
    }
    if(people[index].specification != mostPaid){
      int certainity =  decisionTree(index,mostPaid,highSalary);
        prediction(certainity,index,mostPaid);
      }
    else{
      cout<<people[index].personName<<"'s job "<<people[index].specification<<" is stable"<<endl;
    }
  }
/*
  void friendRoute(string name1 , string name2)
  {
    int u = indexOfname(name1);
    int v = indexOfname(name2);
    if(u>=0 && v>=0){
      list<ipair> *adj2 = new list<ipair>[vertices];
    for(int i = 0;i<vertices;i++ ){
      list<ipair>:: iterator itr1;
      for(itr1 = adj[i].begin();itr1 != adj[i].end();++itr1){
        adj2[i].push_back(make_pair(itr1->first,(maxEdge-(itr1->second)+1)));
      }
    }
    int distance[vertices];
    int parent[vertices];
    priority_queue <ipair,vector<ipair>,greater<ipair>> pq;
    for(int i=0;i<vertices;i++)
    {
      parent[i] = -1;
      distance[i]  = INT_MAX;
    }
    distance[u] = 0;
    pq.push(make_pair(0,u));
    ipair temp;
    ipair temp1;
    list <ipair>::iterator it;
    while(!pq.empty())
    {
      temp = pq.top();
      pq.pop();
      int parentWeight = temp.first;
      int parentVertex = temp.second;
      for(it = adj[parentVertex].begin();it!=adj[parentVertex].end();it++)
      {
        ipair temp1 = *it;
        int weight = temp1.first;
        int vertex = temp1.second;
        if(distance[vertex] > distance[parentVertex]+ weight)
        {
          distance[vertex] = distance[parentVertex] +weight;
          parent[vertex] = parentVertex;
          pq.push(make_pair(distance[vertex], vertex));
        }
      }
    }
    stack <int > s;
    int x = v;
    s.push(v);
    while(parent[x] != -1)
    {
      s.push(parent[x]);
      x = parent[x];
    }
    while(!s.empty())
    {
      int p = s.top();
      cout<<people[p].personName<<endl;
      s.pop();
      if(!s.empty()){
        cout<<" >> ";
      }
    }
    }
    else{
            cout<<"Given names not found "<<endl;
            return;
    }
  }
*/
  // CPP program to print all paths of source to
// destination in given graph
//#include <bits/stdc++.h>
//using namespace std;

// utility function for printing
// the found path in graph
void printpath(vector<int>& path)
{
	int size = path.size();
  if(fr.empty() == true){
    fr.push(path);
  }
  else{
    vector <int> temp = fr.top();
    int l1 = temp.size();
    int l2 = path.size();
    if(l2 == l1)
    {
      fr.push(path);
    }
    else if(l1>l2){
      while(!fr.empty())
      {
        fr.pop();
      }
      fr.push(path);
    }
    else{
      return;
    }
    return;
  }
}

int findWeights(int u,int v)
{
  list<ipair>:: iterator it;
  for(it=adj[u].begin();it!=adj[u].end();it++)
  {
    if(it->first == v)
    {
      return it->second;
    }
  }
  return -1;
}


 routeFriend()
{
  int max = 0;
  int sum = 0;
   multimap < int, vector < int > > match;
  while(!fr.empty())
  {
      sum = 0;
      vector<int> temp = fr.top();
      fr.pop();
      list<ipair>:: iterator it;
      int l1 = temp.size();
      int j = 1;
      while(j<l1)
      {
        int i = j-1;
        int ww = findWeights(i,j);
        if(ww!=-1)
        {
          sum += ww;
        }
      }
      if(max < sum)
      {
        max = sum;
      }
      match.insert(make_pair(sum , temp));
  }
  multimap < int, vector < int > >::iterator iit;
  iit = match.find(max);
  vector <int> flag = 

}

// utility function to check if current
// vertex is already present in path
int isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}

// utility function for finding paths in graph
// from source to destination
void findpaths(string name1,string name2)
{
	// create a queue which stores
	// the paths
  int src = indexOfname(name1);
  int dst = indexOfname(name2);
	queue< vector <int> > q;

	// path vector to store the current path
	vector<int> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		// if last vertex is the desired destination
		// then print the path
		if (last == dst)
			printpath(path);

		// traverse to all the nodes connected to
		// current vertex and push new path to queue
    list<ipair> :: iterator i;
		for ( i = adj[last].begin();i != adj[last].end();++i) {
			if (isNotVisited(i->first, path)) {
				vector<int> newpath(path);
				newpath.push_back(i->first);
				q.push(newpath);
			}
		}
	}
}

// driver program
/*
int main()
{
	vector<vector<int> > g;
	// number of vertices
		int v = 5;
	g.resize(9);

	// construct a graph
	g[0].push_back(1);
  	g[1].push_back(0);
  	g[1].push_back(3);
  	g[3].push_back(1);
  	g[0].push_back(2);
  	g[2].push_back(0);
  	g[3].push_back(5);
  	g[5].push_back(3);
  	g[2].push_back(3);
	g[3].push_back(2);
  	g[2].push_back(4);
	g[4].push_back(2);
  	g[5].push_back(4);
	g[4].push_back(5);
  	g[5].push_back(6);
	g[6].push_back(5);
	g[6].push_back(7);
	g[7].push_back(6);
  	g[8].push_back(7);
	g[7].push_back(8);
  g[8].push_back(6);
	g[6].push_back(8);
  //g[7].push_back(5);
	//g[5].push_back(7);
  int src = 0, dst = 1;
	cout << "path from src " << src
		<< " to dst " << dst << " are \n";

	// function for finding the paths
	findpaths(g, src, dst, v);

	return 0*/

};


int main(){

graph g(5);
g.addEdge(1-1,2-1 ,3);
g.addEdge(1-1,4-1,5);
g.addEdge(1-1,3-1,4);
g.addEdge(2-1,3-1,3);
g.addEdge(3-1,5-1,2);
g.addEdge(4-1,5-1,6);
g.addEdge(2-1,5-1,4);
//g.jobCertainity("A");
g.findpaths("A","D");
}
