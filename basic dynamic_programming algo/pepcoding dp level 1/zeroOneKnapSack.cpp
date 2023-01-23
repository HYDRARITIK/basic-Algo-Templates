#include <iostream>
#include <vector>

using namespace std;

//here repetion is not allowded     ===> 2d array
// rows ==weight and col is from 0 to capacity
//dp[i][j]  ===> 0 se i weight tak jitne bhi weight hai unke combination 
//se j capacity ka bag me maximum weight kitna aa sakta hai





int zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap) {


vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
//  write your code here
for(int i=0;i<n+1;i++){
    for(int j=0;j<cap+1;j++){
        if(i==0 && j==0){
            dp[i][j]=0;
        }
        else if(i==0){
            dp[i][j]=0;
        }
        else if(j==0){
            dp[i][j]=0;
        }
        else{
            if(j>=weight[i-1]){
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-weight[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}

return dp[n][cap];


}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;
  cin >> cap;

  cout<<zeroOneKnapsack(n, val, weight, cap);


}