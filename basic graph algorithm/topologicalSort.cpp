// A C++ program to print topological
// sorting of a DAG (directed acyclic graph)
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph
{

    int V;
    map<int, vector<int>> adj;

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        // adj = new list<int>[V];
    }

    // function to add an edge to graph
    void addEdge(int v, int w)
    {
        // Add w to v’s list.
        adj[v].push_back(w);
    }

    void topdfs(int v, bool visited[],
                stack<int> &Stack)
    {

        visited[v] = true;

        vector<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {

            if (!visited[*i])
            {
                topdfs(*i, visited, Stack);
            }
        }

        // during backtracking

        Stack.push(v);
    }

    void topologicalSort()
    {
        stack<int> Stack;

        bool *visited = new bool[V]{false};

        for (int i = 0; i < V; i++)
        {

            if (!visited[i])
            {

                topdfs(i, visited, Stack);
            }
        }

        // Print contents of stack
        while (!Stack.empty())
        {
            cout << Stack.top() << "->";
            Stack.pop();
        }

        delete[] visited;
    }
};

// Driver Code
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

    cout << "Following is a Topological Sort of the given "
            "graph \n";

    // Function Call
    g.topologicalSort();

    return 0;
}
