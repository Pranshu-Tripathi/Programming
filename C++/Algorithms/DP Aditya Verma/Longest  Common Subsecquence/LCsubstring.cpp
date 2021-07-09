#include <bits/stdc++.h>
using namespace std;

int iterative(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    int MXLCS = 0;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1 ; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = 0;
            MXLCS = max(MXLCS,dp[i][j]);
        }
    }
    return MXLCS;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << iterative(a, b, a.length(), b.length());
}