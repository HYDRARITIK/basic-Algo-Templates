#include<bits/stdc++.h>
using namespace std;

int jumpT(int i, int n, vector<int>& jumps, vector<int>& dp)
{
  // write your code here
//   dp[k]==k se n tak minimum moves

   dp[n]=0;
    
    
    for(int i=n-1;i>=0;i--){
        if(jumps[i]>0){

            int k=INT_MAX;
            for(int j=1;j<=jumps[i] && j+i<=n;j++){
                if(dp[i+j]!=INT_MAX){
                     k=min(k,dp[j+i]);

                }
                
            }
            if(k!=INT_MAX){

                dp[i]=1+k;
            }
        }
    }

    return dp[0];
}

int main() {

  int n;
  cin >> n;

  vector<int> jumps(n);

  for (int i = 0; i < n; i++)
  {
    cin >> jumps[i];
  }

  vector<int> dp(n + 1, INT_MAX);

  int ans = jumpT(0, n, jumps, dp);

  if (ans < 30)
    cout << ans;
  else
    cout << "null";
}