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

void _run()
{
    ll n,l,r,ql,qr;
    cin >> n >> l >> r >> ql >> qr;
    ll w[n+1];
    for(int i = 1 ; i <= n ; i++)
        cin >> w[i];
    ll s[n+1];
    s[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        s[i] = s[i-1] + w[i];
    cout << endl;
    ll best = __INT_MAX__;
    ll right_cnt;
    ll uni;
    for(ll left_cnt = 0; left_cnt <= n ; left_cnt++)
    {
        right_cnt = n - left_cnt;
        uni = (s[left_cnt] * l);
        uni += (s[n]-s[left_cnt])*r;
        if(abs(left_cnt - right_cnt) > 1)
        {
            if(left_cnt >= right_cnt)
                uni += (left_cnt - right_cnt - 1)*ql;
            else if(left_cnt <  right_cnt)
                uni += (right_cnt - left_cnt -1) * qr;
        }
        best = min(best,uni);
    }
    cout << best << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
