#include<bits/stdc++.h>
using namespace std;

#define ll long long

void _run()
{
    int n,k;
    cin >> n >> k;
    int a[n+1];
    for(int i = 1; i <= n ; i++)
        cin >> a[i];

    if(k == 1)
    {
        cout << 1 << endl;
        return;
    }

    int ans[k+1];
    for(int i = 1 ; i <= k ; i++)
    {
        int x = 0;
        ll sum = 0;
        while(i + x <= n)
        {
            sum += a[i+x];
            // cout << sum << ' ' << i + x<< endl;
            x += k;
        }
        ans[i] = sum;
        // cout << "loop" << endl;
    }

    // for(int i = 1 ; i <= k ; i++)
    //     cout << ans[i] << ' ';
    // cout << endl;
    int mi = __INT_MAX__;
    int index = -1;
    for(int i = 1 ; i <= k ; i++)
    {
        if(mi > ans[i])
        {
            mi = ans[i];
            index =i;
        }
    }
    cout << index << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}