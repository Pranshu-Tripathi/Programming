#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll combinatrics(ll n)
{
    return (n * (n -1))/2;
}

void _run()
{
    ll n,m;
    cin >> n >> m;
    if(m == 1)
    {
        cout << combinatrics(n)  << " " << combinatrics(n) << endl;
        return;
    }

    ll mx = combinatrics(n - m + 1);
    ll mi = 0;
    mi += (m-(n % m)) *combinatrics(n/m);
    int x = n % m;
    mi += (n % m) * combinatrics(n/m + 1);

    cout << mi << " " << mx << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
