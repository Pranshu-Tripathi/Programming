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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int e = a + b;
    int f = a+c;
    int g = d + c;
    int mx = max(e,max(f,g));
    int mi = min(e,min(f,g));
    int bet = e+f+g - mx - mi;
    cout << bet << endl;
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
