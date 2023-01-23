#include <iostream>
#include <vector>

using namespace std;

void transaction(vector<int> arr) {
// write your code here
//add profit of all upstoroke
int boughtStateProfit=-arr[0];
int soldStateProfit=0;
int coolStateProfit=0;

int n= arr.size();
for (int i = 1; i < arr.size(); i++) {
        int temp1=boughtStateProfit;
        int temp2=soldStateProfit;
        int temp3=coolStateProfit;

       
            boughtStateProfit=max(temp1,temp3-arr[i]);
            soldStateProfit=max(temp2,temp1+arr[i]);
            coolStateProfit=max(temp3,temp2);

       
 
  }


  cout<<max(soldStateProfit,coolStateProfit)<<endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i] ;
  }

  transaction(arr);
  return 0;
}