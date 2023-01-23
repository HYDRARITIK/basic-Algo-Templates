#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countWays(int n,int m){
    
    int *dp=new int[n+1];
    
    for(int i=1;i<n+1;i++){
        if(i<m){
            dp[i]=1;
        }
        else if(i==m){
            dp[i]=2;
        }
        else{

        dp[i]=dp[i-1]+dp[i-m];
        }
    }
    return dp[n];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


    int n,m;
   cin>>n;
   cin>>m;
   
   cout<<countWays(n,m);




   return 0;
}
