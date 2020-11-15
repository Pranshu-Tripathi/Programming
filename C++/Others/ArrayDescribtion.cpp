/*
You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

CSES DP problem
*/

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define LOG(X)      cout << x << endl;
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

#define mod 1000000007

ll DP(int n,int m, vector<int>& a)
{
    int dp[n+1][m+1];
    int i ,j;
    memset(dp,0,sizeof(dp));
    FORE(i,1,n)
    {
        FORE(j,1,m)
        {
            if(i == 1)
            {
                if(a[i] == j || a[i] == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                
            }
            else
            {
                if(a[i] == j || a[i] == 0) 
                {
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
                    if(j != m)  dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
                }
                else
                {
                    dp[i][j] = 0;    
                }
                
            }
        }
    }


    ll ans = 0;
    FORE(i,1,m)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    return ans;
}


int main()
{
    int n,m,i,j;
    cin >> n >> m;

    vector<int> a(n+1);
    a[0] = -1;
    FORE(i,1,n)     cin >> a[i];

    ll ans = DP(n,m,a);
    cout << ans << endl;
}