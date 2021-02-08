#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    ll a[n+1];
    ll pre[n+1];
    ll count  = 0;
    a[0] = pre[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i], pre[i] = a[i] + pre[i-1];

    if(pre[n] % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }

    ll sum = pre[n]/3;
    ll ss = 0;
    int cnt[n+1] ;
    memset(cnt,0,sizeof(cnt));
    for(int i = n ; i > 0 ; i--)
    {
        ss+=a[i];
        if(ss == sum)
            cnt[i] = 1;
    }

    for(int i = n -1 ; i > 0 ; --i)
    {
        cnt[i] += cnt[i+1];
    }

    for(int i = 1 ; i + 2 <= n ; i++)
    {
        if(pre[i] == sum)
            count+= cnt[i+2];
    }
    cout << count << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
