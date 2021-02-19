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
    ll n;
    cin >> n;
    if(n <= 3)
    {
        if(n == 3)
            cout << 6;
        else if(n == 2)
            cout << 2;
        else
            cout << 1;
        return;
    }
    if(n % 2 != 0)
    {
        cout << n * (n - 1) * (n-2) << endl;
        return;
    }
    if(n % 2 == 0)
    {
        if(n % n - 3 == 0)
        {
            cout << n * (n - 1) * (n - 4);
        }
        else
        {
            ll ans1 = ((n - 2) * (n - 1) * (n - 3)) / (__gcd(n - 2, n - 3)* __gcd(n - 1, ((n - 2) * (n - 3)) / __gcd(n - 2, n - 3)));
            ll ans2 = ((n) * (n - 1) * (n - 3)) / (__gcd(n, n - 3)* __gcd(n - 1, ((n) * (n - 3)) / __gcd(n, n - 3)));
            cout << max(ans1,ans2);
        }
    }
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
