#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000007
vector<ll> possi;

void _build(ll x,int a, int b)
{
    if(x > 10000000)
        return;
    if(x != 0)
        possi.push_back(x);
    _build(x*10+a,a,b);
    _build(x*10+b,a,b);
}

unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; 
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 

unsigned long long modInverse(unsigned long long n,  int p)
{
    return power(n, p - 2, p);
}
 

unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}


void _run()
{
    int a,b,n;
    cin >> a >> b >> n;
    _build(0,a,b);
    sort(possi.begin(),possi.end());
    ll sum = 0;
    ll ans = 0;
    for(int i = 0 ; i <= n; i++)
    {
        sum = (a*i) + b*(n-i);
        ll l = 0;
        ll r = possi.size()-1;
        ll mid;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(possi[mid] > sum)
                r = mid - 1;
            else if(possi[mid] < sum)
                l = mid + 1;
            else
                break;
        }
        if(possi[mid] == sum)
        {
            ans = (ans % mod + nCrModPFermat(n, i, mod) % mod) % mod;
        }
    }
    cout << ans  << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
