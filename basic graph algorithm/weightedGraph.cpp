#include<iostream>
#include<list>
#include<set>
#include<bits/stdc++.h>

using namespace std;

class Graph{

	int V;
    map<int,vector<pair<int,int>>> adj;

public:
	Graph(int v){
		V = v;
	}

	void addEdge(int u,int v,int wt,bool undir = true){

		adj[u].push_back({wt,v});
		if(undir){
			adj[v].push_back({wt,u});
		}
	}
    

};

int main(){

	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);




}