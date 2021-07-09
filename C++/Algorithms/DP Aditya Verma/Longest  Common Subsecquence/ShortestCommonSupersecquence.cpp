#include<bits/stdc++.h>
using namespace std;

string scs(string a,string b, int n, int m)
{
    if(n < m)
    {
        swap(n,m);
        swap(a,b);
    }
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(int i  = 1  ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string scs;
    int i = n,j = m;
    while(i > 0 and j > 0)
    {
        if(a[i-1] == b[j-1])
            scs += a[i-1],i--,j--;
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                scs += a[i-1],i--;
            else
                scs += b[j-1],j--;
        }
    }
    while(i > 0)
        scs += a[i-1],i--;
    while(j > 0)
        scs += b[j - 1],j--;
    reverse(scs.begin(),scs.end());
    return scs;
}


int main()
{
    string a,b;
    cin >> a >> b;
    cout << scs(a,b,a.length(),b.length());
}