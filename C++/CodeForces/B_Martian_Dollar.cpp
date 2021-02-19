#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int n,b;
    cin >> n >> b;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    int ans[n];
    for(int i = 0 ;i < n ; i++)
    {
        int best = b;
        int dol = b/a[i];
        int remain = b%a[i];
        for(int j = i + 1 ; j < n ; j++)
        {
            best = max(best, (dol * a[j])+ remain);
            // cout << best << endl;
        }
        ans[i] = best;
    }

    int best = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(best < ans[i])
            best = ans[i];
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
