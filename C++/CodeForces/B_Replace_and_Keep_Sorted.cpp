#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    ll n, q, k, l, r;
        cin >> n >> q >> k;
        vector<ll> arr(n);
        for (auto &x : arr)
            cin >> x;
        ll dp[n];
        if (n == 1)
        {
            dp[0] = k - 1;
        }
        else
        {
            dp[0] = arr[1] - 2;
            dp[n - 1] = k - arr[n - 2] - 1;
            for (int i = 1; i < n - 1; i++)
            {
                dp[i] = arr[i + 1] - arr[i - 1] - 2;
            }
        }
        ll presum[n];
        presum[0] = dp[0];

        for (int i = 1; i < n; i++)
            presum[i] = presum[i - 1] + dp[i];
        while (q--)
        {
            cin >> l >> r;
            l--, r--;
            if (l == r)
                printf("%lld\n", k - 1);
            else
            {
                ll sum = presum[r - 1] - presum[l];
                sum = sum + (arr[l + 1] - 2);
                sum = sum + (k - arr[r - 1] - 1);
                printf("%lld\n", sum);
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
