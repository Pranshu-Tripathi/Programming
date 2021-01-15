#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000003

map<char,int> m;

ll expo(int A,int B)
{
    if(B == 0 || A == 1)
        return 1;
    if(B == 1)
        return A;
    if(B % 2 == 0)
    {
        ll ret = expo(A,B/2);
        ret = (ret%mod * ret% mod)%mod;
        return ret;
    }
    else
    {
        ll ret = expo(A,B/2);
        ret = (ret %mod * ret % mod)%mod;
        ret = (ret % mod* A%mod)%mod;
        return ret;
    }
    
}

void _run()
{
    string s;
    cin >> s;
    m['>'] = 8;
    m['<'] = 9;
    m['+'] = 10;
    m['-'] = 11;
    m['.'] = 12;
    m[','] = 13;
    m['['] = 14;
    m[']'] = 15;

    ll ans = 0;
    int n = s.length();
    ans += m[s[n-1]];
    int p = 4;
    for(int i = n - 2 ; i >= 0 ; i--,p += 4)
    {
        ll exp = expo(2,p);
        ll ans1 = (exp %mod * m[s[i]] % mod)%mod;
        ans = (ans % mod + ans1 % mod) % mod;
    }
    cout  << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    while(test--)
        _run();
    return 0;
}