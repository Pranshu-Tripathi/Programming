#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int freq[100005];

void _run()
{
    ll n;
    cin >> n;
    ll a[n];
    ll mxElement = -2;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
        if(mxElement < a[i])
            mxElement = a[i];
        freq[a[i]]++;
    }
    ll dp[mxElement+1];
    dp[0] = 0;
    dp[1] = freq[1];
    for(ll i = 2 ; i <= mxElement ; i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+freq[i]*i);
    }
    cout << dp[mxElement] << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
