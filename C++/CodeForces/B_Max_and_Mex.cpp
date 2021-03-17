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
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;


void _run()
{    
    ll n,k;
    cin >> n >> k;
    ll a[n];
    set<ll> u;
    for(ll i = 0 ; i < n ; i++)
        cin >> a[i],u.insert(a[i]);
    sort(a,a+n);
    ll max = a[n-1];
    ll j = 0;
    if(k == 0)
    {
        cout << u.size() << endl;
        return;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(j == a[i])
            j++;
    }

    if(j > max)
    {
        cout << u.size() + k << endl;
    }
    else
    {
        ll add = max + j;
        u.insert((add/2) +add%2);
        cout << u.size() << endl;
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
