#include <iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int V;
    map<int, vector<int>> adj;
    map<int, vector<int>> adj_rev;
    stack<int> dfs_stack;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int i, int j, bool undir = true)
    {
        adj[i].push_back(j);
        adj_rev[j].push_back(i);
    }
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        // cout << node << "->";

        // make a dfs call on all its unvisited neighbours
        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
        dfs_stack.push(node);
        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[V];
         for (int i = 0; i < V; i++){
            visited[i]=false;
         }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // for connected components
                dfsHelper(source, visited);
            }
        }
    }

    int getSCC()
    {
        bool *visited_scc = new bool[V];
        for (int i = 0; i < V; i++){
            visited_scc[i]=false;
         }

        int count = 0;
        while (!dfs_stack.empty())
        {
            int f = dfs_stack.top();
            dfs_stack.pop();
            if (!visited_scc[f])
            {

                dfsSCC(f, visited_scc);
                count++;
            }
        }
        return count;
    }

    void dfsSCC(int node, bool *visited)
    {
        visited[node] = true;
        // cout << node << "->";

        // make a dfs call on all its unvisited neighbours
        for (int nbr : adj_rev[node])
        {
            if (!visited[nbr])
            {
                dfsSCC(nbr, visited);
            }
        }
       
        return;
    }

    void printStack(){
        while (!dfs_stack.empty())
        {
            int f = dfs_stack.top();
            dfs_stack.pop();
            cout<<f<<" -"<<endl;
        }

    }
};

int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    g.addEdge(2, 4);

    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 4);

    g.dfs(1);  //running normal dfs
    // g.printStack();
    cout<<g.getSCC()<<endl;
    return 0;
}