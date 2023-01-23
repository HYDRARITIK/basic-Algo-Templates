#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

void transactions(vector<int> arr)
{

    // write your code here

    int n = arr.size();

    int min_before = arr[0];
    int max_after = arr[n - 1];
    int profit = INT16_MIN;
    int *soldUptoToday = new int[n];
    soldUptoToday[0] = 0;
    int *SoldAfterToday = new int[n];
    SoldAfterToday[n - 1] = 0;

    for (int i = 1; i < n; i++)
    {
        min_before = min(min_before, arr[i - 1]);

        soldUptoToday[i] = max(arr[i] - min_before, soldUptoToday[i - 1]);
        // profit =max(profit,arr[i]-min_before);
    }
   


    for (int i = n - 2; i >=0; i--)
    {
        max_after = max(arr[i + 1], max_after);

        SoldAfterToday[i] = max(SoldAfterToday[i+ 1], max_after - arr[i]);
    }

//  for(int i=0;i<n;i++){
//         cout<<SoldAfterToday[i]<<" ";
//     }




    int total2Transaction = INT_MIN;



    for (int i = 0; i < n; i++)
    {
        total2Transaction = max(total2Transaction, soldUptoToday[i] + SoldAfterToday[i]);
    }

    cout << total2Transaction << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    transactions(arr);

    return 0;
}