#include<iostream>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

//work for both directed and undirected 




class Graph{

	int V;
    map<int,vector<int>>adj;
	int *discovery;
	int *low;//bfs tree path ko ignore karke aap kis lowest discovered node ko touch 
	//kar pa rahe
	bool *articulation;
	vector<pair<int,int>>bridges;

public:
	Graph(int v){
		V = v;
		discovery=new int[V];
		low=new int[V];
		articulation=new bool[V];
		for(int i=0;i<V;i++){
			
			discovery[i]=-1;
			low[i]=-1;
			articulation[i]=false;
		}
		bridges={};

	}
    
	void addEdge(int i,int j,bool undir=true){
		adj[i].push_back(j);
		if(undir){
			adj[j].push_back(i);
		}
	}
    bool cycleFound=false;


	void dfsHelper(int node,int *visited,int parent,int time){

		visited[node] = 1;   // 1 means  it is in call stack
		this->discovery[node]=time;
		this->low[node]=time;
		// cout<<node<<"->";
		
		//make a dfs call on all its unvisited neighbours
		for(int nbr : adj[node]){
			if(visited[nbr]==0){
                //0 means not visited
				dfsHelper(nbr,visited,node,time+1);
			}else if(visited[nbr]==1 && nbr!=parent){
                //it is backedge
                cout<<"backedge b/w="<<node<<"->"<<nbr<<endl;
                cycleFound=true;
				low[node]=min(low[node],discovery[nbr]);
            }
			else{
				continue;
			}
			//backtracking
			low[node]=min(low[node],low[nbr]);
			//checking articulation point
			if(low[nbr]>=discovery[node]){
				//means mera nbr  path me mere se pahle kisi bhi discovered node ko touch nahi kar rha
				//for source node this condition is always true so we have to make another 
				//check for source node
				//ie: we will see how many time we have to call dfs(from source) (if it is one time and we visit all nodes)
				//(in one go this means other node is connected via diff. path ,so im not articulation point)
				articulation[node]=true;

			}


		}
            //after leaving recursion stack mark it as 2
            visited[node]=2;
		return;

	}

	void dfsHelperBridges(int node,int *visited,int parent,int time){

		visited[node] = 1;   // 1 means  it is in call stack
		this->discovery[node]=time;
		this->low[node]=time;
		// cout<<node<<"->";
		
		//make a dfs call on all its unvisited neighbours
		for(int nbr : adj[node]){
			if(visited[nbr]==0){
                //0 means not visited
				dfsHelperBridges(nbr,visited,node,time+1);
			}else if(visited[nbr]==1 && nbr!=parent){
            
                cycleFound=true;
				low[node]=min(low[node],discovery[nbr]);
            }
			else{
				continue;
			}
			//backtracking
			low[node]=min(low[node],low[nbr]);
			//checking bridges
			if(low[nbr]>discovery[node]){
				
				//here we remove equality signs because if nbr is reachable to node than it is not bridge
				bridges.push_back({node,nbr});

			}


		}
            //after leaving recursion stack mark it as 2
            visited[node]=2;
		return;

	}

	void dfs(int source){
		int time=0;
		int *visited = new int[V];
	
		for(int i=0;i<V;i++){
			visited[i]=false;
			discovery[i]=-1;
			low[i]=-1;
		}
		int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
		        // dfsHelper(source,visited,-1,time);
				dfsHelperBridges(source,visited,-1,time);
				count++;
            }
        }
		if(count==1){
			this->articulation[source]=false;
		}
	}
	int totalArticulationPoints(){
		int counter=0;
		for(int i=0;i<V;i++){
			
		if(this->articulation[i]){
			counter++;
		}
		}
		return counter;
	}

	void printBridges(){
		for(int i=0;i<bridges.size();i++){
			cout<<bridges[i].first<<"->"<<bridges[i].second<<endl;
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

	// cout<<g.totalArticulationPoints()<<endl;

	g.printBridges();

	return 0;
}