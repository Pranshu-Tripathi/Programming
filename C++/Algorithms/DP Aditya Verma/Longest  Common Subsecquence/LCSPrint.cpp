#include<bits/stdc++.h>
using namespace std;

string PrintLSC(string a, string b, int n, int m)
{

    if(n < m)
    {
        swap(m,n);
        swap(a,b);
    }

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }


    int x = n;
    int y = m;
    string ans;
    while(x != 0 and y != 0)
    {
        if(a[x-1] == b[y-1])
        {
            ans += a[x-1];
            x--,y--;
        }
        else if(dp[x-1][y] > dp[x][y-1])
            x--;
        else 
            y--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string a,b;
    cin >> a >> b;
    cout << PrintLSC(a,b,a.length(),b.length());
}