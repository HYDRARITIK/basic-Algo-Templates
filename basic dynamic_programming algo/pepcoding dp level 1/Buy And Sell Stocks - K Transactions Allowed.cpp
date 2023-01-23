// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// void transactions(vector<int> arr, int k) {
//     int n =arr.size();
//     vector<vector<int>>dp(k+1,vector<int>(n,0));

//     for(int i=0;i<k+1;i++){
//         for(int j=0;j<n;j++){
//             if(i==0 || j==0){
//                 dp[i][j]=0;
//             }
//             else{
//                 dp[i][j]=dp[i][j-1];
//                 for(int z=0;z<j;z++){
//                     dp[i][j]=max(dp[i][j],dp[i-1][z]+arr[j]-arr[z]);
//                 }
//             }
//         }
//     }
//     cout<<dp[k][n-1];

// }

// int main() {

//   int n;
//   cin >> n;
//   vector<int> arr(n, 0);

//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   int k ;
//   cin >> k;

//   transactions(arr, k);

//   return 0;
// }




#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr, int k) {
    int n =arr.size();
    vector<vector<int>>dp(k+1,vector<int>(n,0));
    int prev_day_max=INT_MIN;

    for(int i=0;i<k+1;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else{
               
                prev_day_max=max(prev_day_max,dp[i-1][j-1]-arr[j]);
                dp[i][j]=max(dp[i][j-1],prev_day_max+arr[j]);
               
            }
        }
    }
    cout<<dp[k][n-1];

}

int main() {

  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k ;
  cin >> k;

  transactions(arr, k);

  return 0;
}