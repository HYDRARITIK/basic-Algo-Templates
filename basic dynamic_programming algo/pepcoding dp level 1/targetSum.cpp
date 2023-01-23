#include <iostream>
#include <vector>
using namespace std;

void targetSumSubset(int n, vector<int> arr, int tar) {

// write your code here
// bool **dp=new bool[n+1][tar+1];
vector<vector<bool>>dp(n+1,vector<bool>(tar+1,false));
// dp[i][j] store if there is any subset from 0 to i-1 index 
//in arr vector which can form the sum equal to j

for(int i=0;i<n+1;i++){
    for(int j=0;j<tar+1;j++){
        if(i==0 && j==0){
            dp[i][j]=true;
        }
        else if(i==0){
            dp[i][j]=false;
        }
        else if(j==0){
            dp[i][j]=true;
        }
        else{
            int val=arr[i-1];
            if(j>=val){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-val];
            }
        }
    }
}

cout<< dp[n][tar];
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int tar;
  cin >> tar;
  targetSumSubset(n, arr, tar);

}