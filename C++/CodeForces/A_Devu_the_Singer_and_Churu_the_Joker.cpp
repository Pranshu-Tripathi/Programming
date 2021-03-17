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
    int n,d;
    cin >> n >> d;
    int t[n];
    ll sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t[i];
        sum += t[i];
    }
    sum += (n-1) * 10;

    if(sum > d)
    {
        cout << -1;
        return;
    }

    ll ans = (n-1) * 2;
    ans += (d - sum)/5;
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
