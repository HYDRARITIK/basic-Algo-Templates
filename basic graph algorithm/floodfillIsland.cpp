#include<bits/stdc++.h>
using namespace std;

void getislands(vector<vector<int>> &v,vector<vector<bool>> &vis,int r,int c){
    if(r<0 || c<0 || r>=v.size() || c>=v[0].size()|| v[r][c]==0 || vis[r][c]){
        return;
    }
    vis[r][c]=true;
    getislands(v,vis,r-1,c); //top
    getislands(v,vis,r,c+1); //right
    getislands(v,vis,r+1,c); //bottom
    getislands(v,vis,r,c-1); //left

}



int noofislands(vector<vector<int>> v){
    int n=v.size(),m=v[0].size(),count=0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(!vis[i][j] && v[i][j]==1){
                getislands(v,vis,i,j);
                count++;
            }
        }
    }

    return count;
}

int main(){

     vector<vector<int> > M = { { 0, 0, 0, 1, 1 },
                               { 0, 1, 0, 0, 0 },
                               { 1, 1, 0, 1, 1 },
                               { 1, 0, 1, 1, 1 },
                               { 0, 0, 0, 0, 0 } };

    cout << noofislands(M) << endl;
    return 0;

}