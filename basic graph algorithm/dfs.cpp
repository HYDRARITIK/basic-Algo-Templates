#include<iostream>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;


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
	void dfsHelper(int node,bool *visited){
		visited[node] = true;
		cout<<node<<"->";

		//make a dfs call on all its unvisited neighbours
		for(int nbr : adj[node]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return;

	}

	void dfs(int source){
		bool *visited = new bool[V]{0};
		 for(int i=0;i<V;i++){
            if(!visited[i]){
                //for connected components
		        dfsHelper(source,visited);
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
    
	g.dfs(1);
	return 0;
}