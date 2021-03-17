#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll ans = 0;
vector<ll> vec(1000001, 0);

void pre_comp()
{
    for (int i = 1; i <= n; i++)
        vec[i] = vec[i - 1] ^ i;
}

void result()
{
    for (int i = 1; i < n; i++)
    {
        ll num = n - i;
        num = num / (i + 1);
        if (num % 2 != 0)
            ans ^= vec[i];
        if ((n-i) % (i + 1) != 0)
            ans ^= vec[(n-i) % (i + 1)-1];
    }
    for (int i = 1; i < n; i++)
    {
        ll num = n - i;
        if (num % 2 != 0)
            ans ^= i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr[i] = t;
        ans ^= t;
    }
    pre_comp();
    result();
    cout << ans;
}