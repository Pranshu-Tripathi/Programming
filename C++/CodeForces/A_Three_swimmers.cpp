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
    ull p,a,b,c;
    cin >> p >> a >> b >> c;
    ld A = (p%a)/(ld)a;
    ld B = (p%b)/(ld)b;
    ld C = (p%c)/(ld)c;
    if(A == 0 || B == 0 || C == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 0;
    ll x = (p/a);
    ll wa = (x+1)*a-p;
    ll y = (p/b);
    ll wb = (y+1)*b-p;
    ll z = (p/c);
    ll wc = (z+1) * c - p;
    ans = min(wa,min(wb,wc));
    cout << ans << endl;
    // ld mx = max(A,max(B,C));
    // if(mx == A)
    // {
    //     ll x = p/a;
    //     ll wa = (x+1)*a-p;
    //     cout << wa << endl;
    // }
    // else if(mx == B)
    // {
    //     ll x = p/b;
    //     ll wa = (x+1)*b-p;
    //     cout << wa << endl;
    // }
    // else
    // {
    //     ll x = p/c;
    //     ll wa = (x+1)*c-p;
    //     cout << wa << endl;
    // }

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
