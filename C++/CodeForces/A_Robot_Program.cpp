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
    int x,y;
    cin >> x >> y;
    if(x == y)
    {
        cout << x + y << endl;
        return;
    }

    if(x > y)
        swap(x,y);
    int steps = 2 * x + 1;
    int _y = y - (x+1);
    steps += _y * 2;
    cout << steps << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
