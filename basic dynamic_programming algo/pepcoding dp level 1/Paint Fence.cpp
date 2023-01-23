#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long  paintFence(int n,int k){

    long long prev_2_same=k;
    long long prev_2_diff=k*(k-1);
    
    for(int i=2;i<n;i++){
        int temp=prev_2_same;
        prev_2_same=prev_2_diff;
        prev_2_diff=(temp+prev_2_diff)*(k-1);
    }

    return prev_2_same+prev_2_diff;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   int n,k;
   cin>>n>>k;
   cout<<paintFence(n,k);



   return 0;
}
