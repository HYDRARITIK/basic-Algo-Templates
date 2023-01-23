#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class coin
{

public:
    int count;
    vector<vector<int>> allstore;
    coin()
    {
        this->count=0;
    }

    void coinChangePermutation(int n, vector<int> arr, int tar)
    {

        if (tar < 0)
            return;
        if (tar== 0)
        {

            count++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            coinChangePermutation(n, arr, tar - arr[i]);
            

        }
    }
    
    
    void coinChangeComb(int n, vector<int> arr, int tar,vector<int> &store)
    {

        if (tar < 0)
            return ;
        if (tar== 0)
        {
            allstore.push_back(store);

            count++;
            return ;
        }
        
        for (int i = 0; i < n; i++)
        {
            store.push_back(arr[i]);
            coinChangeComb(n, arr, tar - arr[i],store);
            store.pop_back();
            //backtracking
        }
    }

    void print(){
        for(int i=0;i<allstore.size();i++){
            for(int j=0;j<allstore[i].size();j++){
                cout<<allstore[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int coinChangeCombdp(int n, vector<int> arr, int tar)
    {

        int *dp=new int[tar+1];
        for(int i=0;i<tar+1;i++){
            dp[i]=0;
        }
        dp[0]=1;

        for(int i=0;i<n;i++){
            //taking effect of arr[i] one by one
            for(int j=arr[i];j<tar+1;j++){
                dp[j]+=dp[j-arr[i]];
            }
        }

        return dp[tar];
   
    }


     int coinChangePermdp(int n, vector<int> arr, int tar)
    {

        int *dp=new int[tar+1];
        for(int i=0;i<tar+1;i++){
            dp[i]=0;
        }
        dp[0]=1;

       for(int i=1;i<tar+1;i++){
        for(auto &coin:arr){
            if(i>=coin){
                dp[i]+=dp[i-coin];
            }
        }
       }

        return dp[tar];
   
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int tar;
    cin >> tar;

    coin g;
    // g.coinChangePermutation(n, arr, tar);
    vector<int> store;
//    cout<<  g.coinChangeCombdp(n, arr, tar)<<endl;
   cout<<  g.coinChangePermdp(n, arr, tar)<<endl;

    // cout<<g.count<<endl;
    // g.print();

    return 0;
}
