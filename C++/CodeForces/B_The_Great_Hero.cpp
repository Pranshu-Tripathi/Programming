#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    ll A,B,n;
    cin >> A >> B >> n;
    ll a[n];
    ll b[n];
    ll ans[n];
    for(int i = 0 ; i <n ;i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
        cin >> b[i];
    ll sum = 0;
    for(int i = 0 ; i < n ;i++)
        sum += ceil((double)b[i]/A) * a[i];
    for(int i = 0 ; i < n ; i++)
        ans[i] = B - sum + ceil((double)b[i]/A) * a[i]; 
    bool foundLastFighter = false;
    for(int i = 0 ; i < n ; i++)
        if(ans[i] > 0)
        {
            foundLastFighter = true;
            break;
        }
    
    if(!foundLastFighter)
    {
        cn;
        return;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(ans[i] > 0)
        {
            ll strike_H = ceil((double)b[i]/A);
            ll strike_M = ceil((double)ans[i]/a[i]);
            if(strike_H <= strike_M)
            {
                cy;
                return;
            }
        }
    }

    cn;

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
