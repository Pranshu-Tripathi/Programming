#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

vector<ll> arr[100001];
vector<ll> lazy(100001, 0), orig(100001), target(100001);
vector<bool> vis(100001, false);
vector<ll> ans_arr;
ll ans = 0;

void _dfs(int idx)
{
    vis[idx] = true;
    if(lazy[idx] % 2 != 0)
        orig[idx] ^= 1;
    if(orig[idx] != target[idx])
        ans++, lazy[idx]++,ans_arr.push_back(idx);
    for(int child : arr[idx])
        if(!vis[child])
            for(int grandChild : arr[child])
                if(!vis[grandChild])
                    lazy[grandChild] += lazy[idx];
    for(int child : arr[idx])
        if(!vis[child])
            _dfs(child);
}

void _run()
{
    int n,u,v;
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i++)
        cin >> orig[i];
    for(int i = 1 ; i <= n ; i++)
        cin >> target[i];

    _dfs(1);

    cout << ans << endl;
    for(auto ele : ans_arr)
        cout << ele <<endl;
}


int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
