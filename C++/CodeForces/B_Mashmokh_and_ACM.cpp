#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl 
#define ld long double
#define mod 1000000007 

set<int> _facts(int m)
{
    set<int> res;
    res.insert(1);
    res.insert(m);
    for(int i = 2 ; i * i <= m; i++)
    {
        while(m % i == 0)
        {
            res.insert(i);
            res.insert(m/i);
            m/=i;
        }
    }
    if(m != 1)
        res.insert(m);
    return res;
}

void _run()
{
    int n,k;
    cin >> n >> k;
    ll dp[k+1][n+1];
    memset(dp,0,sizeof(dp)); 

    for(int i = 1 ; i <= n ; i++)
        dp[1][i] = 1;

    for(int len = 2 ; len <= k ; len++)
    {
        for(int las = 1 ; las <= n ; las++)
        {
            dp[len][las] = 0;
            for(int x = las ; x <= n ; x += las)
                dp[len][las] = (dp[len][las]%mod +dp[len-1][x]%mod)%mod;
        }
    }


    ll sum = 0;
    for(int i = 0 ; i<= n ; i++)
        sum = (sum%mod + dp[k][i]%mod)%mod;
    cout << sum << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
