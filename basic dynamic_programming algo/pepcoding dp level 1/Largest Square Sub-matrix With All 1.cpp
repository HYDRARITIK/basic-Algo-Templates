#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void count(vector<vector<int>>arr ){
    vector<vector<int>>dp;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(arr[i][j]==0)dp[i][j]=0;continue;

            if(i==n-1 ||j==m-1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=min(min(dp[i+1][j+1],dp[i][j+1]),dp[i+1][j]);
            }
        }
        
    } 
    cout<<dp[0][0];
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   int t;
   cin>>t;
   while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
        
    }

    count(arr);
    




    } 




   return 0;
}
