
#include <iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int V;
    // vector<vector<int>> dp;
    bool *visited;
public:
    int ans;
    string path;

    Graph(int v)
    {
        V = v;
        visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        visited[0]=true;
        ans = INT_MAX;
        path="";
    }

 


//from gfg
    void tsp(vector<vector<int>> mat, int currPos, int count, int cost)
{

	
	if (count == V && mat[currPos][0]) {
		ans = min(ans, cost + mat[currPos][0]);
       
		return;
	}

	
	for (int i = 0; i < V; i++) {
		if (!visited[i] && mat[currPos][i]) {

			// Mark as visitedisited
			visited[i] = true;
			tsp(mat , i, count + 1,cost + mat[currPos][i]);

			// Mark ith node as unvisitedisited
			visited[i] = false;
		}
	}
};


   

    int tsp_dp(vector<vector<int>> mat, int currPos,vector<vector<int>> &dp,int setofcities){
        if(setofcities==(1<<V)-1){
            return mat[currPos][0];
        }
        if(dp[setofcities][currPos]!=-1){
            return dp[setofcities][currPos];
        }

        //else
        int global_ans=INT_MAX;
        for(int choice=0;choice<V;choice++){
            if((setofcities & (1<<choice))==0){
                
                int subprob=mat[currPos][choice]+tsp_dp(mat,choice,dp,setofcities | (1<<choice));
                global_ans=min(global_ans,subprob);
            
            }
        }

        return dp[setofcities][currPos]=global_ans;


    }









};

int main()
{
    int V = 4;
    Graph g(V);

     vector<vector<int>> mat = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };

   
//    g.tsp( mat,0,1,0);
 // cout<<"weigth is--> "<<g.ans<<endl;


vector<vector<int>> dp(1<<V,vector<int>(V,-1));

// g.tsp_dp(mat,0,1,0,dp);
 

    cout<<"weigth is--> "<<g.tsp_dp(mat,0,dp,1)<<endl;
  





    return 0;
}
