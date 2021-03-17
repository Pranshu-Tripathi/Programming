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
    vector<pair<ll,ll>> t(n);
    for(int i = 0 ; i < n ; i++)
        cin >> t[i].first;
    for(int i = 0 ; i < n ; i++)
        cin >> t[i].second;
    sort(t.begin(),t.end());
    ll l = 0;
    ll r = t[n-1].first;
    while(l < r)
    {
        ll mid = (l+r)/2;
        ll sum = 0;
        ll c = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(t[i].first > mid)
                sum += t[i].second;
            else
                c = t[i].first;
        }
        if(max(sum,c) > mid)
            l = mid + 1;
        else
            r = mid;
    }   
    cout << r << endl;
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
