#include<bits/stdc++.h>
using namespace std;
#define ll long long

// n -number of painters
// m - number of pictures
void _run()
{
    int n,m;
    cin >> m >> n;
    int paint[m+1][n+1];

    for(int i = 1 ; i <= m ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> paint[i][j];

    int dp[m+1][n+1];
    for(int i = 0 ; i <= m ; i++)
        for(int j = 0 ; j <= n ; j++)
            dp[i][j] = 0;

    for(int i = 1 ; i <= m ; i++)
        dp[i][1] = dp[i-1][1] + paint[i][1];
    
    for(int i = 2 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            dp[j][i] = max(dp[j-1][i],dp[j][i-1]) + paint[j][i];
        }
    }

    for(int i = 1 ; i <= m ; i++)
        cout << dp[i][n] << ' ';
    cout << endl;
}

int main()
{
    int test = 1;
    while(test--)
        _run();
    return 0;
}