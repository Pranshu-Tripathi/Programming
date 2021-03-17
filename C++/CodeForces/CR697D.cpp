#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

bool _sortbysec(const pair<ll,ll> & a , const pair<ll,ll> & b)
{
    return a.second < b.second;
}

void _run()
{
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> ab(n);
    for(int i = 0 ; i < n ; i++)   
        cin >> ab[i].first;
    for(int i = 0 ; i < n ; i++)   
        cin >> ab[i].second;
    
    vector<ll> one,two;
    for(int i = 0 ; i < n ; i++)
    {
        if(ab[i].second == 1)
            one.push_back(ab[i].first);
        if(ab[i].second == 2)
            two.push_back(ab[i].first);
    }

    sort(two.begin(),two.end(),greater<ll>());
    sort(one.begin(),one.end(),greater<ll>());
    ll curSumA = 0;
    ll curSumB = 0;
    for(int x : two)
        curSumB += x;
    int r = two.size();
    int ans = __INT_MAX__;
    for(int l = 0 ; l <= one.size() ; l++)
    {
        while( r > 0 && curSumA + curSumB - two[r-1] >= m)
        {
            r--;
            curSumB -= two[r];
        }
        if(curSumA + curSumB >= m)
            ans = min(ans, l + 2*r);
        if(l != one.size())
            curSumA += one[l];
    }

    cout << (ans == __INT_MAX__ ? -1 : ans) << endl;
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
