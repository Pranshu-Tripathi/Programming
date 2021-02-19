#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    ll a,b;
    cin >> a >> b;
    ll ans = 0; 
    while(true)
    {
        if(b==1)
        {
            ans += a;
            break;
        }   
        if(a == 0 || b == 0)
            break; 
        ll step = 0;
        if(a > b)
        {
            step = a/b;
            a -= b * step; 
        }
        else
        {
            step = b/a;
            b -= a * step;
        }
        ans += step;
    }
    cout << ans;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
