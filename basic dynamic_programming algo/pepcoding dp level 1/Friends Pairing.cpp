#include <iostream>
#include <vector>

using namespace std ;




int countWays(int n){
    int *dp=new int[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<n+1;i++){
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }

    return dp[n];
}

int main() {
  int n ;
  cin >> n ;
  cout<<countWays(n);
  
}