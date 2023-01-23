#include<iostream>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

//work for both directed and undirected 




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
    bool cycleFound=false;


	void dfsHelper(int node,int *visited,int parent){

		visited[node] = 1;   // 1 means  it is in call stack
		// cout<<node<<"->";

		//make a dfs call on all its unvisited neighbours
		for(int nbr : adj[node]){
			if(visited[nbr]==0){
                //0 means not visited
				dfsHelper(nbr,visited,node);
			}else if(visited[nbr]==1 && nbr!=parent){
                //it is backedge
                cout<<"backedge b/w="<<node<<"->"<<nbr<<endl;
                cycleFound=true;
            }

		}
            //after leaving recursion stack mark it as 2
            visited[node]=2;
		return;

	}

	void dfs(int source){
		int *visited = new int[V]{0};

        for(int i=0;i<V;i++){
            if(!visited[i]){
		        dfsHelper(source,visited,-1);

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