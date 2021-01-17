#include<bits/stdc++.h>
using namespace std;
#define dbl double
#define ll long long

void _run()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    dbl num = a * d;
    dbl den = (b*c) + (a*d) - (a*c);
    dbl ans = num / den;
    cout << ans << endl;
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
