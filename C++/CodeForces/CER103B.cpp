#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,k;
    cin >> n >> k;
    ll p[n];
    ll pre[n];
    for(int i = 0 ; i < n ; i ++)
        cin >> p[i];
    
    pre[0] = p[0];
    for(int i = 1 ; i <  n ; i ++)
        pre[i] = pre[i-1] + p[i];
    
    ll ans = 0;
    for(int i = 1 ; i < n ;i ++)
    {
        if(p[i] * 100 > k*(pre[i-1] + ans))
        {
            ans += ((p[i]*100)/k) - (pre[i-1]+ans);
            if((p[i]* 100) % k != 0)
                ans+=1;
        }
    }
    cout << ans << endl;
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
