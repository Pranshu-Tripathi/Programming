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

vector<ull> ans;
vector<ull> lucky;

void _build(ull a)
{
    if(a > (ll) 10*mod)
        return;
    if(a != 0)
        lucky.push_back(a);
    _build(a*10+4);
    _build(a*10+7);
}

int _bs(ll x)
{
    ll l = 0;
    ll r = lucky.size() - 1;
    ll mid;
    ll ans;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(lucky[mid] == x)
        {
            ans = mid;
            break;
        }
        if(lucky[mid] > x)
            r = mid - 1,ans = mid;
        else 
            l = mid + 1;
    }
    return ans;
}

void _run()
{
    ll l,r;
    cin >> l >> r;
    _build(0);
    sort(lucky.begin(),lucky.end());
    int lminIdx = _bs(l);
    int rminIdx = _bs(r);
    int idx = lminIdx;

    if(r == l)
    {
        cout << lucky[lminIdx];
        return;
    }
    if(lminIdx == rminIdx)
    {
        cout << lucky[lminIdx] * (r-l+1);
        return;
    }
    while(idx <= rminIdx)
    {
        if(idx == lminIdx)
        {
            ans.push_back((lucky[idx]) * (lucky[idx] - l + 1));
        }
        else if(idx == rminIdx)
        {
            ans.push_back((lucky[idx]) * (r - lucky[idx-1]));
        }
        else
        {
            ans.push_back((lucky[idx])*(lucky[idx] - lucky[idx-1]));
        }
        idx++;
    }
    ull sum = 0;
    for(ull x : ans)
        sum += x;
    cout << sum << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
