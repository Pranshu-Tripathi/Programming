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
    set<ll> u;
    vector<ll> x;
    ll t;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t;
        x.push_back(t);
        u.insert(t);
    }

    if(x.size() == u.size())
        cn;
    else
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
