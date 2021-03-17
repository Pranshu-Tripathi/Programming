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
#define mod 1000000009

void _run()
{    
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i],sum += a[i];
    ll t = ceil(sum/(ld)(n-1));
    ll d = *max_element(a,a+n);
    ll k = max(t,d);
    ll add = k*(n-1) - sum ;
    cout << add << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
