#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

ll a[100001];

ll _rc2(ll x)
{
    return (x * (x-1))/2;
}

int _bs(int idx,int n,int d)
{
    int l = idx;
    int r = n - 1;
    int ans_pos = 0;
    while(l <= r)
    {
        int mid = (l+r)/2; 
        if(a[mid] - a[idx] > d)
            r = mid - 1;
        else if(a[mid] - a[idx] <= d)
            ans_pos = mid, l = mid+1;
    }
    return ans_pos;
}

void _run()
{
    int n;
    ll d;
    cin >> n >> d;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

    ll pos[n] = {0};

    for(int i = 0 ; i < n - 2 ; i++)
        pos[i] = _bs(i,n,d) - i;

    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans += _rc2(pos[i]);
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
