#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int n,m,a,b;
    cin >> n >> m >> a >> b;

    if(a * m <= b)
    {
        // no use of taking special rides
        cout << a * n << endl;
    }
    else
    {
        if(n < m)
        {
            cout << min(b,a*n) << endl;
        }
        else
        {
            cout << min(ceil((double)n/(double)m) * b, (double)a * (n%m) + b * (n/m))  << endl;
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
