#include <iostream>
#include <vector>

using namespace std ;




long long countWays(int n,int k){
    if(n<=0){
        return 0;
    }
    if(k==1){
        return 1;
    }

    long long a1=countWays(n-1,k-1);
    long long a2= k*countWays(n-1,k);
    return a1+a2;

}

long long countWaysdp(int n,int k){
   vector<vector<long long>>dp(k+1,vector<long long>(n+1,0));
   for(int i=1;i<k+1;i++){
    for(int j=1;j<n+1;j++){
            //j player ko i team me batna
            if(j<i){
                dp[i][j]=0;
            }else if(j==i ||i==1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=i*dp[i][j-1]+dp[i-1][j-1];
            }
    }
   }

   return dp[k][n];

}

int main() {
  int n ,k;
  cin >> n ;
  cin>>k;
//   cout<<countWays(n,k);
  cout<<countWaysdp(n,k);
  
}