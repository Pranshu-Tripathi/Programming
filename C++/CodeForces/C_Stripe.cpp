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
    int n;
    cin >> n;
    int a[n];
    ll pre[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    pre[0] = a[0];
    for(int i = 1 ; i < n ; i++)
        pre[i] = pre[i-1] + a[i];
    int pos = 0;
    for(int i = 1 ; i <= n - 1 ; i++)
    {
        if(pre[i-1] * 2 == pre[n-1])
            pos++;
    }
    cout << pos << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
