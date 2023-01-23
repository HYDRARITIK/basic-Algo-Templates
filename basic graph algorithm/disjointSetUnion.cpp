#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dsu{
    int V;
    int *parent;
    int *rank;
    vector<pair<int,int>>edge_list;

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

    void addEdge(int u,int v){
        edge_list.push_back({u,v});
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
    void union_set(int a,int b){
        int s1=this->find(a);
        int s2=this->find(b);
        
        if(s1!=s2){
            //union of rank
            if(rank[s1]>rank[s2]){
             parent[s2]=s1;
             rank[s1]+=rank[s2];
            }else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            
        }else{
            cout<<"they are already in same set ,if join they form cycle"<<endl;
        }
    }

    void contains_cycle(){
        for(auto edge:edge_list){
            int u=edge.first;
            int v=edge.second;
          
            this->union_set(u,v);
           
        }
    }



};










int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    dsu g(7);
    
g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(5,3);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);

    g.contains_cycle();
  



   return 0;
}
