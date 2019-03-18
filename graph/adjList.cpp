#include <iostream>
using namespace std;
#include <list>

class aList{
public:
	int vertex;
	list<int> edges;
	aList * next;

	aList(int vertex){
		this->vertex = vertex;
		next = NULL;
		
	}

}; 