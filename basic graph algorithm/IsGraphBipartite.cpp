#include <iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int V;
    map<int, vector<int>> adj;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int i, int j, bool undir = true)
    {
        adj[i].push_back(j);
        if (undir)
        {
            adj[j].push_back(i);
        }
    }

    bool bfs(int source)
    {

        queue<pair<int,int>> q; //stor node and level
        bool *visited = new bool[V]{0};
        bool *odd = new bool[V]{0};
        bool *even = new bool[V]{0};
        int level=0;

        q.push({source,level});
        visited[source] = true;
       

        while (!q.empty())
        {

            auto f = q.front();
            
            if (f.second % 2 == 0)
            {
                if (odd[f.first])
                    return false;
                even[f.first] = true;
            }
            else
            {
                if (even[f.first])
                    return false;
                odd[f.first] = true;
            }

            // cout << f << "->";
            q.pop();

            // PUsh the nbrs of current node inside q if they are not already visited
            for (auto nbr : adj[f.first])
            {
                if (!visited[nbr])
                {
                    q.push({nbr,f.second+1});
                    visited[nbr] = true;
                }
            }
            
        }

        return true;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    cout << g.bfs(0);
    return 0;
}
