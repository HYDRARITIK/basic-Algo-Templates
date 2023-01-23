#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr, int fee) {
// write your code here
//add profit of all upstoroke
int boughtStateProfit=-arr[0];
int soldStateProfit=0;

int n= arr.size();
for (int i = 1; i < arr.size(); i++) {
        int temp1=boughtStateProfit;
        int temp2=soldStateProfit;

        if(soldStateProfit-arr[i]>boughtStateProfit){
            boughtStateProfit=soldStateProfit-arr[i];
        }

        if(arr[i]+temp1-fee  >soldStateProfit){
            soldStateProfit=arr[i]+temp1-fee ;
        }

 
  }


  cout<<soldStateProfit<<endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int fee;
  cin >> fee;

  transactions(arr, fee);

  return 0;
}