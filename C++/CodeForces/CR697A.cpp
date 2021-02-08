#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

vector<ll> pows(64);

bool power2(ll n)
{
    while(n % 2 == 0)
    {
        n /= 2; 
    }
    if(n > 1)
        return false;
    else
        return true;;
}

void _run()
{
    ll n;
    cin >> n;
    if(power2(n))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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
