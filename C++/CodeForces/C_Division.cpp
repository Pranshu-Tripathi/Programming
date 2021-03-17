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

bool sort_by_freq(const pair<ll,ll>& a, const pair<ll,ll>& b)
{
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void _run()
{    
    ll q,p;
    cin >> p >> q;
    if(p % q != 0)
    {
        cout << p << endl;
        return;
    }
    ll tem = q;
    vector<pair<ll,ll>> trans;
    for(int i = 2; i * i <= q ; i++)
    {
        if(q % i == 0)
        {
            ll cnt = 0;
            while(q % i == 0)
            {   
                cnt++;
                q /= i;
            }
            trans.push_back({i,cnt});
        }
    }
    if(q != 1)
        trans.push_back({q,1});
    sort(trans.begin(),trans.end(), sort_by_freq);
    ll bestX = 1;
    for(int i = 0 ; i  < trans.size() ; i++)
    {
        ll y = trans[i].first;
        ll x = p;
        while(x % tem == 0)
            x /= y;
        if(x % tem != 0)
            bestX = max(bestX,x);
    }
    cout << bestX << endl;
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
