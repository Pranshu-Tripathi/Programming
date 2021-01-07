#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    string s,t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int dp[n+1][m+1];
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0; j <= m ; j++)
            dp[i][j] = 0;
    int mxLcs = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
            
            mxLcs = max(mxLcs,dp[i][j]);
        }
    
    }

    for(int i = 0 ; i<= n ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << mxLcs << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
