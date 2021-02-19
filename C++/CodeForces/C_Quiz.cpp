#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

ll expo(ll A, ll B)
{
    if(B==0)
        return 1;
    if(B==1)
        return A;
    if(B%2 == 0)
    {
        ll ret = expo(A,B/2);
        ret = (ret%mod * ret%mod)%mod;
        return ret;
    }   
    else
    {
        ll ret = expo(A,B/2);
        ret = (ret%mod * ret%mod)%mod;
        ret = (ret%mod*A%mod)%mod;
        return ret;
    }
}


void _run()
{
    ll n,m,k;
    cin >> n >> m >> k;
    ll bar = (n-m);
    ll che = m/(k-1);
    ll scores = (bar%mod* (k - 1)%mod)%mod;
    ll leftq = (m - (((k-1)%mod*bar%mod)%mod));
    // cout << leftq << ' ' << bar << endl;
    ll dubs = leftq/k;
    if(bar > che * (k-1) || dubs <= 0 || bar * (k-1)  >= m) 
    {
        cout << m << endl;
        return;
    }
    leftq -= (k*dubs);
    scores =(scores%mod + leftq%mod)%mod;
    //cout << scores << endl;
    scores = (scores%mod + ((expo(2,dubs+1)%mod-2 + mod)%mod*k%mod)%mod)%mod;
    //cout << scores << endl;
    scores = (scores%mod);
    cout << scores << endl;
}


int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
