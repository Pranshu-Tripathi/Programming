#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    string s;
    cin >> s;
    int n = s.length();
    bool dp[n][n];
    memset(dp,false,sizeof(dp));

    for(int i = 0 ; i < n ; i++)
        dp[i][i] = true;
    int mxlcs = 1;
    for(int i = n-2 ; i >= 0 ; i--)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                mxlcs = max(mxlcs,j- i + 1);
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << mxlcs << endl;
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
