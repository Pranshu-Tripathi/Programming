#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int n,m;
    cin >> n >> m;
    int a[m+1];
    for(int i = 1 ; i <= m ; i++)
        cin >> a[i];
    a[0] = - 1;

    sort(a,a+m+1);

    // for(int i = 0 ; i <= m ; i++)
    // {
    //     cout << a[i] << ' '; 
    // }

    // cout << endl;

    int best = __INT_MAX__;
    for(int k = 1 ; k <= m-n +1; k++)
    {
        best = min(best, abs(a[k+n-1] - a[k]));

        //cout <<  abs(a[k+n-1] - a[k]) <<' ' <<  min(a[k+n-1],a[k]) << ' ' << max(a[k+n-1],a[k])<< endl;
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
