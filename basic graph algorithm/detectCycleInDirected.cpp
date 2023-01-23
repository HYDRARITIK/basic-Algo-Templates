// A C++ Program to detect cycle in a graph
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    map<int, vector<int>> adj;

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
    
    }

  
    void addEdge(int v, int w)
    {
      
        adj[v].push_back(w);
    }

    bool dfscyclic(int v, bool visited[], bool *recStack)
    {

        // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;

            vector<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {

                if(!visited[*i]){
                   bool IsnbrCyclic= dfscyclic(*i, visited, recStack);
                   if(IsnbrCyclic)return true;
                }
                else if(recStack[*i])return true;

            }
        //backtracking    
        recStack[v] = false; // remove the vertex from recursion stack
        return false;
    }; // used by isCyclic()










    bool isCyclic()
    {
        bool *visited = new bool[V]{false};
        bool *recStack = new bool[V]{false};

        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for (int i = 0; i < V; i++){

            if (!visited[i]){

                //if there is cycle for any node than it is cyclic
                if(dfscyclic(i, visited, recStack)){
                    return true;
                }
            }
        }

        return false;
    }; // returns true if there is a cycle in this graph
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
   g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3,5);
    

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
