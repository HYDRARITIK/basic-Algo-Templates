// A C++ program to print topological
// sorting of a graph using indegrees.
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
    // prints a Topological Sort of
    // the complete graph

    void IndegreeArrayGenerator(vector<int> &in_degree)
    {
        for (int u = 0; u < V; u++)
        {
            vector<int>::iterator itr;
            for (itr = adj[u].begin();
                 itr != adj[u].end(); itr++)
                in_degree[*itr]++;
        }
    }

    void topologicalSort()
    {

        vector<int> in_degree(V, 0);

        IndegreeArrayGenerator(in_degree);

        // pushing node having indegree==0
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
                q.push(i);

        // Initialize count of visited vertices
        int cnt = 0;

        vector<int> top_order;

        while (!q.empty())
        {

            int u = q.front();
            q.pop();
            top_order.push_back(u);

            vector<int>::iterator itr;
            for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            {
                in_degree[*itr]--; //decreasing indegree
                if (in_degree[*itr] == 0)
                {
                    q.push(*itr);
                }
            }
            cnt++;
        }

        // if count not equal to no. of vertices it means there is a cycle
        // if there is cycle than all node will not come to queue and loop end early
        if (cnt != V)
        {
            cout << "There exists a cycle in the graph\n";
            return;
        }

        // Print topological order

        for (int i = 0; i < top_order.size(); i++){
            cout << top_order[i] << "->";

        }
        cout << endl;
    };
};

// Driver program to test above functions
int main()
{

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of\n";
    g.topologicalSort();

    return 0;
}
