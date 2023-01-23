#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countWays(int n){
    
    int *dp=new int[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   int n;
   cin>>n;
   cout<<countWays(n);




   return 0;
}
