#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countBinaryString(int n){
    vector<vector<int>>dp(2,vector<int>(n+1,0));

    dp[0][1]=1;
    dp[1][1]=1;
    // cout<<n;
    for(int j=2;j<n+1;j++){
        for(int i=0;i<2;i++){
            if(i==0){
                dp[i][j]=dp[i+1][j-1];
            }
            else{
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1];

            }
        }
    }



    return dp[0][n]+dp[1][n];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    int n;
    cin>>n;
    cout<<countBinaryString(n);



   return 0;
}
