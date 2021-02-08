#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];

    ll ans = 0;

    vector<ll> c(n+1,0);
    c[1] = 1;
    for(int i = 2 ; i <= n ; i ++)
    {
        c[i] += c[i-1] + i;
    }

    bool vis[n];
    memset(vis,false,sizeof(vis));

    for(int i = 0 ; i < n- 1 ; i++)
    {
        int cnt;
        if(a[i] == a[i+1])
        {
            cnt = 1;
            int j;
            for( j = i+1;  j < n ; j++)
            {
                if(a[j] == a[j-1])
                    cnt++,vis[j] = vis[j-1] = true;
                else
                    break;
            }
            ans += c[cnt];
            i += cnt-1;
        }
        else
            ans += 1,vis[i] = true;
        // cout << cnt << ' ';
    }

    // for(int i = 0 ; i < n ; i ++)
    //     cout << vis[i] << ' ';

    for(int i = 0 ; i < n ; i ++)
    {
        if(!vis[i])
            ans++;
    }

    

    cout << ans << endl;

}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
