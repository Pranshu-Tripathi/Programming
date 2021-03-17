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
    int n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> ans(n);
    for(int i = 0 ; i < n ; i++)
        cin >> p[i];
    sort(p.begin(),p.end());
    ans[0] = 1;
    for(int i = 1 ; i < n ; i++)
        ans[i] = p[i-1];
    if(ans[n-1] == 1 && p[n-1] < 2 && n != 1)
        ans[n-1]++;
    if(n == 1 && p[0] == 1)
        ans[n-1]++;
    for(int i = 0 ; i < n ; i++)
        cout << ans[i] << ' ';
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
