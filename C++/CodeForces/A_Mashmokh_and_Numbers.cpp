#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    ll rand = 100000007;
    ll n,k;
    cin >> n >> k;
    if(n == 1 && k == 0)
    {
        cout << 1 << endl;
        return;
    }
    if(n == 1 && k != 0)
    {
        cout << -1 << endl;
        return;
    }
    if(k < n/2)
    {
        cout << -1 << endl;
        return;
    }
    vector<bool> vis(100005,false);

    ll x = k - ((n-2)/2);
    vector<ll> ans;
    ans.push_back(x);
    ans.push_back(2*x);
    if(x < 100005)
        vis[x] = true;
    if(2 * x < 100005)
        vis[2*x] = true;
    // for(ll ele : ans)
    //     cout << ele << ' ';
    // cout << endl;
    ll co = 0;
    int i = 1;
    while(co != (n - 2)/2)
    {
        if(i < 100005)
        {
            if(!vis[i] && !vis[i+1])
            {
                ans.push_back(i),ans.push_back(i+1);
                co++;
            }
        }
        else
            ans.push_back(i),ans.push_back(i+1);
        
        i+=2;
    }
    if(n % 2 != 0)
        ans.push_back(rand);
    
    for(ll ele : ans)
        cout << ele << ' ';
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
