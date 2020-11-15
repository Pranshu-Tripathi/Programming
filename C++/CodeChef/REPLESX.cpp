#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define FORE(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>
#define pll pair<long long int, long long int>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
map<ll, ll> mp;

bool case1(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if(p == x_min_pos || p == x_max_pos || x_min_pos < p && p < x_max_pos)
        return true;
    return false;
}

bool case2(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if(p != k && (k == x_min_pos || k == x_max_pos || (x_min_pos < k && k < x_max_pos)))
        return true;
    return false;
}

bool case3(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if(p == k && x_min_pos > p)
        return true;
    return false;
}

bool case4(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if(p == k && x_max_pos < k)
        return true;
    return false;
}

bool case5(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if((p < k && k < x_min_pos) || (p < x_min_pos && x_max_pos < k) || (k < x_min_pos && x_max_pos < p) || (x_max_pos < k && k < p))
        return true;
    return false;
}

bool case6(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if(x_max_pos < p && p < k)
        return true;
    return false;
}

bool case7(ll x,ll k , ll p,ll x_max_pos , ll x_min_pos)
{
    if(k < p && p < x_min_pos)
        return true;
    return false;
}

void testcase()
{
    ll n, x, p, k;
    cin >> n >> x >> p >> k;
   
    for(ll i= 0;i<n; i++)
    {
        ll temp;
        cin >> temp;
        if (mp.find(temp) == mp.end())
            mp[temp] = 1;
        else
            mp[temp]++;
    }
    

    ll ans = 0;
    if (mp.find(x) == mp.end())
    {
        ll skip = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            skip += it->second;
            if (skip >= k)
            {
                it->second -= 1;
                if (it->second == 0)
                    mp.erase(it->first);
                mp[x] = 1;
                ans++;
                break;
            }
        }
    }
    

    ll x_min_pos = 0, x_max_pos = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->first != x)
        {
            x_min_pos += it->second;
            continue;
        }
        if (it->first == x)
        {
            x_max_pos = x_min_pos + it->second;
            x_min_pos++;
            break;
        }
    }
    
    if(case1(x,k,p,x_max_pos,x_min_pos))
    {
        cout << ans << endl;
        return;
    }

    if(case2(x,k,p,x_max_pos,x_min_pos))
    {
        cout << -1 << endl;
        return;
    }

    if(case3(x,k,p,x_max_pos,x_min_pos))
    {
        cout << x_min_pos - p + ans << endl;
        return;
    }

    if(case4(x,k,p,x_max_pos,x_min_pos))
    {
        cout << p - x_max_pos + ans << endl;
        return;
    }

    if(case5(x,k,p,x_max_pos,x_min_pos))
    {
        cout << -1 << endl;
        return;
    }

    if(case6(x,k,p,x_max_pos,x_min_pos))
    {
        cout << p - x_max_pos + ans << endl;
        return;
    }

    if(case7(x,k,p,x_max_pos,x_min_pos))
    {
        cout << x_min_pos - p + ans << endl;
        return;
    }

}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        testcase();
    }

}