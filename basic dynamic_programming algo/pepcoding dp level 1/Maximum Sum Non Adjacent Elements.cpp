#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define F(i, j, n) for (int i = (j); i < ((int)n); ++i)

int maxSum(vector<int> arr)
{
   int n=arr.size();
    vector<vector<int>>dp(2,vector<int>(n,0));
    dp[0][0]=arr[0];

    
    for(int j=1;j<n;j++){
        for(int i=0;i<2;i++){
            if(i==0){
                dp[i][j]=dp[i+1][j-1]+arr[j];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }
    return max(dp[0][n-1],dp[1][n-1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSum(arr);

    return 0;
}
