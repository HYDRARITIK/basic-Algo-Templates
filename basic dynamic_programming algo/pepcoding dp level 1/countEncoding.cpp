#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define F(i, j, n) for (int i = (j); i < ((int)n); ++i)

int countEncoding(string s)
{
    int *dp = new int[s.size()];
    dp[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {

        int l = int(s[i - 1]) - 48;
        int m = int(s[i]) - 48;
        int num = l * 10 + m;
      

        if (l == 0 && m == 0)
        {
            dp[i] = 0;
        }
        else if (l == 0 && m != 0)
        {

            dp[i] = dp[i - 1];
        }
        else if (l != 0 && m == 0)
        {
            dp[i] = 0;
            if (num <= 26)
            {

                dp[i] = (i>=2 ? dp[i - 2]:1);
            }
        }
        else
        {
            dp[i] = dp[i - 1];
            if (num <= 26)
            {

                dp[i] += (i>=2 ?  dp[i - 2]:1);
            }
        }
    }
    return dp[s.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << countEncoding(s);

    return 0;
}
