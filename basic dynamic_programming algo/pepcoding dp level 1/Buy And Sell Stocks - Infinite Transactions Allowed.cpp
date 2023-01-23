#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr) {

// write your code here
//add profit of all upstoroke
int profit=0;
int min_stroke=arr[0];
int max_stroke=arr[0];
int n= arr.size();
for (int i = 1; i < arr.size(); i++) {
    if(arr[i]>=arr[i-1]){
        max_stroke=arr[i];
        if(i==n-1){
            profit+=max_stroke-min_stroke;
        }
    }
    else{
        profit+=max_stroke-min_stroke;
        min_stroke=arr[i];
        max_stroke=arr[i];
    }
  }


  cout<<profit<<endl;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }

  transactions(arr);
  return 0;
}