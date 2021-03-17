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
    ll n;
    cin >> n;
    vector<pair<ll,ll>> sc(n+1);
    ll arr[n+1];
    arr[0] = 0;
    ll dep = 0;
    for(int i = 1 ; i <= n ; i++)
        cin >> sc[i].first >> sc[i].second;
    sc[0].first = sc[0].second = 0;
    ll ti[n+1];
    ti[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        cin >> ti[i];
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = dep + (sc[i].first - sc[i-1].second) + ti[i];
        ll stop = ceil((sc[i].second - sc[i].first)/2.0);
        dep = max(sc[i].second,arr[i] + stop);
        
    }
    // debug(arr);
    // debug(ti);
    cout << arr[n] << endl;
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
