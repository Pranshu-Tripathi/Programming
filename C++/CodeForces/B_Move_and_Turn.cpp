/*
PR7
*/
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
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;


void _run()
{    
    int n;
    cin >> n;
    if(n%2 == 0)
    {
        ll ans = (n/2 + 1);
        ans *= ans;
        cout << ans << endl;
    }
    else
    {
        ll ans = 2*(n/2+1)*(n/2+2);
        cout << ans << endl;
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
