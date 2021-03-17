#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    int n;
    cin >> n;
    vector<pair<ll,int>> p(n);
    vector<int> ans;
    for(int i = 0 ; i < n; i++)
    {
        cin >> p[i].first;
        p[i].second = i+1;
    }
    sort(p.begin(),p.end());
    vector<ll> pre(n);
    pre[0] = p[0].first;
    for(int i = 1 ; i < n ; i++)
    {
        pre[i] = pre[i-1] + p[i].first;
    }

    ans.push_back(p[n-1].second);

    for(int i = n - 2 ;i  >= 0 ; i--)
    {
        if(pre[i] >= p[i+1].first)
            ans.push_back(p[i].second);
        else
            break;
    }
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(int i : ans)
        cout << i << ' ';
    cout << endl;
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
