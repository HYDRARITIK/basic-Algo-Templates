#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long paintHouse(vector<vector<long long>>arr){
    long long n=arr.size();
    vector<vector<long long>>dp(n,vector<long long>(3,0));
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];



    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }

    return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);

}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


    long long n;
    cin>>n;
    vector<vector<long long>>arr(n,vector<long long>(3,0));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<3;j++){
            cin>>arr[i][j];

        }
        
    }

    cout<<paintHouse(arr);



   return 0;
}
