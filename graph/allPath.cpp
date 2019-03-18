//#include<bits/stdc++.h>
// CPP program to print all paths of source to
// destination in given graph
#include <bits/stdc++.h>
using namespace std;

// utility function for printing
// the found path in graph
void printpath(vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		cout << path[i] << " ";
	cout << endl;
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
  int u = inde
	queue<vector<int> > q;

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
		for (int i = 0; i < g[last].size(); i++) {
			if (isNotVisited(g[last][i], path)) {
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}

// driver program
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

	return 0
