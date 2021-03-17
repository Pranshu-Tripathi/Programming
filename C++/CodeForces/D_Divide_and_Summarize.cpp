/*
PR7
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl
#define ld long double
#define mod 1000000009
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;

ll a[1000005];
ll sum[1000005];
int n,q;
set<ll> avail;

ll getSum(int l,int r)
{
    if(l > 0)
        return sum[r] - sum[l-1];
    else
        return sum[r];
}

void bin_ser(int l, int r)
{
    if(l > r)
        return;
    ll mid = (a[l] + a[r])/2;
    int pos = upper_bound(a,a+n,mid) - a;
    avail.insert(getSum(l,r));
    if(pos > r)
        return;
    bin_ser(l,pos-1);
    bin_ser(pos,r);
}

void _precom()
{
    memset(sum,0,sizeof(sum));
    sum[0] = a[0];
    for(int i = 1 ; i < n ; i++)
        sum[i] = sum[i-1] + a[i];
}

void _run()
{    
    avail.clear();
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);
    _precom();
    bin_ser(0,n-1);

    ll x;
    for(int i = 0 ; i < q ; i++)
    {
        cin >> x;
        if(avail.count(x))
            cy;
        else    
            cn;
    }
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
