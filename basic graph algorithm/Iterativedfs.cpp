#include<iostream>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

//algo      remove->->mark *->do work-> add neighbours 

class Graph{

	int V;
	map<int,vector<int>>adj;

public:
	Graph(int v){
		V = v;
		
	}

	void addEdge(int i,int j,bool undir=true){
		adj[i].push_back(j);
		if(undir){
			adj[j].push_back(i);
		}
	}
	void Iterativedfs(int source){

		stack<int> q;
		bool *visited = new bool[V]{0};

		q.push(source);
	

		while(!q.empty()){
            // ** pop node ,do some work , add neighbours to queue
			//Do some work for every node
			
			int f = q.top();
			q.pop();

			if(visited[f])continue;

			visited[f]=true;
			cout<<f <<"->";

			//PUsh the nbrs of current node inside q if they are not already visited
			for(auto nbr : adj[f]){
				if(!visited[nbr]){
					q.push(nbr);
					// visited[nbr]=true;
				}
			}
		}

	}
	
	

};

int main(){
Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
    
	g.Iterativedfs(1);
	return 0;
}



