#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

void _run()
{
    int n,m;
    cin >> n >> m;
    int minmoves = n/2 + n%2;
    int maxmoves = n;
    for(int x = minmoves ; x<= maxmoves ; x++)
    {
        if(x % m == 0)
        {
            cout << x;
            return;
        }
    }
    cout << -1  << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
