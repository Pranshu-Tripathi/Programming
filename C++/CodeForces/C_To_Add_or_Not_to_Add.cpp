#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

ll a[200001];
ll pre[200001];

int _bs(ll l, ll r,ll k)
{
    ll idx = r;
    ll occurs;
    ll sum = 0,req = 0;
    ll ans = 1;
    while(l <= r)
    {
        occurs = (l+r)/2;
        sum = pre[idx] - pre[idx-occurs];
        req = occurs * a[idx];
        req -= sum;

        if(req <= k)
            ans = occurs,l = occurs + 1;
        else if(req > k)
            r = occurs - 1;        
    }
    return ans;
}

void _pre(ll n)
{
    pre[0] = a[0] = 0;
    pre[1] = a[1];
    for(int i = 2 ; i <= n ; i++)
        pre[i] = pre[i-1] + a[i];
}

void _run()
{
    ll n,k;
    cin >> n >> k;
    for(int i = 1 ; i  <= n ; i++)
        cin >> a[i];    
    sort(a+1,a+n+1);
    _pre(n);
    ll ocs[n + 1] = {1};
    for(ll i = n ; i >= 1 ; i--)
        ocs[i] = _bs(1,i,k);
    ll mxFre = 0;
    ll ansEle;
    for(int i = 1 ; i <= n ; i++)
    {
        if(mxFre < ocs[i])
            mxFre = ocs[i], ansEle = a[i];
    }
    cout << mxFre << ' ' << ansEle;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
