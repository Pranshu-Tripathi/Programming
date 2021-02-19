#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int k;
    cin >> k;
    ll l;
    cin >> l;
    if(l < k)
    {
        cn;
        return;
    }
    int cnt = 0;
    while(l)
    {
        if(l%k != 0)
            break;
        l/=k;
        cnt++;
    }
    if(l == 1)
    {
        cy;
        cout << cnt -1 << endl;
    }
    else
        cn;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
