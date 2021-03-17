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
    ll h[n+1];
    for(int i = 1; i <= n ; i++)
        cin >> h[i];
    ll pr[n+1];
    pr[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        pr[i] = pr[i-1]+h[i];
    for(int i = 1 ; i <= n ; i++)
    {
        ll s = pr[i];
        ll mi_s = (i*(i-1))/2;
        if(mi_s > pr[i])
        {
            cn;
            return;
        }
    }
    cy;
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
