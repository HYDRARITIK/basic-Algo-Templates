// if we want shortest path in term of edgest than bfs is helpful
// if we want shortest path in term of weights than dijkstra helps,it is similar to bfs but have priority queue in place of simple queue

#include <iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


#define iPair pair<int,int>;

// algo      remove->->mark *->do work-> add neighbours

class pair_queue
{
public:
    int wt;
    int node;
    int parent_node;
   

    pair_queue(int wt=0,
         int node=0,
         int parent_node=0)
    {
        this->wt=wt;
        this->parent_node=parent_node;
        this->node=node;
    }
};


class Compare
{
public:
    bool operator() (const pair_queue &p1,const pair_queue &p2)
    {
        //smaller weight will come first 
        return p1.wt > p2.wt;
    }
};



class Graph
{
    int V;
    map<int, vector<pair<int, int>>> adj;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int u, int v, int wt, bool undir = true)
    {

        adj[u].push_back({wt, v});
        if (undir)
        {
            adj[v].push_back({wt, u});
        }
    }
      

    void bfs(int source)
    {

        priority_queue<pair_queue,vector<pair_queue>,Compare > pq;
    //    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;


        bool *visited = new bool[V]{0};
        string psf="";

        pair_queue pair_q=pair_queue(0,source,-1);

       pq.push(pair_q);

        while (!pq.empty())
        {
            // ** pop node ,do some work , add neighbours to queue
            // Do some work for every node

            pair_queue  f = pq.top();

            pq.pop();

            if (visited[f.node])
                continue;

            visited[f.node] = true;

            cout << ""<<f.node  << "is connected to ->"<<f.parent_node <<"have weight "<<f.wt<<endl;

            // PUsh the nbrs of current node inside q if they are not already visited
            for (auto nbr : adj[f.node])
            {
                if (!visited[nbr.second])
                {
                     pair_queue pair_qq=pair_queue(nbr.first,nbr.second,f.node);
                    pq.push(pair_qq);
                    // visited[nbr]=true;
                }
            }
        }
    }
};

int main()
{
    // create the graph given in above figure
    int V = 7;
    Graph g(V);
 
    // making above shown graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 8);
    g.addEdge(1, 2, 9);
    g.addEdge(2, 3, 11);
    g.addEdge(1, 4, 3);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 6, 4);
    g.addEdge(5, 6, 6);
  
 
    // Function call
    g.bfs(0);

    return 0;
}
