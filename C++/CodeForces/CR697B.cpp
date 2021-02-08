#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll n;
    cin >> n;
    if( n < 2020)
    {
        cout << "NO" << endl;
        return;
    }

    if (n % 2020 == 0 || n % 2021 == 0)
    {
        cout << "YES" << endl;
        return;
    }

    for(ll i = 0 ; i  * 2020 <= n ; i++)
    {
        ll a  = n - i * 2020;
        if(a % 2021 == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
