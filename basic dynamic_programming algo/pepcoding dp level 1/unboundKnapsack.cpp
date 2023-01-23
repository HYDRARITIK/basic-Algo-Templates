#include <iostream>
#include <vector>

using namespace std;
//here repetion is  allowded      ===> 1d array
// rows ==weight and col is from 0 to capacity
//dp[i][j]  ===> 0 se i weight tak jitne bhi weight hai unke combination 
//se j capacity ka bag me maximum weight kitna aa sakta hai


int unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

// write your code here
int *dp=new int[cap+1];
for(int i=0;i<cap+1;i++){
    dp[i]=0;
}

for(int i=1;i<cap+1;i++){
    int max_weight=-10000;
    for(int j=0;j<n;j++){
        if(i>=weight[j]){
            max_weight=max(max_weight,val[j]+dp[i-weight[j]]);
        }
    }


    dp[i]=max(max_weight,0);
}

// for(int i=0;i<cap+1;i++){
//     cout<<dp[i]<<"->";
// }

return dp[cap];

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

 cout<< unboundedKnapsack(n, val, weight, cap);


}