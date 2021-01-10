#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


void _run()
{
    ll x,y,n;
    cin >> x >> y >> n;
    ll ansers[6] = {x,y,( y%mod-x%mod + mod) % mod,-x,-y,(x%mod-y %mod + mod)%mod}; 
    ll ans = ansers[(n-1)%6];
    if(ans < 0)
        cout << ans + mod;
    else 
        cout << ans % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
