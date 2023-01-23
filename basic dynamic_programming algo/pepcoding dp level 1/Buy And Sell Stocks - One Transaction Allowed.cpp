#include <iostream>
#include <vector>

using namespace std;

void Transaction(vector<int> arr) {
  //write your code here
  int n=arr.size();
  int min_before=arr[0];
  int profit=INT16_MIN;
  for(int i=1;i<n;i++){
    min_before=min(min_before,arr[i-1]);
    profit =max(profit,arr[i]-min_before);
  }
  cout<<profit<<endl;
}

int  main() {
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  Transaction(arr);
  return 0;
}