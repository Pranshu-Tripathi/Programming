#include<bits/stdc++.h>
using namespace std;


int recursive(string A, string B, int n, int m)
{
    if(n == 0 or m == 0)
        return 0;
    
    if(A[n-1] == B[m-1])
        return 1 + recursive(A,B,n-1,m-1);
    
    return max(recursive(A,B,n-1,m),recursive(A,B,n,m-1));
}

int d[100][100];
int memo(string A, string B, int n, int m)
{
    if(n == 0 or m == 0)
        return 0;
    
    if(d[n][m] != -1)
        return d[n][m];
    
    if(A[n-1] == B[m-1])
        return d[n][m] = 1 + memo(A,B,n-1,m-1);
    
    return d[n][m] = max(recursive(A,B,n-1,m),recursive(A,B,n,m-1));
}

int iterative(string A, string B, int n, int m)
{
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ;  j <= m ; j++)
        {
            if(A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string a,b;
    cin >> a >> b;
    memset(d,-1,sizeof(d));
    cout << recursive(a,b,a.length(),b.length()) << endl;
    cout << memo(a,b,a.length(),b.length()) << endl;;
    cout << iterative(a,b,a.length(),b.length());
}