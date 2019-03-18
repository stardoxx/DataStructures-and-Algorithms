#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<list>
#include<climits>
#include<utility>
#include<cstdlib>
using namespace std;
typedef pair <int,int> ipair;
typedef pair <float,int> ppair;
/*class person{
	string personName;
	string occupation;
	float salary;
	int experience;
public:
	person(name,occupation,salary,experience){

	}

};*/

class Graph{
	int V;
	string * name;
	list<ipair> * adj;
	int maxEdge;
public:
	//friend class person;
	Graph(int v,string s[])
	{
		V = v;
		name = new string[V];
		for(int i=0;i<V;i++)
		{
			name[i] = s[i];
		}
		adj = new list<ipair>[V];
		maxEdge = 0;
	}
	Graph(){

	}
	void initialize(int v,string s[])
	{
		V = v;
		name = new string[V];
		for(int i=0;i<V;i++)
		{
			name[i] = s[i];
		}
		adj = new list<ipair>[V];
	}
	void addEdge(int u,int v,int weight)
	{
		adj[u].push_back(make_pair(weight , v));
		adj[v].push_back(make_pair(weight , u));
		if(maxEdge > w){
			maxEdge = w;
		}
	}
	void show()
	{
		list<ipair>::iterator j;
		for(int i=0;i<V;i++)
		{
			cout<<name[i]<<" is connected to"<<endl;
			for( j = adj[i].begin();j!=adj[i].end();j++)
			{
				cout<<"  "<<name[(*j).second]<<"  weight "<<(*j).first<<endl;
			}
		}
	}
	void showstring()
	{
		for(int i=0;i<V;i++)
		{
			cout<<name[i]<<"  ";
		}
		cout<<endl;
	}
	int giveIndexOfData(string nameToSearch)
	{

		int index = -1;
		for(int i = 0;i<V;i++)
		{
			if(name[i] == nameToSearch)
			{
				index = i;
			}
		}
		return index;
	}

	void directFriends(string name1)
	{
		int index = giveIndexOfData(name1);
		if(index>=0){
		priority_queue<ipair> pq;
		list <ipair>::iterator it;
		for(it = adj[index].begin();it!=adj[index].end();it++)
		{
			ipair z = *it;
			pq.push(z);
		}
		while(!pq.empty())
		{
			ipair z = pq.top();
			pq.pop();
			cout<<name[z.second]<<"  ";
		}
		}else{
		    cout<<"given name not found";
            return;
		}
	}
	void suggestedFriends(string sname)
	{
//gives the indes of friend's name
		int index =  giveIndexOfData(sname);
		if(index>=0){
		priority_queue <ipair> pq;
		priority_queue <ipair> q;
		bool * visited = new bool[V];
		for(int i= 0;i<V;i++){
			visited[i] = false;
		}
		list<ipair>::iterator it;
		visited[index] = true;
		ipair z;
		for(it = adj[index].begin();it != adj[index].end();it++){
			int x = (*it).first;
			int y = (*it).second;
			z = make_pair(x,y);
			q.push(z);
			visited[(*it).second] = true;
		}
		ipair temp;
		ipair temp1;
		while(!q.empty()){
			temp = q.top();
			q.pop();
			for(it = adj[temp.second].begin();it != adj[temp.second].end();it++){
				if(!visited[(*it).second]){
					temp1 = *it;
					visited[(*it).second] = true;
					pq.push(temp1);
				}
			}

		}
		while(pq.size() != 0){
			z = pq.top();
			cout<<name[z.second]<<" ";
			pq.pop();
		}
		}
		else{
            cout<<"Given name not found";
            return;
		}
	}
	void friendRoute(string name1 , string name2)
	{
		int u = giveIndexOfData(name1);
		int v = giveIndexOfData(name2);
		if(u>=0 && v>=0){
		int distance[V];
		int parent[V];
		priority_queue <ipair,vector<ipair>,greater<ipair>> pq;
		for(int i=0;i<V;i++)
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
				if(distance[vertex] > (distance[parentVertex] + (maxEdge-weight))
				{
					distance[vertex] = distance[parentVertex] +(maxEdge - weight);
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
			cout<<name[s.top()];
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
 /// contribution of a person to the network
/* void contribution(){
 	int maximum = V ;

 	for(int i = 0;i<V;i++){
 		float conn = 0;
 		list<ipair>:: iterator n;
 		for(n = adj[i].begin();n != adj[i].end();++n){
 			conn += 1;
 		}
 		float avg = conn/vertices;
 		float percentContribute = avg*100;
 		cout<<name[i]<<" contribution: "<<percentContribute<<" %"<<endl;
 	}
}*/
	///

};

int main()
{
    int input;
 	int vertex;
 	Graph g;

 	while(true)
    {
        system("cls");
        cout<<"Enter the input accordingly : \n";
        cout<<"Press 1: for predefined graph \n";
        cin>>input;
        if(input==1)
        {
            system("cls");
            int type;
            cout<<"please select the graph : \n";
            cout<<"Press 1: Graph sasuke \n";
            cout<<"Press 2: Graph naruto \n";
            cin>>type;
            while(true)
            {
                if(type ==1)
                {
                    system("cls");
                    vertex = 12;
                    string * name = new string[vertex];
                    name[0] = "ashutosh";
                    name[1] = "saransh";
                    name[2] = "harsh";
                    name[3] = "ashish";
                    name[4] = "nishant";
                    name[5] = "ravi";
                    name[6] = "kira";
                    name[7] = "piyush";
                    name[8] = "lawliet";
                    name[9] = "shiv";
                    name[10] = "sanskar";
                    name[11] = "swapnil";

                    g.initialize(vertex,name);

                    g.addEdge(0,1,13);
                    g.addEdge(0,2,13);
                    g.addEdge(0,5,1);
                    g.addEdge(0,9,3);
                    g.addEdge(0,7,2);
                    g.addEdge(0,3,6);
                    g.addEdge(1,3,2);
                    g.addEdge(1,8,4);
                    g.addEdge(1,2,4);
                    g.addEdge(1,5,8);
                    g.addEdge(2,3,2);
                    g.addEdge(2,6,5);
                    g.addEdge(2,4,3);
                    g.addEdge(2,5,6);
                    g.addEdge(3,7,5);
                    g.addEdge(4,5,15);
                    g.addEdge(4,6,7);
                    g.addEdge(5,6,9);
                    g.addEdge(6,11,5);
                    g.addEdge(7,8,3);
                    g.addEdge(8,10,15);
                    break;
                }
                else if(type==2)
                {
                    //graph 2 .........................................................
                    system("cls");
                    int vertex = 10;
                    string * name = new string[vertex];
                    name[0] = "ashutosh";
                    name[1] = "saransh";
                    name[2] = "harsh";
                    name[3] = "piyush";
                    name[4] = "lawliet";
                    name[5] = "kira";
                    name[6] = "ashish";
                    name[7] = "sanskar";
                    name[8] = "shiv";
                    name[9] = "manas";

                    g.initialize(vertex,name);

                    g.addEdge(0,1,2);
                    g.addEdge(0,3,5);
                    g.addEdge(0,2,1);
                    g.addEdge(1,4,4);
                    g.addEdge(1,7,3);
                    g.addEdge(2,5,10);
                    g.addEdge(3,6,1);
                    g.addEdge(3,7,2);
                    g.addEdge(4,8,6);
                    g.addEdge(5,6,5);
                    g.addEdge(6,9,2);
                    g.addEdge(7,8,1);
                    g.addEdge(7,9,6);
                    break;
                }

            }
                break;
        }

        // user entered graph ..........................................................
        else{
            cout<<"Enter the valid input \n";
        }
    }

    //// functionality dashBoard............................................................................

    while(true)
    {
        system("cls");
        cout<<"...............Welcome to Graph World.............. \n";
        cout<<"Press 1: Show all the vertices \\ persons. \n";
        cout<<"Press 2: Show all the links. \n";
        cout<<"Press 3: Show all the connections according to weight \n";
        cout<<"Press 4: Show all suggested friends \n";
        cout<<"Press 5: To quit \n";
        cin>>input;
        if(input==1)
        {
            system("cls");
            int flag;
            g.showstring();
        }
        else if(input==2)
        {
            system("cls");
            int flag;
            g.show();
            cout<<"\n press 5 for exit \n";
        }
        else if(input==3)
        {
            system("cls");
            int flag;
            string info1;
            string info2;
            cout<<"Enter names to find route \n";
            cout<<"Enter name 1: \n";
            cin>>info1;
            transform(info1.begin(), info1.end(), info1.begin(), ::tolower);
            cout<<"\nEnter name 2: \n";
            cin>>info2;
            transform(info2.begin(), info2.end(), info2.begin(), ::tolower);
            g.friendRoute(info1,info2);
            cout<<"\n press 5 for exit \n";
        }
        else if(input==4)
        {
            system("cls");
            int flag;
            string info;
            transform(info.begin(), info.end(), info.begin(), ::tolower);
            cout<<"Enter the name for Suggested Friends :\n";
            cin>>info;
            g.suggestedFriends(info);

        }
        else if(input==5)
        {
        	break;
        }

        else{
        	cout<<"Please Enter correct Input\n";
        }
    }




}
