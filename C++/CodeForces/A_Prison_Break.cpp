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

ll getDist(int x1,int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

void _run()
{    
    ll n,m,r,c;
    cin >> n >> m >> r >> c;
    vector<pair<ll,ll>> pos;
    pos.push_back({1,m});
    pos.push_back({n,1});
    pos.push_back({n,m});
    pos.push_back({1,1});
    ll mx = 0;
    for(int i = 0 ; i < pos.size() ; i++)
    {
        mx = max(mx,getDist(pos[i].first,pos[i].second,r,c));
    }
    cout << mx << endl;
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
