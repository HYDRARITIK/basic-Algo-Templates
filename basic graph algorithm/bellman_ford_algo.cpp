// if we want shortest path in term of edgest than bfs is helpful
// if we want shortest path in term of weights than dijkstra helps,it is similar to bfs but have priority queue in place of simple queue

#include <iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

// basic
typedef long long LL;
// pair
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;

// vector
typedef vector<int> vi;
typedef vector<vi> vvi;  // vector<vector<int>>
typedef vector<pii> vii; // vector<pair<int,int>>

// map

typedef map<int, int> mi;
typedef map<int, vi> mvi;

// loop
#define f(i, n)                 \
    for (int i = 0; i < n; i++) \
        ;
#define fn(i, n)                     \
    for (int i = n - 1; i >= 0; i--) \
        ;
#define vitr vector<int>::iterator

// algo      remove->->mark *->do work-> add neighbours

class pair_queue
{
public:
    int u;
    int v;
    int wt;

    pair_queue(int u = 0,
               int v = 0,
               int wt = 0)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

// class Compare
// {
// public:
//     bool operator()(const pair_queue &p1, const pair_queue &p2)
//     {
//         return p1.wtsf > p2.wtsf;
//     }
// };

class Graph
{
    int V;
    vector<vector<int>> mat;

public:
    Graph(int v)
    {
        V = v;
    }
    void addedge(int u, int v, int wt)
    {
        mat[u][v] = wt;
    }

    void relaxation()
    {

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i == j)
                    mat[i][j] = 0;
            }
        }

        for (int via = 0; via < V; via++)
        {

            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    // if (mat[i][via] == INT_MAX || mat[via][j] == INT_MAX);continue;

                    int distance = mat[i][via] + mat[via][j];

                    // if (distance < mat[i][j])
                    // {
                    //     mat[i][j] = distance;
                    // }
                    mat[i][j] = min(mat[i][j], distance);
                }
            }
        }
        // negative cycle
        for (int i = 0; i < V; i++)
        {

            if (mat[i][i] < 0)
            {
                cout << "there is negative cycle";
            }
        }

        // print
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // create the graph given in above figure
    int V = 9;
    Graph g(V);

    // making above shown graph

    g.addedge(0, 1, 4);
    g.addedge(0, 7, 8);
    g.addedge(1, 2, 8);
    g.addedge(1, 7, 11);
    g.addedge(2, 3, 7);
    g.addedge(2, 8, 2);
    g.addedge(2, 5, 4);
    g.addedge(3, 4, 9);
    g.addedge(3, 5, 14);
    g.addedge(4, 5, 10);
    g.addedge(5, 6, 2);
    g.addedge(6, 7, 1);
    g.addedge(6, 8, 6);
    g.addedge(7, 8, 7);

    // Function call
    g.relaxation();

    return 0;
}
