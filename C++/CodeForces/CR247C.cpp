#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define mod 1000000007

int dp[101][2];

void add(int &a, int b)
{
    a += b;
    if(a >= mod)
        a-=mod;
}

void _run()
{
    int n,k,d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        dp[i][0] = dp[i][1] = 0;
        for(int j = 1 ; j <= k ; j++)
        {
            if( i - j < 0)
                break;
            else if(j < d)
            {
                add(dp[i][0],dp[i-j][0]);
                add(dp[i][1],dp[i-j][1]);
            }
            else
            {
                add(dp[i][1],dp[i-j][1]);
                add(dp[i][1],dp[i-j][0]);
            }
        }
    }

    // for(int i = 0 ; i <= n ; i++)
    // {
    //     cout << dp[i][0] <<' '<<dp[i][1] << endl;
    // }
    cout << dp[n][1] << endl;
}


int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
