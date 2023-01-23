#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class pair_queue
{
public:
    int u;
    int v;
    int wt;
   

    pair_queue(int u=0,
         int v=0,
         int wt=0)
    {
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};


class Compare
{
public:
    bool operator() (const pair_queue &p1,const pair_queue &p2)
    {
        //smaller weight will come first ie smaller weight is at front and
        //larger weight is at last 
        return p1.wt < p2.wt;
    }
};









class dsu{
    int V;
    int *parent;
    int *rank;
    
    
    vector<pair_queue>edge_list;

    public:
    dsu(int v){
        this->V=v;
        parent=new int[V];
        rank=new int[V];
        for(int i=0;i<V;i++){
            parent[i]=-1;
            rank[i]=1;
        }

    }

    void addEdge(int u,int v,int wt){
        pair_queue p1(u,v,wt);
        edge_list.push_back(p1);
    }


      int find(int a){
        if(parent[a]==-1)return a;
        
        return parent[a]=find(parent[a]);

    }
    // void print(){
    //     for(int i=0;i<V;i++){
    //         cout<<parent[i]<<endl;
    //     }
    // }
    string psf="";


    void union_set(int a,int b){
        int s1=this->find(a);
        int s2=this->find(b);
        if(s1!=s2){
            parent[s1]=s2;
            psf+="("+to_string(a)+"->"+to_string(b)+")";
            
        }else{
            cout<<to_string(a)+"and"+to_string(b)+" are already in same set ,if join they form cycle"<<endl;
        }
    }

    void contains_cycle(){
        for(auto edge:edge_list){
            int u=edge.u;
            int v=edge.v;
            sort(edge_list.begin(), edge_list.end(), Compare());
          
            this->union_set(u,v);
           
        }
    }



};










int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    dsu g(7);
    
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 8);
    g.addEdge(1, 2, 9);
    g.addEdge(2, 3, 11);
    g.addEdge(1, 4, 3);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 6, 4);
    g.addEdge(5, 6, 6);

g.contains_cycle();

    cout<<"path so far is-->"<<g.psf<<endl;
  



   return 0;
}
