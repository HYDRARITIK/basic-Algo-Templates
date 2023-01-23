#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define F(i, j, n) for (int i = (j); i < ((int)n); ++i)

int countsubs(string s)
{
    int *dp = new int[s.size()];
    // dp[0] = 1;
    int prev_a=0;
    int prev_ab=0;
    int prev_abc=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='a'){
            //prev_a wale sequence ke peeche nya a aaye yah nahi + start nya sequence(1)
            dp[i]=2*prev_a+1;
            prev_a=dp[i];
        }
        else if(s[i]=='b'){
            dp[i]=prev_a+2*prev_ab;
            prev_ab=dp[i];
        }
        else{
            dp[i]=prev_ab+2*prev_abc;
            prev_abc=dp[i];
        }
       
    }
    return prev_abc;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << countsubs(s);

    return 0;
}
